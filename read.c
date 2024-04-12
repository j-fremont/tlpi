#include <sys/stat.h>
#include <fcntl.h>
#include "lib/tlpi_hdr.h"

#ifndef MAX_READ /* Allow "cc -D" to override definition */
#define MAX_READ  20
#endif

int
main(int argc, char *argv[])
{
	char buffer[MAX_READ + 1];
	ssize_t numRead;

	numRead = read(STDIN_FILENO, buffer, MAX_READ);
	if (numRead == -1)
		errExit("read");

	buffer[numRead] = '\0';
	printf("The input data was: %s\n", buffer);
}

