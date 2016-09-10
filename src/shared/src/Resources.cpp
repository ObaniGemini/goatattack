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

#include "Resources.hpp"
#include "Utils.hpp"
#include "Globals.hpp"
#include "AutoPtr.hpp"

#include <cstdlib>
#include <ctime>
#include <algorithm>

const char *Resources::NonDownloadableMainPaks[] = {
    "base.pak",
    0
};

/* static helpers */
template<class T> static bool erase_resource_object_home_only(Resources::ResourceObject& elem) {
    if (!elem.base_resource) {
        delete static_cast<T *>(elem.object);
        return true;
    }

    return false;
}

template<class T> static bool erase_resource_object_all(Resources::ResourceObject& elem) {
    delete static_cast<T *>(elem.object);
    return true;
}

template<class T> static void erase_resource_objects(Resources::ResourceObjects& elems, bool home_paks_only) {
    if (home_paks_only) {
        elems.erase(std::remove_if(elems.begin(), elems.end(), erase_resource_object_home_only<T>), elems.end());
    } else {
        elems.erase(std::remove_if(elems.begin(), elems.end(), erase_resource_object_all<T>), elems.end());
    }
}

static bool is_not_a_main_pak(const std::string& pakname) {
    const char **pak = Resources::NonDownloadableMainPaks;
    std::string pakfile = pakname + ".pak";
    while (*pak) {
        if (!strcmp(*pak, pakfile.c_str())) {
            return false;
        }
        pak++;
    }

    return true;
}

static bool erase_loaded_pak_home_only(Resources::LoadedPak& pak) {
    return pak.from_home_dir;
}

static void erase_loaded_pak(Resources::LoadedPaks& paks, bool home_paks_only) {
    if (home_paks_only) {
        paks.erase(std::remove_if(paks.begin(), paks.end(), erase_loaded_pak_home_only), paks.end());
    } else {
        paks.clear();
    }
}

template<class T> static T *find_object(Resources::ResourceObjects& objects, const std::string& name) {
    for (Resources::ResourceObjects::iterator it = objects.begin(); it != objects.end(); it++) {
        Resources::ResourceObject& ro = *it;
        T *obj = static_cast<T *>(ro.object);
        if (obj->get_name() == name) {
            return obj;
        }
    }
    return 0;
}

template<class T> static bool check_duplicate(Subsystem& subsystem, Resources::ResourceObjects& objects, const std::string& objectgroup, const std::string& name) {
    if (find_object<T>(objects, name)) {
        subsystem << "WARNING: object '" << name << "' in '" << objectgroup << "' already found, skipping." << std::endl;
        return true;
    }
    return false;
}

/* class implementation begins here */
Resources::Resources(Subsystem& subsystem, const std::string& resource_directory, bool skip_maps) throw (ResourcesException, ResourcesMissingException)
    : subsystem(subsystem), resource_directory(resource_directory), skip_maps(skip_maps)
{
    subsystem << "initializing resources" << std::endl;
    srand(static_cast<unsigned int>(time(0)));

    create_directory(UserDirectory, get_home_directory());

    load_resources(false);
}

Resources::~Resources() {
    subsystem << "cleaning resources" << std::endl;
    destroy_resources(false);
}

void Resources::reload_resources() throw (ResourcesException) {
    destroy_resources(true);
    load_resources(true);
}
void Resources::update_tile_index(double diff, Tileset *tileset) {
    if (!tileset) {
        for (ResourceObjects::iterator it = tilesets.begin(); it != tilesets.end(); it++) {
            ResourceObject& ro = *it;
            tileset = static_cast<Tileset *>(ro.object);
            size_t sz = tileset->get_tile_count();
            for (size_t i = 0; i < sz; i++) {
                tileset->get_tile(i)->update_tile_index(diff);
            }
        }
    } else {
        size_t sz = tileset->get_tile_count();
        for (size_t i = 0; i < sz; i++) {
            tileset->get_tile(i)->update_tile_index(diff);
        }
    }

    for (ResourceObjects::iterator it = objects.begin(); it != objects.end(); it++) {
        ResourceObject& ro = *it;
        Object *object = static_cast<Object *>(ro.object);
        object->get_tile()->update_tile_index(diff);
    }
}

const std::string& Resources::get_resource_directory() const {
    return resource_directory;
}

Tileset *Resources::get_tileset(const std::string& name) throw (ResourcesException) {
    Tileset *o = find_object<Tileset>(tilesets, name);
    if (o) return o;
    throw ResourcesException("tileset " + name + " not found");
}

Object *Resources::get_object(const std::string& name) throw (ResourcesException) {
    Object *o = find_object<Object>(objects, name);
    if (o) return o;
    throw ResourcesException("object " + name + " not found");
}

Characterset *Resources::get_characterset(const std::string& name) throw (ResourcesException) {
    Characterset *o = find_object<Characterset>(charactersets, name);
    if (o) return o;
    throw ResourcesException("characterset " + name + " not found");
}

NPC *Resources::get_npc(const std::string& name) throw (ResourcesException) {
    NPC *o = find_object<NPC>(npcs, name);
    if (o) return o;
    throw ResourcesException("npc " + name + " not found");
}

Animation *Resources::get_animation(const std::string& name) throw (ResourcesException) {
    Animation *o = find_object<Animation>(animations, name);
    if (o) return o;
    throw ResourcesException("animation " + name + " not found");
}

Map *Resources::get_map(const std::string& name) throw (ResourcesException) {
    Map *o = find_object<Map>(maps, name);
    if (o) return o;
    throw ResourcesException("map " + name + " not found");
}

Background *Resources::get_background(const std::string& name) throw (ResourcesException) {
    Background *o = find_object<Background>(backgrounds, name);
    if (o) return o;
    throw ResourcesException("background " + name + " not found");
}

Font *Resources::get_font(const std::string& name) throw (ResourcesException) {
    Font *o = find_object<Font>(fonts, name);
    if (o) return o;
    throw ResourcesException("font " + name + " not found");
}

Icon *Resources::get_icon(const std::string& name) throw (ResourcesException) {
    Icon *o = find_object<Icon>(icons, name);
    if (o) return o;
    throw ResourcesException("icon " + name + " not found");
}

Sound *Resources::get_sound(const std::string& name) throw (ResourcesException) {
    Sound *o = find_object<Sound>(sounds, name);
    if (o) return o;
    throw ResourcesException("sound " + name + " not found");
}

Music *Resources::get_music(const std::string& name) throw (ResourcesException) {
    Music *o = find_object<Music>(musics, name);
    if (o) return o;
    throw ResourcesException("music " + name + " not found");
}

Properties *Resources::get_game_settings(const std::string& name) throw (ResourcesException) {
    Properties *o = find_object<Properties>(game_settings, name);
    if (o) return o;
    throw ResourcesException("game settings " + name + " not found");
}

const Resources::LoadedPaks& Resources::get_loaded_paks() const {
    return loaded_paks;
}

Resources::ResourceObjects& Resources::get_tilesets() {
    return tilesets;
}

Resources::ResourceObjects& Resources::get_objects() {
    return objects;
}

Resources::ResourceObjects& Resources::get_charactersets() {
    return charactersets;
}

Resources::ResourceObjects& Resources::get_npcs() {
    return npcs;
}

Resources::ResourceObjects& Resources::get_animations() {
    return animations;
}

Resources::ResourceObjects& Resources::get_maps() {
    return maps;
}

Resources::ResourceObjects& Resources::get_backgrounds() {
    return backgrounds;
}

Resources::ResourceObjects& Resources::get_fonts() {
    return fonts;
}

Resources::ResourceObjects& Resources::get_icons() {
    return icons;
}

Resources::ResourceObjects& Resources::get_sounds() {
    return sounds;
}

Resources::ResourceObjects& Resources::get_musics() {
    return musics;
}

Resources::ResourceObjects& Resources::get_game_settings() {
    return game_settings;
}

void Resources::read_tilesets(const std::string& directory, ZipReader *zip, bool base_resource) throw (Exception) {
    const char *entry = 0;
    try {
        Directory dir(directory, ".tileset", zip);
        while ((entry = dir.get_entry())) {
            try {
                AutoPtr<Tileset> new_object(new Tileset(subsystem, (zip ? "" : directory + dir_separator) + entry, zip));
                if (!check_duplicate<Tileset>(subsystem, tilesets, "tilesets", new_object->get_name())) {
                    tilesets.push_back(ResourceObject(new_object.release(), base_resource));
                }
            } catch (const Exception& e) {
                subsystem << e.what() << std::endl;
            }
        }
    } catch (const DirectoryException&) {
        /* chomp */
    }
}

void Resources::read_objects(const std::string& directory, ZipReader *zip, bool base_resource) throw (Exception) {
    const char *entry = 0;
    try {
        Directory dir(directory, ".object", zip);
        while ((entry = dir.get_entry())) {
            try {
                AutoPtr<Object> new_object(new Object(subsystem, (zip ? "" : directory + dir_separator) + entry, zip));
                if (!check_duplicate<Object>(subsystem, objects, "objects", new_object->get_name())) {
                    objects.push_back(ResourceObject(new_object.release(), base_resource));
                }
            } catch (const Exception& e) {
                subsystem << e.what() << std::endl;
            }
        }
    } catch (const DirectoryException&) {
        /* chomp */
    }
}

void Resources::read_charactersets(const std::string& directory, ZipReader *zip, bool base_resource) throw (Exception) {
    const char *entry = 0;
    try {
        Directory dir(directory, ".characterset", zip);
        while ((entry = dir.get_entry())) {
            try {
                AutoPtr<Characterset> new_object(new Characterset(subsystem, (zip ? "" : directory + dir_separator) + entry, zip));
                if (!check_duplicate<Characterset>(subsystem, charactersets, "charactersets", new_object->get_name())) {
                    charactersets.push_back(ResourceObject(new_object.release(), base_resource));
                }
            } catch (const Exception& e) {
                subsystem << e.what() << std::endl;
            }
        }
    } catch (const DirectoryException&) {
        /* chomp */
    }
}

void Resources::read_npcs(const std::string& directory, ZipReader *zip, bool base_resource) throw (Exception) {
    const char *entry = 0;
    try {
        Directory dir(directory, ".npc", zip);
        while ((entry = dir.get_entry())) {
            try {
                AutoPtr<NPC> new_object(new NPC(subsystem, (zip ? "" : directory + dir_separator) + entry, zip));
                if (!check_duplicate<NPC>(subsystem, npcs, "npcs", new_object->get_name())) {
                    npcs.push_back(ResourceObject(new_object.release(), base_resource));
                }
            } catch (const Exception& e) {
                subsystem << e.what() << std::endl;
            }
        }
    } catch (const DirectoryException&) {
        /* chomp */
    }
}

void Resources::read_animations(const std::string& directory, ZipReader *zip, bool base_resource) throw (Exception) {
    const char *entry = 0;
    try {
        Directory dir(directory, ".animation", zip);
        while ((entry = dir.get_entry())) {
            try {
                AutoPtr<Animation> new_object(new Animation(subsystem, (zip ? "" : directory + dir_separator) + entry, zip));
                if (!check_duplicate<Animation>(subsystem, animations, "animations", new_object->get_name())) {
                    animations.push_back(ResourceObject(new_object.release(), base_resource));
                }
            } catch (const Exception& e) {
                subsystem << e.what() << std::endl;
            }
        }
    } catch (const DirectoryException&) {
        /* chomp */
    }
}

void Resources::read_maps(const std::string& directory, ZipReader *zip, bool base_resource) throw (Exception) {
    if (!skip_maps) {
        const char *entry = 0;
        try {
            Directory dir(directory, ".map", zip);
            while ((entry = dir.get_entry())) {
                try {
                    AutoPtr<Map> new_object(new Map(subsystem, (zip ? "" : directory + dir_separator) + entry, zip));
                    if (!check_duplicate<Map>(subsystem, maps, "maps", new_object->get_name())) {
                        maps.push_back(ResourceObject(new_object.release(), base_resource));
                    }
                } catch (const Exception& e) {
                    subsystem << e.what() << std::endl;
                }
            }
        } catch (const DirectoryException&) {
            /* chomp */
        }
    }
}

void Resources::read_backgrounds(const std::string& directory, ZipReader *zip, bool base_resource) throw (Exception) {
    const char *entry = 0;
    try {
        Directory dir(directory, ".background", zip);
        while ((entry = dir.get_entry())) {
            try {
                AutoPtr<Background> new_object(new Background(subsystem, (zip ? "" : directory + dir_separator) + entry, zip));
                if (!check_duplicate<Background>(subsystem, backgrounds, "backgrounds", new_object->get_name())) {
                    backgrounds.push_back(ResourceObject(new_object.release(), base_resource));
                }
            } catch (const Exception& e) {
                subsystem << e.what() << std::endl;
            }
        }
    } catch (const DirectoryException&) {
        /* chomp */
    }
}

void Resources::read_fonts(const std::string& directory, ZipReader *zip, bool base_resource) throw (Exception) {
    const char *entry = 0;
    try {
        Directory dir(directory, ".font", zip);
        while ((entry = dir.get_entry())) {
            try {
                AutoPtr<Font> new_object(new Font(subsystem, (zip ? "" : directory + dir_separator) + entry, zip));
                if (!check_duplicate<Font>(subsystem, fonts, "fonts", new_object->get_name())) {
                    fonts.push_back(ResourceObject(new_object.release(), base_resource));
                }
            } catch (const Exception& e) {
                subsystem << e.what() << std::endl;
            }
        }
    } catch (const DirectoryException&) {
        /* chomp */
    }
}

void Resources::read_icons(const std::string& directory, ZipReader *zip, bool base_resource) throw (Exception) {
    const char *entry = 0;
    try {
        Directory dir(directory, ".icon", zip);
        while ((entry = dir.get_entry())) {
            try {
                AutoPtr<Icon> new_object(new Icon(subsystem, (zip ? "" : directory + dir_separator) + entry, zip));
                if (!check_duplicate<Icon>(subsystem, icons, "icons", new_object->get_name())) {
                    icons.push_back(ResourceObject(new_object.release(), base_resource));
                }
            } catch (const Exception& e) {
                subsystem << e.what() << std::endl;
            }
        }
    } catch (const DirectoryException&) {
        /* chomp */
    }
}

void Resources::read_sounds(const std::string& directory, ZipReader *zip, bool base_resource) throw (Exception) {
    const char *entry = 0;
    try {
        Directory dir(directory, ".sound", zip);
        while ((entry = dir.get_entry())) {
            try {
                AutoPtr<Sound> new_object(new Sound(subsystem, (zip ? "" : directory + dir_separator) + entry, zip));
                if (!check_duplicate<Sound>(subsystem, sounds, "sounds", new_object->get_name())) {
                    sounds.push_back(ResourceObject(new_object.release(), base_resource));
                }
            } catch (const Exception& e) {
                subsystem << e.what() << std::endl;
            }
        }
    } catch (const DirectoryException&) {
        /* chomp */
    }
}

void Resources::read_musics(const std::string& directory, ZipReader *zip, bool base_resource) throw (Exception) {
    const char *entry = 0;
    try {
        Directory dir(directory, ".music", zip);
        while ((entry = dir.get_entry())) {
            try {
                AutoPtr<Music> new_object(new Music(subsystem, (zip ? "" : directory + dir_separator) + entry, zip));
                if (!check_duplicate<Music>(subsystem, musics, "musics", new_object->get_name())) {
                    musics.push_back(ResourceObject(new_object.release(), base_resource));
                }
            } catch (const Exception& e) {
                subsystem << e.what() << std::endl;
            }
        }
    } catch (const DirectoryException&) {
        /* chomp */
    }
}

void Resources::read_game_settings(const std::string& directory, ZipReader *zip, bool base_resource) throw (Exception) {
    const char *entry = 0;
    try {
        Directory dir(directory, ".game", zip);
        while ((entry = dir.get_entry())) {
            try {
                AutoPtr<Properties> new_object(new Properties((zip ? "" : directory + dir_separator) + entry + ".game", zip));
                if (!check_duplicate<Properties>(subsystem, game_settings, "game_settings", new_object->get_name())) {
                    game_settings.push_back(ResourceObject(new_object.release(), base_resource));
                }
            } catch (const Exception& e) {
                subsystem << e.what() << std::endl;
            }
        }
    } catch (const DirectoryException&) {
        /* chomp */
    }
}

void Resources::load_resources(bool home_paks_only) throw (ResourcesException, ResourcesMissingException) {
    try {
        const char **pak = 0;

        if (!home_paks_only) {
            /* scan main directories */
            subsystem << "looking into: " << resource_directory << std::endl;

            /* read main paks */
            pak = Resources::NonDownloadableMainPaks;
            while (*pak) {
                subsystem << "scanning " << *pak << std::endl;
                try {
                    ZipReader zip(resource_directory + dir_separator + *pak);
                    read_all("", &zip, true);
                    loaded_paks.push_back(LoadedPak(zip.get_zip_filename(), zip.get_zip_short_filename(), zip.get_hash(), false));
                } catch (const ZipException& e) {
                    subsystem << e.what() << std::endl;
                }

                pak++;
            }

            /* read additional paks */
            Directory dir(resource_directory, ".pak");
            const char *entry = 0;
            while ((entry = dir.get_entry())) {
                if (is_not_a_main_pak(entry)) {
                    subsystem << "scanning " << entry << ".pak" << std::endl;
                    try {
                        ZipReader zip(resource_directory + dir_separator + entry + ".pak");
                        read_all("", &zip, true);
                        loaded_paks.push_back(LoadedPak(zip.get_zip_filename(), zip.get_zip_short_filename(), zip.get_hash(), false));
                    } catch (const ZipException& e) {
                        subsystem << e.what() << std::endl;
                    }
                }
            }

            /* read open directory */
            read_all(resource_directory + dir_separator, 0, true);
        }

        /* scan user directories */
        std::string hdir = get_home_directory() + dir_separator + UserDirectory;
        subsystem << "looking into: " << hdir << std::endl;

        /* read additional paks in home directory */
        Directory dir(hdir, ".pak");
        const char *entry = 0;
        while ((entry = dir.get_entry())) {
            subsystem << "scanning " << entry << ".pak" << std::endl;
            try {
                ZipReader zip(hdir + dir_separator + entry + ".pak");
                read_all("", &zip, false);
                loaded_paks.push_back(LoadedPak(zip.get_zip_filename(), zip.get_zip_short_filename(), zip.get_hash(), true));
            } catch (const ZipException& e) {
                subsystem << e.what() << std::endl;
            }
        }

        /* read open directory */
        read_all(get_home_directory() + dir_separator + UserDirectory + dir_separator, 0, false);

        /* check if main paks are there */
        pak = Resources::NonDownloadableMainPaks;
        while (*pak) {
            if (std::find(loaded_paks.begin(), loaded_paks.end(), *pak) == loaded_paks.end()) {
                throw ResourcesMissingException(std::string(*pak) + " is missing.");
            }
            pak++;
        }

        /* prepare all resources for quick accesses */
        subsystem.set_scanlines_icon(get_icon("scanlines"));
        prepare_resources();
    } catch (const ResourcesMissingException&) {
        destroy_resources(false);
        throw;
    } catch (const DirectoryException& e) {
        destroy_resources(false);
        throw ResourcesMissingException(e.what());
    } catch (const Exception& e) {
        destroy_resources(false);
        throw ResourcesException(e.what());
    }
}

void Resources::read_all(const std::string& fdir, ZipReader *fzip, bool base_resource) throw (Exception) {
    read_tilesets(fdir + "tilesets", fzip, base_resource);
    read_objects(fdir + "objects", fzip, base_resource);
    read_charactersets(fdir + "charactersets", fzip, base_resource);
    read_npcs(fdir + "npcs", fzip, base_resource);
    read_animations(fdir + "animations", fzip, base_resource);
    read_maps(fdir + "maps", fzip, base_resource);
    read_backgrounds(fdir + "backgrounds", fzip, base_resource);
    read_fonts(fdir + "fonts", fzip, base_resource);
    read_icons(fdir + "icons", fzip, base_resource);
    read_sounds(fdir + "sounds", fzip, base_resource);
    read_musics(fdir + "music", fzip, base_resource);
    read_game_settings(fdir + "game", fzip, base_resource);
}

void Resources::destroy_resources(bool home_paks_only) {
    erase_resource_objects<Properties>(game_settings, home_paks_only);
    erase_resource_objects<Music>(musics, home_paks_only);
    erase_resource_objects<Sound>(sounds, home_paks_only);
    erase_resource_objects<Icon>(icons, home_paks_only);
    erase_resource_objects<Font>(fonts, home_paks_only);
    erase_resource_objects<Background>(backgrounds, home_paks_only);
    erase_resource_objects<Map>(maps, home_paks_only);
    erase_resource_objects<Animation>(animations, home_paks_only);
    erase_resource_objects<NPC>(npcs, home_paks_only);
    erase_resource_objects<Characterset>(charactersets, home_paks_only);
    erase_resource_objects<Object>(objects, home_paks_only);
    erase_resource_objects<Tileset>(tilesets, home_paks_only);

    erase_loaded_pak(loaded_paks, home_paks_only);
}

void Resources::prepare_resources() throw (ResourcesException) {
    /* load animation sounds */
    for (ResourceObjects::iterator it = animations.begin(); it != animations.end(); it++) {
        ResourceObject& ro = *it;
        Animation *ani = static_cast<Animation *>(ro.object);
        const std::string& sound_name = ani->get_value("sound_name");
        if (sound_name.length()) {
            ani->set_sound(get_sound(sound_name));
        }
    }
}
