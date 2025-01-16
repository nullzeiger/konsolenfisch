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
