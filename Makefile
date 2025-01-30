# Root Makefile
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

.PHONY: all src deps clean

all:
	$(MAKE) deps
	$(MAKE) src

# Compile konsolenfisch
src:
	$(MAKE) -C src

# Compile Lua
deps:
	$(MAKE) -C lua

install:
	$(MAKE) -C src install

uninstall:
	$(MAKE) -C src uninstall

help:
	@echo "konsolenfisch Project Makefile Commands:"
	@echo "  all       - Build entire project (default)"
	@echo "  src       - Build konsolenfisch source files"
	@echo "  deps      - Build Lua source files"
	@echo "  install   - Install executable to ~/.local/bin"
	@echo "  uninstall - Remove executable from ~/.local/bin"
	@echo "  clean     - Remove all build artifacts"
	@echo ""
	@echo "Usage examples:"
	@echo "  make              # Build entire project"
	@echo "  make install      # Install program"
	@echo "  make clean        # Clean build artifacts"

clean:
	$(MAKE) -C src clean
