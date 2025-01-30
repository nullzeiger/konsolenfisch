/* terminal.h

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

/* This header file defines function prototypes related to fish and terminal output. */
#ifndef TERMINAL_H
#define TERMINAL_H

#include "entity.h"

/* Returns a greeting string including a fish name. */
const char *hello_fish (void);

/* Create aquarium */
char *create_aquarium (void);

/* Print aquarium */
void print_aquarium (char *aquarium, const char *, struct Fish);

#endif /* TERMINAL_H */
