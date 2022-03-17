#pragma once

#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

static void spawn(char **com) {
	if (fork() == 0) {
		setsid();
		if (fork() != 0) {
			_exit(0);
		}
		execvp((char*)com[0], (char**)com);
		_exit(0);
	}
	wait(NULL);
}
