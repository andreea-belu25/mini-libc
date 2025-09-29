// SPDX-License-Identifier: BSD-3-Clause

#include <fcntl.h>
#include <internal/syscall.h>
#include <stdarg.h>
#include <errno.h>

int open(const char *filename, int flags, ...)
{
	/* variable argument list for the possible
	   file opening modes */
	va_list valist;
	va_start(valist, flags);
	int a = va_arg(valist, int);
	va_end(valist);

	//  open -> file opening

	/* filename = which file to open,
	   flags = file permissions
	   ... -> variable argument list */
	/* system call open; if the call succeeded
	I return its value, otherwise I update errno and return
	-1 */
	int rez = syscall(__NR_open, filename, flags, a);
	
	if (rez >= 0)
		return rez;
	errno = -rez;
	
	return -1;
}
