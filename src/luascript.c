/* luascript.c

   Copyright (C) 2025 Ivan Guerreschi.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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
static int l_hello(lua_State *l)
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

	/* Calls the C function hello_fish and prints the result. */
	printf("%s%s%s\n", ansi_color, hello_fish(), RESET);

	return 0;
}

/* C function exposed to Lua as "version". */
static int l_version(lua_State *l __attribute__((unused)))
{
	/* Calls the C function hello_fish and prints the result. */
	printf("%s\n", version());

	return 0;
}

/* C function exposed to Lua as "package". */
static int l_package(lua_State *l __attribute__((unused)))
{
	/* Calls the C function package and prints the result. */
	printf("%s\n", package());

	return 0;
}

/* C function exposed to Lua as "bugreport". */
static int l_bugreport(lua_State *l __attribute__((unused)))
{
	/* Calls the C function bugreport and prints the result. */
	printf("%s\n", bugreport());

	return 0;
}

/* C function exposed to Lua as "license". */
static int l_license(lua_State *l __attribute__((unused)))
{
	/* Calls the C function license and prints the result. */
	printf("%s\n", license());

	return 0;
}

/* C function exposed to Lua as "help". */
static int l_help(lua_State *l __attribute__((unused)))
{
	/* Calls the C function help and prints the result. */
	printf("%s\n", help());

	return 0;
}

static int l_print_aquarium(lua_State *l)
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
	const char *name = hello_fish();
	struct Fish fish = { FISH, name, 0, 0 };
	char *aquarium = create_aquarium();
	time_t start_time = time(NULL);

	while (time(NULL) - start_time < 80) {
		print_aquarium(aquarium, ansi_color, fish);
		sleep(1);
		fish.x++;
		if (fish.x > 9) {
			fish.x = 0;
			fish.y++;
		}

		if (fish.x == 7 && fish.y == 9)
			break;

	}

	free(aquarium);

	return 0;
}

/* Function to initialize the Lua interpreter. */
static lua_State *init(void)
{
	/* Creates a new Lua state. */
	lua_State *l = luaL_newstate();

	if (NULL == l) {
		fprintf(stderr, "Lua initialization error\n");
		return NULL;
	}

	/* Opens the standard Lua libraries. */
	luaL_openlibs(l);

	return l;
}

/* Function to register the C functions in Lua. */
static void register_functions(lua_State *l)
{
	/* Pushing the C function onto the Lua stack */
	/* Assigning the global name (for example "hello") to the function */
	lua_pushcfunction(l, l_hello);
	lua_setglobal(l, "hello");
	lua_pushcfunction(l, l_version);
	lua_setglobal(l, "version");
	lua_pushcfunction(l, l_package);
	lua_setglobal(l, "package");
	lua_pushcfunction(l, l_bugreport);
	lua_setglobal(l, "bugreport");
	lua_pushcfunction(l, l_license);
	lua_setglobal(l, "license");
	lua_pushcfunction(l, l_help);
	lua_setglobal(l, "help");
	lua_pushcfunction(l, l_print_aquarium);
	lua_setglobal(l, "aquarium");
}

/* Main function to load and execute the Lua script. */
int load_lua_script(const char *scriptname)
{
	/* Initializes the Lua interpreter. */
	lua_State *l = init();
	if (NULL == l)
		return 1;

	/* Registers the C functions. */
	register_functions(l);

	/* Loads and executes the Lua script. */
	if (luaL_dofile(l, scriptname) != LUA_OK) {
		fprintf(stderr, "Error while executing Lua script: %s\n",
			lua_tostring(l, -1));
		lua_close(l);
		return 1;
	}

	/* Closes the Lua state. */
	lua_close(l);

	return 0;
}
