// SPDX-License-Identifier: BSD-3-Clause

#include <unistd.h>
#include <internal/syscall.h>
#include <stdarg.h>
#include <errno.h>

int close(int fd)
{
	/* TODO: Implement close(). */

	//  close -> inchidere fisier
	//  fd = ce fisier sa inchida
	/* apel de sistem close; daca apelul a reusit 
	ii returnez valoarea, altfel modific errno si returnez
	-1 */
	int rez = syscall(__NR_close, fd);

	if (rez >= 0)
		return rez;
	errno = -rez;
	return -1;
}
