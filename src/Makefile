# Source code Makefile
#
# Copyright (c) 2025 Ivan Guerreschi <ivan.guerreschi.dev@gmail.com>
# All rights reserved.
#
# Use of this source code is governed by a BSD-style
# license that can be found in the LICENSE file.

# Phony targets
.PHONY: all clean

# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -O2 -ggdb -Werror -Wformat=2 \
		 -Wunused -Wmissing-prototypes -Wstrict-prototypes \
		 -Wcast-qual -Wnull-dereference -Wduplicated-cond
LDLIBS = -L../lua/src -l:liblua.a -lm
LDFLAGS = -I../lua/src -l:liblua.a

# Source files
SRCS = $(wildcard *.c)
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
%.o: %.c %.h
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

