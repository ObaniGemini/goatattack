/*
 *  This file is part of Goat Attack.
 *
 *  Goat Attack is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  Goat Attack is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with Goat Attack.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "Cargo.hpp"
#include "Directory.hpp"
#include "CRC32.hpp"
#include "FileReader.hpp"

#include <cerrno>
#include <algorithm>
#include <sys/stat.h>
#include <zlib.h>

#include <iostream>

static const int ChunkSize = 1024;

static void throw_deflate_failed(z_stream *z) throw (CargoException) {
    if (z) {
        deflateEnd(z);
    }

    throw CargoException("Deflate failed.");
}

static void file_status(const char *entry, bool& is_directory, size_t& file_size) throw (CargoException) {
    struct stat sinfo;
    if (stat(entry, &sinfo)) {
        throw CargoException("Retrieving file information failed: " + std::string(strerror(errno)));
    }

    is_directory = (S_ISDIR(sinfo.st_mode) != 0);
    file_size = (is_directory ? 0 : sinfo.st_size);
}

Cargo::Cargo(const char *directory, const char *pak_file) throw (CargoException)
    : f(0), valid(true), finished(false), directory(directory), pak_file(pak_file)
{
    f = fopen(pak_file, "wb");
    if (!f) {
        throw CargoException("Cannot open file: " + std::string(strerror(errno)));
    }
}

Cargo::~Cargo() {
    fclose(f);
}

void Cargo::pack() throw (CargoException) {
    /* finished? */
    if (finished) {
        throw CargoException("Pack already created.");
    }

    /* object invalid? */
    if (!valid) {
        throw CargoException("Object is invalid.");
    }

    /* go */
    pack_directory("");

    /* append central directory */
    add_central_directory();

    /* flush file */
    if (fflush(f)) {
        throw_write_error();
    }

    /* done */
    finished = true;
}

void Cargo::pack_directory(const char *subdir) throw (CargoException) {
    try {
        /* read entries in directory */
        DirectoryEntries entries;
        std::string root = directory + "/" + subdir;
        Directory dir(root, "", 0);
        const char *entry = 0;
        size_t file_size = 0;
        bool is_dir = false;
        while ((entry = dir.get_entry())) {
            if (strcmp(entry, ".") && strcmp(entry, "..") && strcmp(entry, pak_file.c_str())) {
                std::string new_entry = append_dir(subdir, entry);
                file_status(append_dir(directory.c_str(), new_entry.c_str()).c_str(), is_dir, file_size);
                entries.push_back(DirectoryEntry(is_dir, new_entry.c_str(), file_size));
            }
        }
        std::sort(entries.begin(), entries.end());

        /* recursively pack files */
        for (DirectoryEntries::iterator it = entries.begin(); it != entries.end(); it++) {
            const DirectoryEntry& entry = *it;
            if (entry.is_directory) {
                pack_directory(append_dir(subdir, entry.entry.c_str()).c_str());
            } else {
                pack_file(entry);
            }
        }

    } catch (const Exception& e) {
        valid = false;
        throw CargoException(e.what());
    }
}

void Cargo::pack_file(const DirectoryEntry& entry) throw (CargoException) {
    std::string name = entry.entry;
    if (entry.is_directory) {
        name += "/";
    }

    std::cout << name.c_str() << std::endl;
    //return;

    /* create entry with placeholders */
    uint16_t file_time = 0;
    uint16_t file_date = 0;
    uint32_t sz_compressed = 0;
    uint32_t sz_uncompressed = entry.file_size;
    uint16_t method = (entry.is_directory || entry.file_size == 0 ? 0 : 8);

    long int rel_pos = ftell(f);
    write_string("PK\03\04", 4);        // file entry
    write_uint16(0x14);                 // version needed
    write_uint16(0);                    // general purpose flags
    write_uint16(method);               // compression method
    write_uint16(file_time);            // file time
    write_uint16(file_date);            // file date

    long int crc32_pos = ftell(f);
    write_uint32(0);                    // crc32 placeholder

    long int compr_sz_pos = ftell(f);
    write_uint32(0);                    // compressed size placeholder

    write_uint32(sz_uncompressed);      // uncompressed size
    write_uint16(name.length());        // file name length
    write_uint16(0);                    // extra field length
    write_string(name.c_str(), name.length()); // file name

    /* pack and write */
    uint32_t crc32 = 0;
    try {
        CRC32 crc;
        std::string filename(directory);
        filename += "/";
        filename += entry.entry;
        FileReader fr(filename.c_str());
        z_stream z;
        memset(&z, 0, sizeof(z_stream));
        int status = deflateInit(&z, Z_DEFAULT_COMPRESSION);
        if (status != Z_OK) {
            throw_deflate_failed(&z);
        }
        unsigned char in[ChunkSize];
        unsigned char out[ChunkSize];
        int flush = 0;
        do {
            z.avail_in = fr.read(in, sizeof(in));
            z.next_in = in;
            flush = (fr.eof() ? Z_FINISH : Z_NO_FLUSH);
            do {
                z.avail_out = sizeof(out);
                z.next_out = out;
                if (deflate(&z, flush) == Z_STREAM_ERROR) {
                    throw_deflate_failed(&z);
                }
                size_t have = sizeof(out) - z.avail_out;
                sz_compressed += have;
                crc.process(out, have);
                try {
                    write_string(out, have);
                } catch (const Exception& e) {
                    throw_deflate_failed(&z);
                }
            } while (z.avail_out == 0);
        } while (flush != Z_FINISH);
        deflateEnd(&z);
        crc32 = crc.get_crc();
    } catch (const Exception& e) {
        valid = false;
        throw CargoException(e.what());
    }

    /* fill placeholders */
    long int current_pos = ftell(f);
    fseek(f, crc32_pos, SEEK_SET);
    write_uint32(crc32);
    fseek(f, compr_sz_pos, SEEK_SET);
    write_uint32(sz_compressed);
    fseek(f, current_pos, SEEK_SET);

    /* add cd entry */
    pak_entries.push_back(PakEntry(name.c_str(), sz_compressed, sz_uncompressed,
        rel_pos, crc32, file_time, file_date, method));
}

void Cargo::throw_write_error() throw (CargoException) {
    valid = false;
    throw CargoException("Writing to file failed: " + std::string(strerror(errno)));
}

std::string Cargo::append_dir(const char *directory, const char *subdir) {
    std::string new_dir(directory);
    if (new_dir.length()) {
        new_dir += "/";
    }
    new_dir += subdir;

    return new_dir;
}

void Cargo::add_central_directory() throw (CargoException) {
    long int cd_offset = ftell(f);
    size_t cd_sz = 0;

    /* central directory */
    for (PakEntries::iterator it = pak_entries.begin(); it != pak_entries.end(); it++) {
        const PakEntry& entry = *it;

        cd_sz += write_string("PK\01\02", 4);            // entry magic
        cd_sz += write_uint16(0x0317);                   // version
        cd_sz += write_uint16(0x14);                     // version needed
        cd_sz += write_uint16(0);                        // general purpose flags
        cd_sz += write_uint16(entry.method);             // compression method
        cd_sz += write_uint16(entry.file_time);          // file time
        cd_sz += write_uint16(entry.file_date);          // file date
        cd_sz += write_uint32(entry.crc32);              // crc32
        cd_sz += write_uint32(entry.sz_compressed);      // compressed size
        cd_sz += write_uint32(entry.sz_uncompressed);    // uncompressed size
        cd_sz += write_uint16(entry.name.length());      // file name length
        cd_sz += write_uint16(0);                        // extra field length
        cd_sz += write_uint16(0);                        // comment length
        cd_sz += write_uint16(0);                        // on disk nbr
        cd_sz += write_uint16(1);                        // internal file attributes
        cd_sz += write_uint32(0x81a40000);               // external file attributes
        cd_sz += write_uint32(entry.relative_position);  // position
        cd_sz += write_string(entry.name.c_str(), entry.name.length()); // file name
    }

    /* eocd */
    write_string("PK\05\06", 4);        // central directory
    write_uint16(0);                    // nbr of this disk
    write_uint16(0);                    // start disk
    write_uint16(pak_entries.size());   // dir records on disk
    write_uint16(pak_entries.size());   // dir records total
    write_uint32(cd_sz);                // sz of central directory
    write_uint32(cd_offset);            // offset of cd
    write_uint16(0);                    // comment length
}

size_t Cargo::write_string(const void *s, size_t len) throw (CargoException) {
    size_t written = fwrite(s, 1, len, f);
    if (written != len) {
        throw_write_error();
    }

    return written;
}

size_t Cargo::write_uint16(uint16_t n) throw (CargoException) {
    unsigned char data[2];
    data[0] = (n & 0x00ff);
    data[1] = (n >> 8);
    size_t written = fwrite(data, 1, sizeof(data), f);
    if (written != sizeof(data)) {
        throw_write_error();
    }

    return written;
}

size_t Cargo::write_uint32(uint32_t n) throw (CargoException) {
    unsigned char data[4];
    data[0] = ((n      ) & 0xff);
    data[1] = ((n >>  8) & 0xff);
    data[2] = ((n >> 16) & 0xff);
    data[3] = ((n >> 24) & 0xff);
    size_t written = fwrite(data, 1, sizeof(data), f);
    if (written != sizeof(data)) {
        throw_write_error();
    }

    return written;
}