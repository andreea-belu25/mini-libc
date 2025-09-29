// SPDX-License-Identifier: BSD-3-Clause

#include <unistd.h>
#include <internal/syscall.h>
#include <errno.h>
#include <internal/io.h>
#include <internal/types.h>

off_t lseek(int fd, off_t offset, int whence)
{
	//  lseek -> changes the location of a file's read/write pointer

	/* fd = which file to open,
	   offset = the pointer's offset measured in bytes
	   whence = the method of interpreting the offset */
	/* system call lseek; if the call succeeded
	I return its value, otherwise I update errno and return
	-1 */
	int rez = syscall(__NR_lseek, fd, offset, whence);
	
	if (rez >= 0)
		return rez;
	errno = -rez;
	
	return -1;
}
