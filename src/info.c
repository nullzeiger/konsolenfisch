/* info.c

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

#include "info.h"
#include <string.h>

/* This function likely retrieves the version string from a pre-defined
 * constant named `VERSION` defined elsewhere in the project. */
const char *version(void)
{
	return VERSION;
}

/* This function likely retrieves the package name string from a pre-defined
 * constant named `PACKAGE_STRING` defined elsewhere in the project. */
const char *package(void)
{
	return PACKAGE_STRING;
}

/* This function likely retrieves the bug report address string from a pre-defined
 * constant named `PACKAGE_BUGREPORT` defined elsewhere in the project. */
const char *bugreport(void)
{
	return PACKAGE_BUGREPORT;
}

/* This function returns the full BSD-3-Clause license. */
const char *license(void)
{
	return
	    "Copyright (c) 2025 Ivan Guerreschi <ivan.guerreschi.dev@gmail.com>\n"
	    "This program is free software: you can redistribute it and/or "
	    "modify\n"
	    "it under the terms of the GNU General Public License as published "
	    "by\n"
	    "the Free Software Foundation, either version 3 of the License, or\n"
	    "(at your option) any later version.\n\n"
	    "This program is distributed in the hope that it will be useful,\n"
	    "but WITHOUT ANY WARRANTY; without even the implied warranty of\n"
	    "MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the\n"
	    "GNU General Public License for more details.\n\n"
	    "You should have received a copy of the GNU General Public License\n"
	    "along with this program.  If not, see "
	    "<https://www.gnu.org/licenses/>.\n";
}

/* This function returns a string containing the help message describing
 *  the program's usage and available options. */
const char *help(void)
{
	return "konsolenfisch\n"
	    "Options:\n"
	    "  --help -h    Help\n"
	    "  --load -l    Load Lua script file\n"
	    "  --version -v Program version\n";
}
