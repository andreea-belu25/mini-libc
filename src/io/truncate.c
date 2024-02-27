// SPDX-License-Identifier: BSD-3-Clause

#include <unistd.h>
#include <internal/syscall.h>
#include <errno.h>
#include <internal/io.h>
#include <internal/types.h>

int truncate(const char *path, off_t length)
{
	/* TODO: Implement truncate(). */

	/* truncate -> redimensioneaza un fisier la o anumita dim
	   prin micsorare */

	//  path = calea fisierului de deschis, length = lung specifica
	/* apel de sistem truncate; daca apelul a reusit 
	ii returnez valoarea, altfel modific errno si returnez
	-1 */
	int rez = syscall(__NR_truncate, path, length);

	if (rez >= 0)
		return rez;
	errno = -rez;
	return -1;
}
