// SPDX-License-Identifier: BSD-3-Clause

#include <unistd.h>
#include <internal/syscall.h>
#include <errno.h>
#include <internal/io.h>
#include <internal/types.h>

int ftruncate(int fd, off_t length)
{
	/* TODO: Implement ftruncate(). */
	//  ftruncate -> resizes a file to a certain size
	//  fd = which file to open, length = specified length
	/* system call ftruncate; if the call succeeded
	I return its value, otherwise I update errno and return
	-1 */
	int rez = syscall(__NR_ftruncate, fd, length);
	
	if (rez >= 0)
		return rez;
	errno = -rez;
	
	return -1;
}
