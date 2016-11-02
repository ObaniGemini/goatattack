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

#include "I18N.hpp"

const I18N::Text I18N::all_texts_french[] = {
    { I18N_BUTTON_YES, "Yes" },
    { I18N_BUTTON_NO, "No" },
    { I18N_BUTTON_OK, "Ok" },
    { I18N_BUTTON_CANCEL, "Cancel" },
    { I18N_BUTTON_CLOSE, "Close" },
    { I18N_BUTTON_START_SERVER, "Start Server" },
    { I18N_BUTTON_DELETE, "Delete" },

    { I18N_TILETYPE01, "non blocking" },
    { I18N_TILETYPE02, "blocking" },
    { I18N_TILETYPE03, "falling only blocking" },
    { I18N_TILETYPE04, "red base" },
    { I18N_TILETYPE05, "blue base" },
    { I18N_TILETYPE06, "killing" },
    { I18N_TILETYPE07, "jump, no descend" },
    { I18N_TILETYPE08, "speed race finish" },
    { I18N_TILETYPE09, "hill zone" },

    { I18N_WINTITLE_GAME, "Goat Attack" },
    { I18N_WINTITLE_EDITOR, "Goat Attack Map Editor" },

    { I18N_SUBSYSTEM, "working with ${1}" },
    { I18N_MODE_IS_NORMAL, "mode is normal game" },
    { I18N_MODE_IS_DEDICATED, "mode is dedicated server" },

    { I18N_MAINMENU_PLAY, "Play" },
    { I18N_MAINMENU_LAN, "Create Local LAN Server" },
    { I18N_MAINMENU_PACKAGES, "List Loaded Packages" },
    { I18N_MAINMENU_OPTIONS, "Options And Settings" },
    { I18N_MAINMENU_CREDITS, "Credits" },
    { I18N_MAINMENU_QUIT, "Quit Game" },
    { I18N_MAINMENU_VERSION, "Current Version: ${1}" },
    { I18N_MAINMENU_INTERNET, "Internet" },
    { I18N_MAINMENU_INTERNET_SERVERS, "Internet servers:" },
    { I18N_MAINMENU_SERVER_NAME, "Server Name" },
    { I18N_MAINMENU_CONNECT, "Connect" },
    { I18N_MAINMENU_REFRESH, "Refresh" },
    { I18N_MAINMENU_PLAYERS, "Players" },
    { I18N_MAINMENU_PING, "Ping" },
    { I18N_MAINMENU_LAN_TITLE, "LAN" },
    { I18N_MAINMENU_LAN_SERVERS, "LAN servers:" },
    { I18N_MAINMENU_CUSTOM_SERVER, "Custom Server" },
    { I18N_MAINMENU_ENTER_HOSTNAME, "Enter here the hostname or IP address and port:" },
    { I18N_MAINMENU_ADDRESS, "address:" },
    { I18N_MAINMENU_PORT, "port:" },
    { I18N_MAINMENU_PASSWORD, "password:" },
    { I18N_MAINMENU_ENTER_PASSWORD, "Enter password:" },
    { I18N_MAINMENU_SERVER_NAME2, "server name:" },
    { I18N_MAINMENU_GAME_MODE, "game mode:" },
    { I18N_MAINMENU_GM_DM, "death match" },
    { I18N_MAINMENU_GM_TDM, "team death match" },
    { I18N_MAINMENU_GM_CTF, "capture the flag" },
    { I18N_MAINMENU_GM_SR, "speed race" },
    { I18N_MAINMENU_GM_CTC, "catch the coin" },
    { I18N_MAINMENU_GM_GOH, "goat of the hill" },
    { I18N_MAINMENU_MAX_PLAYERS, "max. players:" },
    { I18N_MAINMENU_WARMUP, "warm-up:" },
    { I18N_MAINMENU_DURATION, "duration:" },
    { I18N_MAINMENU_IN_SECONDS, "(in seconds)" },
    { I18N_MAINMENU_IN_MINUTES, "(in minutes)" },
    { I18N_MAINMENU_SELECT_MAP, "select map:" },
    { I18N_MAINMENU_INVALID_SERVERNAME, "Please enter a valid server name." },
    { I18N_MAINMENU_MAX_PLAYERS_TITLE, "Max. Players" },
    { I18N_MAINMENU_INVALID_GENERIC_NUMBER, "Please enter a valid number. (${1})" },
    { I18N_MAINMENU_DURATION2, "Duration" },
    { I18N_MAINMENU_WARMUP2, "Warm-Up" },
    { I18N_MAINMENU_SELECT_MAP2, "Select Map" },
    { I18N_MAINMENU_SELECT_MAP3, "Please select a map." },
    { I18N_MAINMENU_PACKAGE, "Package" },
    { I18N_MAINMENU_HASH, "Hash" },
    { I18N_MAINMENU_CREDITS_CODE, "code:" },
    { I18N_MAINMENU_CREDITS_GFX, "graphics:" },
    { I18N_MAINMENU_CREDITS_MAPS, "maps:" },
    { I18N_MAINMENU_CREDITS_MUSIC, "music:" },
    { I18N_MAINMENU_CREDITS_THANKS, "special thanks to:" },
    { I18N_MAINMENU_FREDERIC, "and of course, frederic the goat" },

    { I18N_OPTIONS_PLAYER, "Player" },
    { I18N_OPTIONS_GRAPHICS_AND_SOUND, "Graphics And Sound" },
    { I18N_OPTIONS_CONTROLLER, "Controller And Keyboard" },
    { I18N_OPTIONS_SPECTATE, "Spectate" },
    { I18N_OPTIONS_SKIP_SONG, "Skip Song" },
    { I18N_OPTIONS_RETURN, "Return To Main Menu" },
    { I18N_OPTIONS_SETTINGS11, "player's name:" },
    { I18N_OPTIONS_SETTINGS12, "show player's name" },
    { I18N_OPTIONS_SETTINGS13, "character:" },
    { I18N_OPTIONS_SETTINGS21, "fullscreen graphics mode" },
    { I18N_OPTIONS_SETTINGS22, "draw scanlines" },
    { I18N_OPTIONS_SETTINGS23, "intensity:" },
    { I18N_OPTIONS_SETTINGS24, "music volume:" },
    { I18N_OPTIONS_SETTINGS25, "sfx volume:" },
    { I18N_OPTIONS_SETTINGS26, "text fade speed:" },
    { I18N_OPTIONS_SETTINGS31, "up:" },
    { I18N_OPTIONS_SETTINGS32, "down:" },
    { I18N_OPTIONS_SETTINGS33, "left:" },
    { I18N_OPTIONS_SETTINGS34, "right:" },
    { I18N_OPTIONS_SETTINGS35, "jump:" },
    { I18N_OPTIONS_SETTINGS36, "fire:" },
    { I18N_OPTIONS_SETTINGS37, "grenade:" },
    { I18N_OPTIONS_SETTINGS38, "bomb:" },
    { I18N_OPTIONS_SETTINGS39, "frog:" },
    { I18N_OPTIONS_SETTINGS40, "chat:" },
    { I18N_OPTIONS_SETTINGS41, "stats:" },
    { I18N_OPTIONS_SETTINGS42, "escape:" },
    { I18N_OPTIONS_SETTINGS43, "horz. gamepad deadzone:" },
    { I18N_OPTIONS_SETTINGS44, "vert. gamepad deadzone:" },
    { I18N_OPTIONS_SETTINGS45, "Rescan Joysticks" },
    { I18N_OPTIONS_SETTINGS46, "Capturing" },
    { I18N_OPTIONS_SETTINGS47, "Press key or use joystick..." },
    { I18N_OPTIONS_SETTINGS48, "${1} joystick(s) found." },
    { I18N_OPTIONS_SETTINGS49, "Joysticks" },
    { I18N_OPTIONS_SETTINGS50, "[none]" },
    { I18N_OPTIONS_SETTINGS51, "Button: ${1}" },

    { I18N_CLIENT_TRANSFER, "transferring ${1} (${2}%)" },
    { I18N_CLIENT_ENTER_MSG, "Enter Message" },
    { I18N_CLIENT_CONNECTING_TO1, "connecting to ${1}, ping = ${2}" },
    { I18N_CLIENT_CONNECTING_TO2, ", needs password" },
    { I18N_CLIENT_CONNECTING_TO3, "(clients: ${1}/${2})" },
    { I18N_CLIENT_LOGGED_IN, "you logged in" },
    { I18N_CLIENT_LOGGED_OUT, "You logged out." },
    { I18N_CLIENT_PING_TIMEOUT, "You logged out. (ping timeout)" },
    { I18N_CLIENT_TOO_MANY_RESENDS, "You logged out. (too many resends)" },
    { I18N_CLIENT_APPLICATION_LAYER, "You logged out. (application layer quit)" },
    { I18N_CLIENT_SERVER_MESSAGE, "Server Message" },
    { I18N_CLIENT_MAP_INFO, "map: ${1}" },
    { I18N_CLIENT_JOIN_REFUSED, "YOUR JOIN REQUEST WAS REFUSED" },
    { I18N_CLIENT_FRIENDLY_FIRE, "FRIENDLY FIRE: WATCH OUT!!!" },
    { I18N_CLIENT_UNBALANCED, "GAMEPLAY IS UNBALANCED" },
    { I18N_CLIENT_WARMUP, "please warm up" },
    { I18N_CLIENT_GAME_BEGINS, "game begins" },
    { I18N_CLIENT_GAME_OVER, "GAME IS OVER" },
    { I18N_CLIENT_RENAME, "${1} is now known as ${2}" },
    { I18N_CLIENT_SKIN_CHANGE, "${1} changed the skin to ${2}" },

    { I18N_TNMT_NEW_MAP_LOADED, "new map loaded" },
    { I18N_TNMT_SPECTATING, "SPECTATING" },
    { I18N_TNMT_WARMUP, "WARM UP" },
    { I18N_TNMT_SB_CTC_TITLE, "CATCH THE COIN" },
    { I18N_TNMT_SB_PLAYER, "PLAYER" },
    { I18N_TNMT_SB_TOTAL, "TOTAL" },
    { I18N_TNMT_SB_PING, "PING" },
    { I18N_TNMT_SB_SPECTATORS, "SPECTACTORS:" },
    { I18N_TNMT_SB_DM_TITLE, "DEATHMATCH" },
    { I18N_TNMT_SB_FRAGS, "FRAGS" },
    { I18N_TNMT_SB_KILLS, "KILLS" },
    { I18N_TNMT_SB_SCORE, "SCORE" },
    { I18N_TNMT_SB_SR_TITLE, "SPEED RACE" },
    { I18N_TNMT_SB_LAPS, "LAPS" },
    { I18N_TNMT_SB_BEST, "BEST" },
    { I18N_TNMT_SB_LAST, "LAST" },
    { I18N_TNMT_SR_LEAD, "lead:" },
    { I18N_TNMT_SR_LAP, "lap:" },
    { I18N_TNMT_SR_BEST, "best:" },
    { I18N_TNMT_SR_LAST, "last:" },
    { I18N_TNMT_SR_NA, "N/A" },
    { I18N_TNMT_PLAYER_JOINS, "${1} joins the game" },
    { I18N_TNMT_PLAYER_FELL_OFF, "${1} fell off the stage" },
    { I18N_TNMT_PLAYER_SUICIDE, "${1} committed suicide" },
    { I18N_TNMT_COIN_RETURNED, "the coin returned to its base" },
    { I18N_TNMT_COIN_CATCHED, "${1} catched the coin" },
    { I18N_TNMT_COIN_DROPPED, "the coin dropped" },
    { I18N_TNMT_RED_FLAG_RETURNED, "the red flag returned to its base" },
    { I18N_TNMT_BLUE_FLAG_RETURNED, "the blue flag returned to its base" },
    { I18N_TNMT_RED_FLAG_CATCHED, "${1} catched the red flag" },
    { I18N_TNMT_BLUE_FLAG_CATCHED, "${1} catched the blue flag" },
    { I18N_TNMT_RED_FLAG_SAVED, "the red flag returned by ${1}" },
    { I18N_TNMT_BLUE_FLAG_SAVED, "the blue flag returned by ${1}" },
    { I18N_TNMT_RED_FLAG_DROPPED, "the red flag dropped" },
    { I18N_TNMT_BLUE_FLAG_DROPPED, "the blue flag dropped" },
    { I18N_TNMT_TEAM_RED_SCORED1, "team red scores" },
    { I18N_TNMT_TEAM_BLUE_SCORED1, "team blue scores" },
    { I18N_TNMT_TEAM_RED_SCORED2, "TEAM RED SCORES" },
    { I18N_TNMT_TEAM_BLUE_SCORED2, "TEAM RED SCORES" },
    { I18N_TNMT_SR_RECORD, "new record of ${1}: ${2}" },
    { I18N_TNMT_SR_COMPLETE, "round completed" },
    { I18N_TNMT_KILLED1, "${1} killed ${2}" },
    { I18N_TNMT_KILLED2, "${1} killed himself" },
    { I18N_TNMT_FROGGED1, "${1} frogged ${2}" },
    { I18N_TNMT_FROGGED2, "${1} frogged himself" },

    { I18N_TNMT_STATS_TEAM, "team stat" },
    { I18N_TNMT_STATS_PLAYER, "player stat" },
    { I18N_TNMT_STATS_OVER, "game over" },
    { I18N_TNMT_STATS_END, "end of stats" },
    { I18N_TNMT_STATS_MAP_CLOSED, "current map closed" },

    { I18N_TNMT_SELECT_TEAM1, "Choose with up and down, select with fire." },
    { I18N_TNMT_SELECT_TEAM2, "Select Team" },
    { I18N_TNMT_JOIN_RED_TEAM, "${1} joins the red team" },
    { I18N_TNMT_JOIN_BLUE_TEAM, "${1} joins the blue team" },

    { I18N_TNMT_TEAM_RED_CAP, "TEAM RED" },
    { I18N_TNMT_TEAM_BLUE_CAP, "TEAM BLUE" },

    { I18N_SERVE_WARM_UP, "warm up" },
    { I18N_SERVE_GAME_BEGINS, "game begins" },
    { I18N_SERVE_CONNECT, "${1} connected" },
    { I18N_SERVE_RECONNECT, "${1} reconnected" },
    { I18N_SERVE_SPECTATING, "${1} is spectating now" },
    { I18N_SERVE_UNKNOWN_COMMAND, "Unknown server command: ${1}" },
    { I18N_SERVE_WRONG_PASSWORD, "Wrong admin password" },
    { I18N_SERVE_ALREADY_ADMIN, "You're already admin" },
    { I18N_SERVE_NEW_ADMIN, "${1} is now server admin" },
    { I18N_SERVE_ADMIN_LEFT, "${1} left the server admin mode" },
    { I18N_SERVE_KICK_YOURSELF, "You cannot kick yourself" },
    { I18N_SERVE_PLAYER_NOT_FOUND, "Player not found: ${1}" },
    { I18N_SERVE_NOT_AUTHORIZED, "You're not authorized to do that" },
    { I18N_SERVE_KICK, "${1} kicked ${2}" },
    { I18N_SERVE_NOT_IMPLEMENTED, "Not implemented yet" },
    { I18N_SERVE_NEXT_MAP, "${1} started next map" },
    { I18N_SERVE_MAP_USAGE, "Usage: /map <map_name> <warmup> <duration>" },
    { I18N_SERVE_MAP_LOADED, "${1} started map ${2}" },
    { I18N_SERVE_CONFIG_RELOADED, "configuration reloaded" },
    { I18N_SERVE_CONFIG_SAVED, "configuration saved" },
    { I18N_SERVE_GET_USAGE, "Usage: /get <variable>" },
    { I18N_SERVE_SET_USAGE, "Usage: /set <variable> <value>" },
    { I18N_SERVE_SET_VAR_TO, "set ${1} to ${2}" },
    { I18N_SERVE_RESET_USAGE, "Usage: /reset <variable>" },
    { I18N_SERVE_VAR_CLEARED, "${1} cleared" },
    { I18N_SERVE_PARM_MISSING, "Parameter missing" },
    { I18N_SERVE_NO_PARM_NEEDED, "No parameters needed" },
    { I18N_SERVE_ILLEGAL_PARM, "Illegal parameters" },

    { I18N_TNMT_LOGOUT_MSG01, "gone, gone... gone" },
    { I18N_TNMT_LOGOUT_MSG02, "ended in smoke" },
    { I18N_TNMT_LOGOUT_MSG03, "bye bye world" },
    { I18N_TNMT_LOGOUT_MSG04, "bitten the dust" },
    { I18N_TNMT_LOGOUT_MSG05, "went the way of all flesh" },
    { I18N_TNMT_LOGOUT_MSG06, "bitten the ground" },
    { I18N_TNMT_LOGOUT_MSG07, "cheerio..." },
    { I18N_TNMT_LOGOUT_MSG08, "au revoir!" },
    { I18N_TNMT_LOGOUT_MSG09, "goodbye, hoo roo." },
    { I18N_TNMT_LOGOUT_MSG10, "time to say goodbye" },
    { I18N_TNMT_LOGOUT_MSG11, "i took the blue pill" },
    { I18N_TNMT_LOGOUT_MSG12, "" },

    { I18N_VERSION_MISMATCH_TITLE, "Version Mismatch" },
    { I18N_VERSION_MISMATCH_MESSAGE, "Both protocols differ, you cannot connect to this server." },
    { I18N_SERVER_TITLE, "Server" },
    { I18N_SELECT_SERVER, "Please select a server first." },
    { I18N_ERROR_TITLE, "Error" },
    { I18N_PORT_TITLE, "Port" },
    { I18N_SERVER_UNKNOWN, "Server not found or unknown." },
    { I18N_INVALID_PORT, "Enter valid port number." },
    { I18N_WRONG_MAPTYPE, "Wrong Map Type" },
    { I18N_WRONG_MAPTYPE2, "This map can't be played in this mode." },
    { I18N_SERVER_FULL, "Login failed: server is full." },
    { I18N_WRONG_PASSWORD, "Login failed: wrong password." },
    { I18N_XFER_OPEN_FAILED, "WARNING: cannot open file: ${1}" },
    { I18N_XFER_ALREADY_OPEN, "WARNING: cannot receive ${1}. This file is already opened." },
    { I18N_THREAD_FAILED, "Starting thread failed." },
    { I18N_HEAP_CHANGE_ERROR, "Cannot set num_players to ${1}, ${2} are logged in." },
    { I18N_SERVER_TOO_OLD, "---[ server too old ]---" },
    { I18N_ANIMATION_FAILED, "creating animation failed: ${1}" },
    { I18N_MISSING_SPAWN_POINTS, "Missing spawn points in this map." },
    { I18N_MULTIPLE_COINS, "Multiple coins not allowed." },
    { I18N_COIN_MISSING, "Coin is missing in this map." },
    { I18N_MULTIPLE_RED_FLAGS, "Multiple red flags not allowed." },
    { I18N_MULTIPLE_BLUE_FLAGS, "Multiple blue flags not allowed." },
    { I18N_RED_FLAG_MISSING, "Red flag is missing in this map." },
    { I18N_BLUE_FLAG_MISSING, "Blue flag is missing in this map." },
    { I18N_WHY_MORE_SPAWN_POINTS, "Why more than one spawn point in this game mode?" },
    { I18N_RED_SPAWNPOINTS_MISSING, "Missing spawn points for team red in this map." },
    { I18N_BLUE_SPAWNPOINTS_MISSING, "Missing spawn points for team blue in this map." },
    { I18N_DIFFERENT_HASH, "Main pak '${1}' has a different hash." },
    { I18N_NO_MAPS_DEFINED, "No maps defined in server configuration file." },
    { I18N_NO_DEDICATED_SERVER, "This is not a dedicated server." },
    { I18N_MUSIC_INFO, "music: ${1}" },
    { I18N_MUSIC_TOO_FAST, "ERROR: ${1} played too fast, stopping." },
    { I18N_NO_MUSIC_FOUND, "ERROR: no valid music found." },
    { I18N_ENTER_VALID_VALUE, "Enter valid value (${1})" },
    { I18N_NO_PARENT, "no parent specified" },
    { I18N_NO_FONT, "no valid font declared" },

    { I18N_RES_OBJECT_FOUND_WARNING, "WARNING: object '${1}' in '${2}' already found, skipping." },
    { I18N_RES_INIT_RESOURCES, "initializing resources" },
    { I18N_RES_UNINIT_RESOURCES, "cleaning resources" },
    { I18N_RES_TILESET_NOT_FOUND, "tileset ${1} not found" },
    { I18N_RES_OBJECT_NOT_FOUND, "object ${1} not found" },
    { I18N_RES_CHARACTERSET_NOT_FOUND, "characterset ${1} not found" },
    { I18N_RES_NPC_NOT_FOUND, "npc ${1} not found" },
    { I18N_RES_ANIMATION_NOT_FOUND, "animation ${1} not found" },
    { I18N_RES_MAP_NOT_FOUND, "map ${1} not found" },
    { I18N_RES_BACKGROUND_NOT_FOUND, "background ${1} not found" },
    { I18N_RES_FONT_NOT_FOUND, "font ${1} not found" },
    { I18N_RES_ICON_NOT_FOUND, "icon ${1} not found" },
    { I18N_RES_SOUND_NOT_FOUND, "sound ${1} not found" },
    { I18N_RES_MUSIC_NOT_FOUND, "music ${1} not found" },
    { I18N_RES_GAME_SETTING_NOT_FOUND, "game settings ${1} not found" },
    { I18N_RES_SHADER_NOT_FOUND, "shader ${1} not found" },
    { I18N_RES_LOOKING_INTO, "looking into: ${1}" },
    { I18N_RES_SCANNING, "scanning ${1}" },
    { I18N_RES_PAK_MISSING, "${1} is missing" },

    { I18N_SSSDL_START, "starting SubsystemSDL" },
    { I18N_SSSDL_INIT, "initializing SubsystemSDL" },
    { I18N_SSSDL_SIZE_QUERY, "Could not query main desktop size: ${1}" },
    { I18N_SSSDL_WINDOW, "creating SDL window" },
    { I18N_SSSDL_WINDOW_FAILED, "Could not create window: ${1}" },
    { I18N_SSSDL_OPENGL, "creating OpenGL context" },
    { I18N_SSSDL_MIXER_FAILED, "Could not initialize mixer: ${1}" },
    { I18N_SSSDL_AUDIO_FAILED, "Could not open audio: ${1}" },
    { I18N_SSSDL_UNINIT, "cleaning SubsystemSDL" },
    { I18N_SSSDL_SHADING_PIPELINE, "using shading pipeline" },
    { I18N_SSSDL_FULLSCREEN, "toggling fullscreen" },
    { I18N_SSSDL_OPENGL_INIT, "initializing OpenGL" },

    { I18N_SSNULL_START, "starting SubsystemNull" },
    { I18N_SSNULL_UNINIT, "cleaning SubsystemNull" },

    { I18N_ME_RADIUS, "Radius" },
    { I18N_ME_RED, "Red" },
    { I18N_ME_GREEN, "Green" },
    { I18N_ME_BLUE, "Blue" },
    { I18N_ME_NAME, "Name" },
    { I18N_ME_FROG_SPAWN, "Frog Spawn" },
    { I18N_ME_AUTHOR, "Author" },
    { I18N_ME_DESCRIPTION, "Description" },
    { I18N_ME_WIDTH, "Width" },
    { I18N_ME_WIDTH_EVEN, "The width of the map must be even." },
    { I18N_ME_HEIGHT, "Height" },
    { I18N_ME_PARALLAX_SHIFT, "Parallax Shift" },
    { I18N_ME_TILESET, "Tileset" },
    { I18N_ME_TILESET_SELECT, "Select a tileset." },
    { I18N_ME_BACKGROUND, "Background" },
    { I18N_ME_BACKGROUND_SELECT, "Select a background." },
    { I18N_ME_UNSAVED_MAP, "Unsaved Map" },
    { I18N_ME_REALLY_CONTINUE, "There are unsaved changes. Really continue?" },
    { I18N_ME_TOOL, "Tool" },
    { I18N_ME_MODE_SELECTOR, "mode selector" },
    { I18N_ME_CENTER_MAP, "center map" },
    { I18N_ME_MAP_PROPERTIES, "map properties" },
    { I18N_ME_LOAD_MAP, "load map" },
    { I18N_ME_SAVE_MAP, "save map" },
    { I18N_ME_TILE_SELECTOR, "open tile selector" },
    { I18N_ME_OBJECT_SELECTOR, "open object selector" },
    { I18N_ME_HORZ_COPY, "horizontal copy" },
    { I18N_ME_QUICK_LIGHTMAP, "create quick lightmap" },
    { I18N_ME_PIXEL_LIGHTMAP, "create pixel precise lightmap" },
    { I18N_ME_MAP_PACKAGE, "create map package" },
    { I18N_ME_ZAP, "zap/clear map" },
    { I18N_ME_OPTIONS, "map editor options" },
    { I18N_ME_QUIT, "quit map editor" },
    { I18N_ME_COMPILING, "Please wait... ${1}%" },
    { I18N_ME_MODIFIED, "modified" },
    { I18N_ME_COMPILING2, "Compiling" },
    { I18N_ME_LIGHT_SRC, "Light Sources" },
    { I18N_ME_NO_LIGHT_SRC, "No light sources found in this map." },
    { I18N_ME_MAP_NAME, "No Map Name" },
    { I18N_ME_NO_MAP_NAME, "Please define a map name in the map properties." },
    { I18N_ME_NO_TILESET1, "No Tileset" },
    { I18N_ME_NO_TILESET2, "Please select a tileset in the map properties." },
    { I18N_ME_LIGHT_MAP, "Light Map" },
    { I18N_ME_SAVING_FAILED, "Saving failed: ${1}" },
    { I18N_ME_MODE_TILE, "TILE" },
    { I18N_ME_MODE_OBJECT, "OBJECT" },
    { I18N_ME_MODE_LIGHT, "LIGHT" },
    { I18N_ME_MODE_EDIT_LIGHT, "EDIT LIGHT" },
    { I18N_ME_MIRRORING, "mirroring" },
    { I18N_ME_DECORATION, "decoration" },
    { I18N_ME_NO_DEC, "NO DECORATION" },
    { I18N_ME_NO_LGTMP, "NO LIGHTMAP" },
    { I18N_ME_NO_MP, "NO MAP" },
    { I18N_ME_NO_OBJ, "NO OBJECTS" },
    { I18N_ME_NO_LGT, "NO LIGHT" },
    { I18N_ME_LOAD_MAP_TITLE, "Load Map" },
    { I18N_ME_ERROR_TITLE, "Error" },
    { I18N_ME_NO_SELECTION, "No Selection" },
    { I18N_ME_SELECT_MAP, "Please select a map." },
    { I18N_ME_LIGHT_PROPERTIES, "Light Properties" },
    { I18N_ME_LP_RADIUS, "radius:" },
    { I18N_ME_LP_RED, "red:" },
    { I18N_ME_LP_GREEN, "green:" },
    { I18N_ME_LP_BLUE, "blue:" },
    { I18N_ME_MP_TITLE, "Map Properties" },
    { I18N_ME_MP_NAME, "name:" },
    { I18N_ME_MP_FROG_SPAWN, "frog spawn:" },
    { I18N_ME_MP_AUTHOR, "author:" },
    { I18N_ME_MP_DESCRIPTION, "description:" },
    { I18N_ME_MP_WIDTH, "width:" },
    { I18N_ME_MP_HEIGHT, "height:" },
    { I18N_ME_MP_DECO_BRIGHTNESS, "deco brghtn.:" },
    { I18N_ME_MP_LIGHTMAP_ALPHA, "lgtmap alpha:" },
    { I18N_ME_MP_PARALLAX, "parallax:" },
    { I18N_ME_MP_TYPE, "type:" },
    { I18N_ME_MP_TILESET, "tileset:" },
    { I18N_ME_MP_BACKGROUND, "background:" },
    { I18N_ME_SAVE_NO_MAP_NAME, "No Map Name" },
    { I18N_ME_SAVE_CHOOSE_NAME, "Please choose a map name in the map properties." },
    { I18N_ME_SELECT_TILE, "Select Tile" },
    { I18N_ME_ST_PROPERTIES, "Properties" },
    { I18N_ME_ST_NO_TILE1, "No Tile" },
    { I18N_ME_ST_NO_TILE2, "Please select a tile first." },
    { I18N_ME_TP_TITLE, "Tile Properties (${1})" },
    { I18N_ME_TP_BACKGROUND, "tile is in background" },
    { I18N_ME_TP_BLOCKS_LIGHT, "tile blocks light" },
    { I18N_ME_TP_TILE_TYPE, "tile type:" },
    { I18N_ME_TP_ANIMATION_SPEED, "animation speed:" },
    { I18N_ME_TP_FRICTION, "friction:" },
    { I18N_ME_SO_TITLE, "Select Object" },
    { I18N_ME_HC_MAP_INVALID1, "Map Invalid" },
    { I18N_ME_HC_MAP_INVALID2, "Please configure this map first." },
    { I18N_ME_HC_MAP_INVALID3, "The width of the map must be even." },
    { I18N_ME_HC_TITLE, "Horizontal Copy" },
    { I18N_ME_HC_QUESTION, "This operation cannot be undone. Continue?" },
    { I18N_ME_PAK_NO_MAP, "No Map" },
    { I18N_ME_PAK_CONFIGURE, "Please create or load a map first, before you can create a package." },
    { I18N_ME_PAK_SAVE_FIRST, "Please save your map first." },
    { I18N_ME_PAK_OVERWRITE1, "Overwrite?" },
    { I18N_ME_PAK_OVERWRITE2, "Overwrite existing package?" },
    { I18N_ME_PAK_DONE1, "Done" },
    { I18N_ME_PAK_DONE2, "Your package '${1}.pak' has been created." },
    { I18N_ME_OPTIONS1, "Options" },

    { I18N_FREETYPE_FAILED, "freetype initialization failed." },
    { I18N_LANGUAGE, "Language" },
    { I18N_PAK_NAME_TOO_LONG, "Pak name '${1}' too long (max. 31). Please rename it." },
    { I18N_SHOW_LAGOMETER, "show lagometer" },
    { I18N_SERVE_NO_COMMAND, "No server command entered" },
    { I18N_SERVE_LIST_USAGE, "Usage: /list [part_of_player_name]" },
    { I18N_CLIENT_LOGGED_OUT_RPL, "${1} logged out." },
    { I18N_CLIENT_PING_TIMEOUT_RPL, "${1} logged out. (ping timeout)" },
    { I18N_CLIENT_TOO_MANY_RESENDS_RPL, "${1} logged out. (too many resends)" },
    { I18N_CLIENT_APPLICATION_LAYER_RPL, "${1} logged out. (application layer quit)" },

    { I18N_NONE, 0 }
};
