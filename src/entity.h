/* File header: entity.h
 *
 * Copyright (c) 2025 Ivan Guerreschi <ivan.guerreschi.dev@gmail.com>
 * All rights reserved.
 *
 * Use of this source code is governed by a BSD-style
 * license that can be found in the LICENSE file.
 */

/* This header file defines macros to graphically represent
 * a fish in different directions. */
#ifndef ENTITY_H
#define ENTITY_H

/* Macro FISHR represents a fish facing right. */
#define FISHR '>'

/* Macro FISHL represents a fish facing left. */
#define FISHL '<'

/* Macro WATER represents a water in acquarium */
#define WATER '~'

/* Macro BASE represents a base in acquarium */
#define BASE '-'

/* Macro ROWS and COLS represent a dimension of acquarium */
#define ROWS 10
#define COLS 10

enum FishDir {
    R,
    L
};

struct Fish {
    char fish_entity;
    int x;
    int y;
    enum FishDir fish_dir;
} ;

#endif /* ENTITY_H */
