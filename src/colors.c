/* colors.c

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

#include <string.h>
#include "colors.h"

/* Colors Array */
static const struct color_map colors[] = {
  {"BLACK", BLACK},
  {"RED", RED},
  {"GREEN", GREEN},
  {"YELLOW", YELLOW},
  {"BLUE", BLUE},
  {"MAGENTA", MAGENTA},
  {"CYAN", CYAN},
  {"WHITE", WHITE},
  {NULL, NULL}
};

/* Convert string color to macro color */
const char *
convert_color_to_ansi (const char *color)
{
  /* Initializes a cm pointer to the color_map structure that points to
   * the beginning of the colors array.
   * Continues until it finds an element with a name equal to NULL.
   * Increments the pointer to move to the next element in the structure. */
  for (const struct color_map * cm = colors; cm->name != NULL; cm++)
    {
      if (strncasecmp (color, cm->name, strlen (cm->name)) == 0)
	{
	  return cm->code;
	}
    }

  return "";
}
