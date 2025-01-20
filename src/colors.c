/* File: colors.c
 * Copyright (c) 2025 Ivan Guerreschi <ivan.guerreschi.dev@gmail.com>
 * All rights reserved.
 *
 * Use of this source code is governed by a BSD-style
 * license that can be found in the LICENSE file.
 */

#include <string.h>
#include "colors.h"

/* Colors Array */
static const struct color_map colors[] = {
    {"BLACK",   BLACK},
    {"RED",     RED},
    {"GREEN",   GREEN},
    {"YELLOW",  YELLOW},
    {"BLUE",    BLUE},
    {"MAGENTA", MAGENTA},
    {"CYAN",    CYAN},
    {"WHITE",   WHITE},
    {NULL,      NULL}
};

/* Convert string color to macro color */
const char* convert_color_to_ansi(const char *color) {
    /* Initializes a cm pointer to the color_map structure that points to
     * the beginning of the colors array.
     * Continues until it finds an element with a name equal to NULL.
     * Increments the pointer to move to the next element in the structure. */
    for (const struct color_map *cm = colors; cm->name != NULL; cm++) {
        if (strcmp(color, cm->name) == 0) {
            return cm->code;
        }
    }

    return "";
}
