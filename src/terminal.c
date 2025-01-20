/* File: terminal.c
 * Copyright (c) 2025 Ivan Guerreschi <ivan.guerreschi.dev@gmail.com>
 * All rights reserved.
 *
 * Use of this source code is governed by a BSD-style
 * license that can be found in the LICENSE file.
 */

#include <stdlib.h>
#include <time.h>
#include "fish.h"
#include "terminal.h"

/* Returns a greeting string including a fish name. */
const char *hello_fish()
{
    const char *fish_name[5] = {"Goldie", "Finny", "Bubbles", "Sunny", "Splash"};
    srand(time(NULL));
    /* Generate a random number between 0 and 4 (inclusive) */
    int random_number = rand() % 5;
    const char *name = fish_name[random_number];

    return name;
}

/* Returns the string representation of a fish facing right.
 * The string is defined by the FISHR macro. */
const char *fish_r(void)
{
    return FISR;
}

/* Returns the string representation of a fish facing left.
 * The string is defined by the FISHL macro. */
const char *fish_l(void)
{
    return FISHL;
}

/* Returns the string representation of a fish facing left.
 * The string is defined by the FISHD macro. */
const char *fish_d(void)
{
    return FISHD;
}
