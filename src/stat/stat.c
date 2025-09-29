// SPDX-License-Identifier: BSD-3-Clause

#include <sys/stat.h>
#include <internal/syscall.h>
#include <fcntl.h>
#include <errno.h>

int stat(const char *restrict path, struct stat *restrict buf)
{
	// stat -> provides information about a file and filesystem
	/*  path = the path of the file about which I want to get information
		buf = where the information is stored */
	
	// Syscall similar to the rest
	int rez = syscall(__NR_stat, path, buf);
	
	if (rez >= 0)
		return rez;
	
	errno = -rez;
	
	return -1;
}
