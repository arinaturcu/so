/**
 * SO
 * Lab #4
 *
 * Task #3, Linux
 *
 * Signal handling by asking questions
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

#include <signal.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>

#include "../utils/utils.h"

#define MY_MAX		32
#define TIMEOUT		1

static void print_next(void)
{
	static int n = 1;

	printf("n = %d\n", n);

	n = (n + 1) % MY_MAX;
}

/* signal handler */
static void ask_handler(int signo)
{
	char buffer[128];

	printf("Got %d  - Stop program? [Y/n] ", signo);
	fflush(stdout);
	fgets(buffer, 128, stdin);
	buffer[strlen(buffer)-1] = '\0';

	if (buffer[0] == 'y' || buffer[0] == 'Y')
		exit(EXIT_SUCCESS);
}

/* configure handlers */
static void set_signals(void)
{
	struct sigaction sa;
	int rc, i;

	/* TODO - set handler in struct sigaction sa */
	sa.sa_handler = ask_handler;

	/* TODO - handle SIGINT, SIGQUIT and SIGUSR1 signals */
	int signals_to_mask[] = {SIGINT, SIGQUIT, SIGUSR1};

	for (i = 0; i < sizeof(signals_to_mask)/sizeof(int); i++) {
		rc = sigaction(signals_to_mask[i], &sa, NULL);
		DIE(rc == -1, "sigaction");
	}
}

int main(void)
{
	set_signals();

	while (1) {
		print_next();
		sleep(TIMEOUT);
	}

	return 0;
}
