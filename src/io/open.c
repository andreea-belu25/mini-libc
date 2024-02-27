// SPDX-License-Identifier: BSD-3-Clause

#include <fcntl.h>
#include <internal/syscall.h>
#include <stdarg.h>
#include <errno.h>

int open(const char *filename, int flags, ...)
{
	/* TODO: Implement open system call. */
	/* lista variabila de argumente pentru modurile 
	posibile de deschidere a fisierului */
	va_list valist;
	va_start(valist, flags);
	int a = va_arg(valist, int);
	va_end(valist);

	// 	open -> deschidere fisier

	/* filename = ce fisier sa deschida, 
	   flags = permisiunile fisierului
	   ... -> lista variabila de argumente */
	/* apel de sistem open; daca apelul a reusit 
	ii returnez valoarea, altfel modific errno si returnez
	-1 */

	int rez = syscall(__NR_open, filename, flags, a);
	if (rez >= 0)
		return rez;

	errno = -rez;
	return -1;
}
