// SPDX-License-Identifier: BSD-3-Clause

#include <unistd.h>
#include <internal/syscall.h>
#include <stdarg.h>
#include <errno.h>

int close(int fd)
{
	/* TODO: Implement close(). */

	//  close -> file closing
	//  fd = which file to close
	/* system call close; if the call succeeded
	I return its value, otherwise I update errno and return
	-1 */
	int rez = syscall(__NR_close, fd);

	if (rez >= 0)
		return rez;
	errno = -rez;
	return -1;
}
