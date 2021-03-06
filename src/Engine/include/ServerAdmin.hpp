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

#ifndef _SERVERADMIN_HPP_
#define _SERVERADMIN_HPP_

#include "Exception.hpp"
#include "Resources.hpp"
#include "ClientServer.hpp"
#include "Properties.hpp"

class ServerAdminException : public Exception {
public:
    ServerAdminException(const char *msg) : Exception(msg) { }
    ServerAdminException(std::string msg) : Exception(msg) { }
};

class ServerAdmin {
private:
    ServerAdmin(const ServerAdmin&);
    ServerAdmin& operator=(const ServerAdmin&);

public:
    ServerAdmin(Resources& resources, ClientServer& client_server,
        Properties& properties);

    ServerAdmin(Resources& resources, ClientServer& client_server,
        Properties& properties, const std::string& admin_password);

    void execute(const Connection *c, Player *p, std::string cmd, std::string params);
    void set_admin_server_is_on_client(bool state);
    bool get_admin_server_is_on_client() const;

private:
    typedef void (ServerAdmin::*AdminFunction)(const Connection *c, Player *p, const std::string& params);

    struct ServerCommand {
        const char *command;
        AdminFunction function;
    };

    Resources& resources;
    ClientServer& server;
    Properties& properties;
    std::string admin_password;
    bool is_client;

    static ServerCommand server_commands[];

    void update_configuration(const Connection *c);
    void send_i18n_msg(const Connection *c, I18NText id, const char *addon = 0);
    void send_i18n_msg(const Connection *c, I18NText id, const std::string& p1, const std::string& p2);

    void sc_op(const Connection *c, Player *p, const std::string& params);
    void sc_deop(const Connection *c, Player *p, const std::string& params);
    void sc_list(const Connection *c, Player *p, const std::string& params);
    void sc_kick(const Connection *c, Player *p, const std::string& params);
    void sc_ban(const Connection *c, Player *p, const std::string& params);
    void sc_unban(const Connection *c, Player *p, const std::string& params);
    void sc_next(const Connection *c, Player *p, const std::string& params);
    void sc_map(const Connection *c, Player *p, const std::string& params);
    void sc_maps(const Connection *c, Player *p, const std::string& params);
    void sc_reload(const Connection *c, Player *p, const std::string& params);
    void sc_save(const Connection *c, Player *p, const std::string& params);
    void sc_get(const Connection *c, Player *p, const std::string& params);
    void sc_set(const Connection *c, Player *p, const std::string& params);
    void sc_reset(const Connection *c, Player *p, const std::string& params);
    void sc_vote(const Connection *c, Player *p, const std::string& params);
    void sc_stats(const Connection *c, Player *p, const std::string& params);

    bool check_if_authorized(const Connection *c, Player *p);
    bool check_if_params(const Connection *c, const std::string& params);
    bool check_if_no_params(const Connection *c, const std::string& params);
    bool check_if_is_server(const Connection *c);
};

#endif
