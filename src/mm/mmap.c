// SPDX-License-Identifier: BSD-3-Clause

#include <sys/mman.h>
#include <errno.h>
#include <internal/syscall.h>

void *mmap(void *addr, size_t length, int prot, int flags, int fd, off_t offset)
{
	/* TODO: Implement mmap(). */

	//  mmap -> rezerva o zona de memorie

	/* addr = adresa de start 
	   length = nr de bytes care trebuie mapati
	   prot = tipul accesului permis
	   flags = "nature of the map"
	   fd = file descriptor
	   offset = unde incepe fisierul care trebuie mapat */

	//  syscall-ul se executa asemanator ca la restul

	long rez = syscall(__NR_mmap, addr, length, prot, flags, fd, offset);

	if (rez >= 0)
		return (void *)rez;
	errno = -rez;
	return MAP_FAILED;
}

void *mremap(void *old_address, size_t old_size, size_t new_size, int flags)
{
	/* TODO: Implement mremap(). */

	//  mremap -> maparea unei adrese virtuale de memorie

	/*  old_address = adresa veche a zonei de memorie de extins
		old_size = vechea marime a memoriei virtuale
		new_size = noua marime dupa extindere */
	//  syscall-ul se face asemanator ca pana acum

	long rez = syscall(__NR_mremap, old_address, old_size, new_size, flags);

	if (rez >= 0)
		return (void*)rez;
	errno = -rez;
	return MAP_FAILED;
}

int munmap(void *addr, size_t length)
{
	/* TODO: Implement munmap(). */
	//  munmap -> stergerea unei zone de memorie mapata anterior

	/*  addr = adresa de start a zonei mapate
		length = lungimea zonei mapate */

	//  syscall asemanator ca pana acum
	long rez = syscall(__NR_munmap, addr, length);

	if (rez >= 0)
		return rez;
	errno = -rez;
	return -1;
}
