## Awm makefile
CC := gcc
LDFLAGS := -lxcb -lxcb-keysyms -lm
CFLAGS := -Iinclude -g -O2 -std=gnu2x

BINARY := awm

.PHONY: build

build: src/awm.c
	@$(CC) $^ $(CFLAGS) $(LDFLAGS) -o $(BINARY)

clean:
	@rm $(BINARY)

install:
	@sudo cp $(BINARY) /usr/local/bin/$(BINARY)
