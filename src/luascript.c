/* File: luascript.c
 * Copyright (c) 2025 Ivan Guerreschi <ivan.guerreschi.dev@gmail.com>
 * All rights reserved.
 *
 * Use of this source code is governed by a BSD-style
 * license that can be found in the LICENSE file.
 */

#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "colors.h"
#include "entity.h"
#include "info.h"
#include "luascript.h"
#include "terminal.h"

/* C function exposed to Lua as "hello". */
static int l_hello(lua_State *L)
{
    /* Check if an argument was passed */
    if (lua_gettop(L) != 1) {
        return luaL_error(L, "Expected 1 argument (color)");
    }

    /* Check if the argument is a string */
    if (lua_type(L, 1) != LUA_TSTRING) {
        return luaL_error(L, "Argument must be a string");
    }

    /* Get the string argument */
    const char *color = lua_tostring(L, 1);

    /* Convert string to macro */
    const char *ansi_color = convert_color_to_ansi(color);

    /* Calls the C function hello_fish and prints the result. */
    printf("%s%s%s\n", ansi_color, hello_fish(), RESET);

    return 0;
}

/* C function exposed to Lua as "version". */
static int l_version(lua_State *L __attribute__((unused)))
{
    /* Calls the C function hello_fish and prints the result. */
    printf("%s\n", version());

    return 0;
}

/* C function exposed to Lua as "package". */
static int l_package(lua_State *L __attribute__((unused)))
{
    /* Calls the C function package and prints the result. */
    printf("%s\n", package());

    return 0;
}


/* C function exposed to Lua as "bugreport". */
static int l_bugreport(lua_State *L __attribute__((unused)))
{
    /* Calls the C function bugreport and prints the result. */
    printf("%s\n", bugreport());

    return 0;
}

/* C function exposed to Lua as "license". */
static int l_license(lua_State *L __attribute__((unused)))
{
    /* Calls the C function license and prints the result. */
    printf("%s\n", license());

    return 0;
}

/* C function exposed to Lua as "help". */
static int l_help(lua_State *L __attribute__((unused)))
{
    /* Calls the C function help and prints the result. */
    printf("%s\n", help());

    return 0;
}

/* C function that is exposed to Lua as "fishl." */
static int l_fishl(lua_State *L)
{
    /* Check if an argument was passed */
    if (lua_gettop(L) != 1) {
        return luaL_error(L, "Expected 1 argument (color)");
    }

    /* Check if the argument is a string */
    if (lua_type(L, 1) != LUA_TSTRING) {
        return luaL_error(L, "Argument must be a string");
    }

    /* Get the string argument */
    const char *color = lua_tostring(L, 1);

    /* Convert string to macro */
    const char *ansi_color = convert_color_to_ansi(color);

    /* Calls the C function fish_l and prints the result. */
    printf("%s%c%s\n", ansi_color, fish_l(), RESET);

    return 0;
}

/* C function that is exposed to Lua as "fishr." */
static int l_fishr(lua_State *L)
{
    /* Check if an argument was passed */
    if (lua_gettop(L) != 1) {
        return luaL_error(L, "Expected 1 argument (color)");
    }

    /* Check if the argument is a string */
    if (lua_type(L, 1) != LUA_TSTRING) {
        return luaL_error(L, "Argument must be a string");
    }

    /* Get the string argument */
    const char *color = lua_tostring(L, 1);

    /* Convert string to macro */
    const char *ansi_color = convert_color_to_ansi(color);

    /* Calls the C function fish_r and prints the result. */
    printf("%s%c%s\n", ansi_color, fish_r(), RESET);

    return 0;
}

static int l_print_acquarium(lua_State *l)
{
    /* Check if an argument was passed */
    if (lua_gettop(l) != 1) {
        return luaL_error(l, "Expected 1 argument (color)");
    }

    /* Check if the argument is a string */
    if (lua_type(l, 1) != LUA_TSTRING) {
        return luaL_error(l, "Argument must be a string");
    }

    /* Get the string argument */
    const char *color = lua_tostring(l, 1);

    /* Convert string to macro */
    const char *ansi_color = convert_color_to_ansi(color);

    struct Fish fish = { FISHR, 0, 0, R };
    char *acquarium = create_acquarium();
    time_t start_time = time(NULL);

    while (time(NULL) - start_time < 80) {
        print_acquarium(acquarium, ansi_color, fish);
        sleep(1);
        fish.x++;
        if (fish.x > 9) {
            fish.x = 0;
            fish.y++;
        }

        if (fish.x == 7 && fish.y == 9)
            break;

    }

    free(acquarium);

    return 0;
}

/* Function to initialize the Lua interpreter. */
static lua_State *init(void)
{
    /* Creates a new Lua state. */
    lua_State *L = luaL_newstate();

    if (NULL == L) {
        fprintf(stderr, "Lua initialization error\n");
        return NULL;
    }

    /* Opens the standard Lua libraries. */
    luaL_openlibs(L);

    return L;
}

/* Function to register the C functions in Lua. */
static void register_functions(lua_State *L)
{
    /* Pushing the C function onto the Lua stack */
    /* Assigning the global name (for example "hello") to the function */
    lua_pushcfunction(L, l_hello);
    lua_setglobal(L, "hello");
    lua_pushcfunction(L, l_version);
    lua_setglobal(L, "version");
    lua_pushcfunction(L, l_package);
    lua_setglobal(L, "package");
    lua_pushcfunction(L, l_bugreport);
    lua_setglobal(L, "bugreport");
    lua_pushcfunction(L, l_license);
    lua_setglobal(L, "license");
    lua_pushcfunction(L, l_help);
    lua_setglobal(L, "help");
    lua_pushcfunction(L, l_fishl);
    lua_setglobal(L, "fishl");
    lua_pushcfunction(L, l_fishr);
    lua_setglobal(L, "fishr");
    lua_pushcfunction(L, l_print_acquarium);
    lua_setglobal(L, "acquarium");
}

/* Main function to load and execute the Lua script. */
int load_lua_script(const char *scriptname)
{
    /* Initializes the Lua interpreter. */
    lua_State *L = init();
    if (NULL == L)
        return 1;

    /* Registers the C functions. */
    register_functions(L);

    /* Loads and executes the Lua script. */
    if (luaL_dofile(L, scriptname) != LUA_OK) {
        fprintf(stderr, "Error while executing Lua script: %s\n", lua_tostring(L, -1));
        lua_close(L);
        return 1;
    }

    /* Closes the Lua state. */
    lua_close(L);

    return 0;
}
