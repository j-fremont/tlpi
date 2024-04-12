#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "lib/tlpi_hdr.h"

#ifndef MAX_READ /* Allow "cc -D" to override definition */
#define MAX_READ  20
#endif

int
main(int argc, char *argv[])
{
	int inputFd, outputFd, openFlags;
	ssize_t numRead;
	mode_t filePerms;
	char buffer[MAX_READ + 1];

	if (argc < 2 || argc > 3 || strcmp(argv[1], "--help") == 0)
		usageErr("%s file {-a}\n", argv[0]);
	
	numRead = read(STDIN_FILENO, buffer, MAX_READ);
	if (numRead == -1)
		errExit("read");
	
	openFlags = O_CREAT | O_WRONLY | (getopt(argc, argv, "a") != -1 ? O_APPEND : O_TRUNC);
	filePerms = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH; /* rw-rw-rw- */
	outputFd = open(argv[1], openFlags, filePerms);
	if (outputFd == -1)
		errExit("opening file %s", argv[2]);

	if (write(outputFd, buffer, numRead) != numRead)
		fatal("couldn't write whole buffer");

	if (close(outputFd) == -1)
		errExit("close output");

	exit(EXIT_SUCCESS);
}

