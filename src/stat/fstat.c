// SPDX-License-Identifier: BSD-3-Clause

#include <sys/stat.h>
#include <internal/syscall.h>
#include <errno.h>

int fstat(int fd, struct stat *st)
{
	/* TODO: Implement fstat(). */
	//  fstat -> obtine informatie despre un fisier deschis
	/*  fd = file descriptor-ul asociat fisierului
		st = unde e retinuta informatia */

	//  syscall asemanator ca la restul
	int rez = syscall(__NR_fstat, fd, st);

	if (rez >= 0)
		return rez;
	errno = -rez;
	return -1;
}
