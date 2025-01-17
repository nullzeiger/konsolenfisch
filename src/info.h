/* File header: info.h
 *
 * Copyright (c) 2025 Ivan Guerreschi <ivan.guerreschi.dev@gmail.com>
 * All rights reserved.
 *
 * Use of this source code is governed by a BSD-style
 * license that can be found in the LICENSE file.
 */

#ifndef INFO_H
#define INFO_H

/* Define constants for info. */
#define VERSION "0.1"
#define PACKAGE_BUGREPORT "ivan.guerreschi.dev@gmail.com github.com/nullzeiger/konsolenfisch/issue"
#define PACKAGE_STRING "konsolenfisch version 0.1"

/* Returns the version string of the konsolenfisch package. */
const char *version(void);
/* Returns the package name of the konsolenfisch package. */
const char *package(void);
/* Returns the bug report address for the konsolenfisch package. */
const char *bugreport(void);
/* Returns the license information for the konsolenfisch package. */
const char *license(void);
/* Returns the help text for the konsolenfisch package. */
const char *help(void);

#endif /* INFO_H */
