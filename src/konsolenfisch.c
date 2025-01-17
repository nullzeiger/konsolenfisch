/* File: konsolenfisch.c
 *
 * Copyright (c) 2025 Ivan Guerreschi <ivan.guerreschi.dev@gmail.com>
 * All rights reserved.
 *
 * Use of this source code is governed by a BSD-style
 * license that can be found in the LICENSE file.
 */

#include <stdio.h>
#include "luascript.h"
#include "info.h"
#include "user_input.h"

/* Main function of the program.
 * Parsing input user. */
int main(int argc, char *argv[])
{
    parsing(argc, argv);

    return 0;
}
