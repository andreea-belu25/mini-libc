// SPDX-License-Identifier: BSD-3-Clause

#include <unistd.h>
#include <internal/syscall.h>
#include <errno.h>
#include <internal/io.h>
#include <internal/types.h>

int truncate(const char *path, off_t length)
{
	/* truncate -> resizes a file to a certain size
	   by shortening it */

	//  path = the path of the file to open, length = specified length
	/* system call truncate; if the call succeeded
	I return its value, otherwise I update errno and return
	-1 */
	int rez = syscall(__NR_truncate, path, length);

	if (rez >= 0)
		return rez;
	errno = -rez;
	
	return -1;
}
