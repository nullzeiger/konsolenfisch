# Source code Makefile
#
# Copyright (C) 2025 Ivan Guerreschi.
#
#  This program is free software: you can redistribute it and/or modify
#  it under the terms of the GNU General Public License as published by
#  the Free Software Foundation, either version 3 of the License, or
#  (at your option) any later version.
#
#  This program is distributed in the hope that it will be useful,
#  but WITHOUT ANY WARRANTY; without even the implied warranty of
#  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#  GNU General Public License for more details.
#
#  You should have received a copy of the GNU General Public License
#  along with this program.  If not, see <https://www.gnu.org/licenses/>.

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

