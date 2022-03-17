CC := gcc
CFLAGS := -lX11 -g -O2 -std=gnu99 -Iinclude/

.PHONY: a_wm

a_wm: src/awm.c
	$(CC) $^ $(CFLAGS) -o awm

run: a_wm
	@bash run-xephyr.sh

clean: ./awm
	@rm $^

install:
	@sudo cp awm /usr/local/bin/awm
