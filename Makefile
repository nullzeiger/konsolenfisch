# Root Makefile
#
# Copyright (c) 2025 Ivan Guerreschi <ivan.guerreschi.dev@gmail.com>
# All rights reserved.
#
# Use of this source code is governed by a BSD-style
# license that can be found in the LICENSE file.

.PHONY: all src deps clean

all:
	$(MAKE) deps
	$(MAKE) src

# Compile konsolenfisch
src:
	$(MAKE) -C src

# Compile Lua
deps:
	$(MAKE) -C deps/lua

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
