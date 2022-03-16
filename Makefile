CC := gcc
CFLAGS := -lX11 -g -O2 -std=gnu99

.PHONY: a_wm

a_wm: src/awm.c
	$(CC) $^ $(CFLAGS) -o awm

install:
	sudo cp awm /usr/locla/bin/awm
