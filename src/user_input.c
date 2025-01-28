/* File: user_input.c
 *
 * Copyright (c) 2025 Ivan Guerreschi <ivan.guerreschi.dev@gmail.com>
 * All rights reserved.
 *
 * Use of this source code is governed by a BSD-style
 * license that can be found in the LICENSE file.
 */

#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>
#include "luascript.h"
#include "info.h"
#include "user_input.h"
#include "terminal.h"

/* This function is responsible for parsing the command-line
 * arguments provided to the program. */
int parsing (int argc, char **argv)
{
    int opt;
    int ret = 1;

    /* Define short option string. */
    const char *short_opts = "hl:v";

    /* Define long options array */
    static struct option long_options[] = {
        {"help", no_argument, 0, 'h'},
        {"load", required_argument, 0, 'l'},
        {"version", no_argument, 0, 'v'},
        {0, 0, 0, 0}
    };

    while (1) {
        /* Get the next option using getopt_long. */
        opt = getopt_long (argc, argv, short_opts, long_options, 0);

        /* If there are no more options, break the loop. */
        if (opt == -1)
            break;

        /* Switch statement to handle different options.*/
        switch (opt) {
            case 'h':
                printf ("%s\n%s\n%s\n", help (), license (), bugreport ());
                ret = 0;
                break;
            case 'l':
                char *scriptname = optarg;
                ret = load_lua_script (scriptname);
                break;
            case 'v':
                printf ("%s\n", package ());
                ret = 0;
                break;
            case '?':
                printf ("%s\n", help ());
                ret = 1;
                break;
            default:
                abort ();
                ret = 1;
        }
    }

    return ret;
}
