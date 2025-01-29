/* File: terminal.c
 * Copyright (c) 2025 Ivan Guerreschi <ivan.guerreschi.dev@gmail.com>
 * All rights reserved.
 *
 * Use of this source code is governed by a BSD-style
 * license that can be found in the LICENSE file.
 */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include "colors.h"
#include "entity.h"
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
char fish_r(void)
{
    return FISHR;
}

/* Returns the string representation of a fish facing left.
 * The string is defined by the FISHL macro. */
char fish_l(void)
{
    return FISHL;
}

/* Return the matrix of char representation aquarium. */
char *create_aquarium(void)
{
    char *aquarium = malloc(ROWS * COLS * sizeof(char));

    if (aquarium == NULL) {
        return NULL;
    }

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            aquarium[i * ROWS + j] = WATER;
        }
    }

    return aquarium;
}

/* Print and update state of fish. */
void print_aquarium(char *aquarium, const char *color, struct Fish fish)
{
    if (isatty(STDOUT_FILENO)) {
        printf(CLEAR);
        fflush(stdout);
    } else {
        fprintf(stderr, "Output is not a terminal. Skipping clear screen.\n");
    }

    printf("%s\n", fish.name);

    aquarium[fish.y * ROWS + fish.x] = fish.fish_entity;

    for (int i = 0; i < ROWS - 2; i++) {
        for (int j = 0; j < COLS; j++) {
            if (fish.y == i && fish.x == j)
                printf("%s%c%s", RED, aquarium[i * ROWS + j], RESET);
            else
                printf("%s%c%s", BLUE, aquarium[i * ROWS + j], RESET);
        }

        printf("\n");
    }

    aquarium[fish.y * ROWS + fish.x] = WATER;

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%s%c%s", color, BASE, RESET);
        }
        printf("\n");
    }
}
