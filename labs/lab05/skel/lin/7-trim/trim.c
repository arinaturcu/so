/**
 * SO
 * Lab #5, Memory Management
 *
 * Task #7, Linux
 *
 * Use of mcheck
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../utils/utils.h"

char first_name[] = "  Harry";
char last_name[]  = "    Potter";

static char *trim(char *s)
{
	char *p = malloc(strlen(s) + 1);
	char *org_p = p;

	strcpy(p, s);

	while (*p == ' ')
		p++;

	strcpy(s, p);
	free(org_p);

	return s;
}

int main(void)
{

	printf("%s %s is learning SO!\n",
			trim(first_name), trim(last_name));

	return 0;
}
