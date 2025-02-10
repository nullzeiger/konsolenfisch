/* entity.h
 
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

/* This header file defines macros to graphically represent
 * a fish in different directions. */
#ifndef ENTITY_H
#define ENTITY_H

/* Macro FISHR represents a fish facing right. */
#define FISH '>'

/* Macro WATER represents a water in acquarium */
#define WATER '~'

/* Macro BASE represents a base in acquarium */
#define BASE '-'

/* Macro ROWS and COLS represent a dimension of acquarium */
#define ROWS 10
#define COLS 10

struct Fish {
	char fish_entity;
	const char *name;
	int x;
	int y;
};

#endif /* ENTITY_H */
