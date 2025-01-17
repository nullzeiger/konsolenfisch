/* File: luascript.c
 * Copyright (c) 2025 Ivan Guerreschi <ivan.guerreschi.dev@gmail.com>
 * All rights reserved.
 *
 * Use of this source code is governed by a BSD-style
 * license that can be found in the LICENSE file.
 */

#include <stdio.h>
#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>
#include "terminal.h"
#include "luascript.h"

/* C function exposed to Lua as "hello". */
static int l_hello(lua_State *L)
{
    /* (void)L; silences the compiler warning for the unused L variable. */
    (void)L;

    /* Calls the C function hello_fish with the argument "Gold"
     * and prints the result. */
    printf("%s\n", hello_fish());
    return 0;
}

/* C function that is exposed to Lua as "fishl." */
static int l_fish_l(lua_State *L)
{
    (void)L;
    /* Calls the C function fish_l and prints the result. */
    printf("%s\n", fish_l());
    return 0;
}

/* Function to initialize the Lua interpreter. */
static lua_State *init(void)
{
    /* Creates a new Lua state. */
    lua_State *L = luaL_newstate();

    if (L == NULL) {
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
    lua_pushcfunction(L, l_fish_l);
    lua_setglobal(L, "fishl");
}

/* Main function to load and execute the Lua script. */
int load_lua_script(const char *scriptname)
{
    /* Initializes the Lua interpreter. */
    lua_State *L = init();
    if (L == NULL)
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
