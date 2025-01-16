# Copyright (c) 2025 Ivan Guerreschi <ivan.guerreschi.dev@gmail.com>
# All rights reserved.
#
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions are met:
#
# 1. Redistributions of source code must retain the above copyright notice,
#    this list of conditions and the following disclaimer.
#
# 2. Redistributions in binary form must reproduce the above copyright notice,
#    this list of conditions and the following disclaimer in the documentation
#    and/or other materials provided with the distribution.
#
# 3. Neither the name of the copyright holder nor the names of its
#    contributors may be used to endorse or promote products derived from
#    this software without specific prior written permission.
#
# THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
# AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
# IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
# ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
# LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
# CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
# SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
# INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
# CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
# ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
# POSSIBILITY OF SUCH DAMAGE.

# Phony targets
.PHONY: all clean

# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -O2 -ggdb
LDLIBS = -L../deps/lua/src -l:liblua.a -lm
LDFLAGS = -I../deps/lua/src -L../deps/lua/src -l:liblua.a

# Source files
SRCS = info.c luascript.c konsolenfisch.c terminal.c

# Object files
OBJS = $(SRCS:.c=.o)

# Target executable name
TARGET = konsolenfisch

# Install directory
INSTALL_DIR = $(HOME)/.local/bin

# Default target
all: $(TARGET)

# Link the program
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ $(LDLIBS)

# Compile object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ $(LDFLAGS)

# Install target (optional)
install: $(TARGET)
	@mkdir -p $(INSTALL_DIR)
	install -m 755 $(TARGET) $(INSTALL_DIR)/$(TARGET)

# Uninstall target (optional)
uninstall: $(TARGET)
	rm -f $(INSTALL_DIR)/$(TARGET)

# Clean up object files and the executable
clean:
	rm -f $(OBJS) $(TARGET)

