EXE=meh-do

CC ?= gcc
override CFLAGS := -Wall -Wextra --std=c99 -pedantic $(CFLAGS)
INSTALL=install
INSTALLFLAGS=-C -D
MANSECTION=man1

DESTDIR=
PREFIX=/usr/local

.PHONY: default
default: all

.PHONY: debug
debug: CFLAGS += -g -O0
debug: all

.PHONY: all
all: $(EXE)

$(EXE): $(EXE).c
	$(CC) $(CLFLAGS) $< -o $@

.PHONY: clean
clean:
	rm -f $(EXE)

.PHONY: install
install:
	mkdir -p $(DESTDIR)$(PREFIX)/bin
	$(INSTALL) $(INSTALLFLAGS) $(EXE) $(DESTDIR)$(PREFIX)/bin/$(EXE)
	mkdir -p $(DESTDIR)$(PREFIX)/man/$(MANSECTION)
	$(INSTALL) $(EXE).1 $(DESTDIR)$(PREFIX)/man/$(MANSECTION)/$(EXE).1
	chown root:root $(DESTDIR)$(PREFIX)/bin/$(EXE)
	chmod 4755 $(DESTDIR)$(PREFIX)/bin/$(EXE)
