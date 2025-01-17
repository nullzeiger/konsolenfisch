/* File source: info.c
 *
 * Copyright (c) 2025 Ivan Guerreschi <ivan.guerreschi.dev@gmail.com>
 * All rights reserved.
 *
 * Use of this source code is governed by a BSD-style
 * license that can be found in the LICENSE file.
 */

#include "info.h"
#include <string.h>

/* This function likely retrieves the version string from a pre-defined
 * constant named `VERSION` defined elsewhere in the project. */
const char *version(void)
{
    return VERSION;
}

/* This function likely retrieves the package name string from a pre-defined
 * constant named `PACKAGE_STRING` defined elsewhere in the project. */
const char *package(void)
{
    return PACKAGE_STRING;
}

/* This function likely retrieves the bug report address string from a pre-defined
 * constant named `PACKAGE_BUGREPORT` defined elsewhere in the project. */
const char *bugreport(void)
{
    return PACKAGE_BUGREPORT;
}

/* This function returns the full BSD-3-Clause license. */
const char *license(void)
{
    return "Copyright (c) 2025 Ivan Guerreschi <ivan.guerreschi.dev@gmail.com>\n"
        "All rights reserved.\n\n"
        "Redistribution and use in source and binary forms, with or without\n"
        "modification, are permitted provided that the following conditions are met:\n\n"
        "1. Redistributions of source code must retain the above copyright notice, this\n"
        "   list of conditions and the following disclaimer.\n\n"
        "2. Redistributions in binary form must reproduce the above copyright notice,\n"
        "   this list of conditions and the following disclaimer in the documentation\n"
        "   and/or other materials provided with the distribution.\n\n"
        "3. Neither the name of the copyright holder nor the names of its\n"
        "   contributors may be used to endorse or promote products derived from\n"
        "   this software without specific prior written permission.\n\n"
        "THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS \"AS IS\"\n"
        "AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE\n"
        "IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE\n"
        "DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE\n"
        "FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL\n"
        "DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR\n"
        "SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER\n"
        "CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,\n"
        "OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE\n"
        "OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.\n";

}

/* This function returns a string containing the help message describing
 *  the program's usage and available options. */
const char *help(void)
{
    return "konsolenfisch\n"
        "Options:\n"
        "  --help -h    Help\n"
        "  --load -l    Load Lua script file\n"
        "  --version -v Program version\n";
}
