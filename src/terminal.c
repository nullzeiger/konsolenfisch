/* File: terminal.c
 * Copyright (c) 2025 Ivan Guerreschi <ivan.guerreschi.dev@gmail.com>
 * All rights reserved.
 *
 * Use of this source code is governed by a BSD-style
 * license that can be found in the LICENSE file.
 */

#include "fish.h"
#include "terminal.h"

/* Returns a greeting string including a fish name. */
const char *hello_fish(void)
{
    /* TODO: Add random name generation. Currently, it always returns "Gold". */
    const char *name = "Gold";
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
