// SPDX-License-Identifier: BSD-3-Clause

#include <sys/stat.h>
#include <internal/syscall.h>
#include <errno.h>

int fstat(int fd, struct stat *st)
{
	// fstat -> obtains information about an open file
	/*  fd = the file descriptor associated with the file
		st = where the information is stored */
	
	// Syscall similar to the rest
	int rez = syscall(__NR_fstat, fd, st);
	
	if (rez >= 0)
		return rez;
	
	errno = -rez;
	
	return -1;
}
