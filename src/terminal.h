/* File header: terminal.h
 *
 * Copyright (c) 2025 Ivan Guerreschi <ivan.guerreschi.dev@gmail.com>
 * All rights reserved.
 *
 * Use of this source code is governed by a BSD-style
 * license that can be found in the LICENSE file.
 */

/* This header file defines function prototypes related to fish and terminal output. */
#ifndef TERMINAL_H
#define TERMINAL_H

/* Returns a greeting string including a fish name. */
const char *hello_fish(void);

/* Returns the string representation of a fish facing right. */
const char *fish_r(void);

/* Returns the string representation of a fish facing left. */
const char *fish_l(void);

/* Returns the string representation of a fish facing down. */
const char *fish_d(void);

#endif /* TERMINAL_H */
