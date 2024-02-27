// SPDX-License-Identifier: BSD-3-Clause

#include <sys/stat.h>
#include <internal/syscall.h>
#include <fcntl.h>
#include <errno.h>

int stat(const char *restrict path, struct stat *restrict buf)
{
	/* TODO: Implement stat(). */

	//  stat -> ofera informatie despre un file si filesystem

	/*  path = path-ul fisierului despre care vreau sa aflu inf
		buf =  unde sunt retinute info */

	//  syscall asemanator ca la restul

	int rez = syscall(__NR_stat, path, buf);

	if (rez >= 0)
		return rez;
	errno = -rez;
	return -1;
}
