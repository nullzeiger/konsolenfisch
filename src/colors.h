/* File header: colors.h
 *
 * Copyright (c) 2025 Ivan Guerreschi <ivan.guerreschi.dev@gmail.com>
 * All rights reserved.
 *
 * Use of this source code is governed by a BSD-style
 * license that can be found in the LICENSE file.
 */

/* This header file defines ANSI escape codes for controlling
 * text colors in a terminal. */
#ifndef COLORS_H
#define COLORS_H

/* Text colors */
#define BLACK       "\x1b[30m"
#define RED         "\x1b[31m"
#define GREEN       "\x1b[32m"
#define YELLOW      "\x1b[33m"
#define BLUE        "\x1b[34m"
#define MAGENTA     "\x1b[35m"
#define CYAN        "\x1b[36m"
#define WHITE       "\x1b[37m"

/* Background color codes */
#define BG_BLACK    "\x1b[40m"
#define BG_RED      "\x1b[41m"
#define BG_GREEN    "\x1b[42m"
#define BG_YELLOW   "\x1b[43m"
#define BG_BLUE     "\x1b[44m"
#define BG_MAGENTA  "\x1b[45m"
#define BG_CYAN     "\x1b[46m"
#define BG_WHITE    "\x1b[47m"

/* Resets all attributes */
#define RESET       "\x1b[0m"

/* Clear terminal */
#define CLEAR       "\033[2J\033[H"

/* Associating a name with a color code */
struct color_map {
    const char *name;
    const char *code;
};

/* Convert color to ansi macro */
const char* convert_color_to_ansi(const char *color);

#endif /* COLORS_H */
