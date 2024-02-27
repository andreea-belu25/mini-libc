// SPDX-License-Identifier: BSD-3-Clause

#include <unistd.h>
#include <internal/syscall.h>
#include <errno.h>
#include <internal/io.h>
#include <internal/types.h>

int ftruncate(int fd, off_t length)
{
	/* TODO: Implement ftruncate(). */
	// 	ftruncate -> redimensioneaza un fisier la o anumita dim
	//  fd = ce fisier sa deschida, length = lung specifica
	/* apel de sistem ftruncate; daca apelul a reusit 
	ii returnez valoarea, altfel modific errno si returnez
	-1 */
	int rez = syscall(__NR_ftruncate, fd, length);
	if (rez >= 0)
		return rez;
	errno = -rez;
	return -1;
}
