#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/syscall.h>
#include <sys/stat.h>
#include "dirent.h"
#define MAX_PATH 1024
#ifndef DIRSIZ
#define DIRSIZ 14
#endif
void fsize (char *name)
{
	struct stat status_buffer;
	if (stat (name, &status_buffer) == -1)
	{
		fprintf (stderr, "Can't access %s\n", name);
		return;
	}
	printf ("Name: %s\nInode number: %lu\nStatus mode: %o\nNumber of links: %lu\nSize: %ld\n", name, status_buffer.st_ino, status_buffer.st_mode, status_buffer.st_nlink, status_buffer.st_size);
}
int main (int argc, char **argv)
{
	if (argc == 1)
		fsize (".");
	else
		while (--argc)
			fsize (*++argv);	
	return 0;
}
