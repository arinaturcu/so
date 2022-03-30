/**
 * SO
 * Lab #4
 *
 * Task #5, Linux
 *
 * Avoid creating zombies using signals
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <signal.h>
#include <sys/types.h>
#include <unistd.h>

#include "../utils/utils.h"

#define TIMEOUT		20

/*
 * configure signal handler
 */
static void set_signals(void)
{
	struct sigaction sa;

	memset(&sa, 0, sizeof(sa));

	/* TODO - ignore SIGCHLD */
	signal(17, SIG_IGN);
}

int main(void)
{
	pid_t pid;

	/* TODO - create child process without waiting */
	pid = fork();

	/* TODO - sleep */
	if (pid == 0) {
		exit(0);
	}

	sleep(30);

	return 0;
}
