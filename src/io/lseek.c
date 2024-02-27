// SPDX-License-Identifier: BSD-3-Clause

#include <unistd.h>
#include <internal/syscall.h>
#include <errno.h>
#include <internal/io.h>
#include <internal/types.h>

off_t lseek(int fd, off_t offset, int whence)
{
	/* TODO: Implement lseek(). */

	// 	lseek -> schimba locatia unui read/ write pointer a unui fisier

	/* fd = ce fisier sa deschida, 
	   offset = offset-ul pointer-ului masurat in bytes
	   whence = metoda de interpretare a offset-ului */
	/* apel de sistem lseek; daca apelul a reusit 
	ii returnez valoarea, altfel modific errno si returnez
	-1 */
	int rez = syscall(__NR_lseek, fd, offset, whence);
	if (rez >= 0)
		return rez;

	errno = -rez;
	return -1;
}
