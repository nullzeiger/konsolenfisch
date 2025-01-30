/* terminal.c
   
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
   
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include "colors.h"
#include "entity.h"
#include "terminal.h"

/* Returns a greeting string including a fish name. */
const char *
hello_fish ()
{
  const char *fish_name[5] =
    { "Goldie", "Finny", "Bubbles", "Sunny", "Splash" };
  srand (time (NULL));
  /* Generate a random number between 0 and 4 (inclusive) */
  int random_number = rand () % 5;
  const char *name = fish_name[random_number];

  return name;
}

/* Return the matrix of char representation aquarium. */
char *
create_aquarium (void)
{
  char *aquarium = malloc (ROWS * COLS * sizeof (char));

  if (aquarium == NULL)
    {
      return NULL;
    }

  for (int i = 0; i < ROWS; i++)
    {
      for (int j = 0; j < COLS; j++)
	{
	  aquarium[i * ROWS + j] = WATER;
	}
    }

  return aquarium;
}

/* Print and update state of fish. */
void
print_aquarium (char *aquarium, const char *color, struct Fish fish)
{
  if (isatty (STDOUT_FILENO))
    {
      printf (CLEAR);
      fflush (stdout);
    }
  else
    {
      fprintf (stderr, "Output is not a terminal. Skipping clear screen.\n");
    }

  printf ("%s\n", fish.name);

  aquarium[fish.y * ROWS + fish.x] = fish.fish_entity;

  for (int i = 0; i < ROWS - 2; i++)
    {
      for (int j = 0; j < COLS; j++)
	{
	  if (fish.y == i && fish.x == j)
	    printf ("%s%c%s", RED, aquarium[i * ROWS + j], RESET);
	  else
	    printf ("%s%c%s", BLUE, aquarium[i * ROWS + j], RESET);
	}

      printf ("\n");
    }

  aquarium[fish.y * ROWS + fish.x] = WATER;

  for (int i = 0; i < 2; i++)
    {
      for (int j = 0; j < COLS; j++)
	{
	  printf ("%s%c%s", color, BASE, RESET);
	}

      printf ("\n");
    }
}
