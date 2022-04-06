/**
 * SO
 * Lab #5, Memory Management
 *
 * Task #8, Linux
 *
 * Endianess
 */
#include <stdlib.h>
#include <stdio.h>

#include "../utils/utils.h"

int main(void)
{
	int i;
	unsigned int n = 0xDEADBEEF;
	unsigned char *w;

	/* TODO - use w to show all bytes of n in order */
	w = (unsigned char *)&n;
	for (i = 3; i >= 0; i--) {
		printf("%x", *(w + i));
	}

	printf("\n");

	return 0;
}
