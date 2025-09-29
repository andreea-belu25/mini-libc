// SPDX-License-Identifier: BSD-3-Clause

#include <sys/mman.h>
#include <errno.h>
#include <internal/syscall.h>

void *mmap(void *addr, size_t length, int prot, int flags, int fd, off_t offset)
{
	// mmap -> reserves a memory region
	/* addr = start address 
	   length = number of bytes to be mapped
	   prot = type of access permitted
	   flags = "nature of the map"
	   fd = file descriptor
	   offset = where the file to be mapped starts */
	
	// The syscall executes similarly to the rest
	long rez = syscall(__NR_mmap, addr, length, prot, flags, fd, offset);
	
	if (rez >= 0)
		return (void *)rez;
	
	errno = -rez;
	return MAP_FAILED;
}

void *mremap(void *old_address, size_t old_size, size_t new_size, int flags)
{
	// mremap -> mapping of a virtual memory address
	/*  old_address = old address of the memory region to expand
		old_size = old size of virtual memory
		new_size = new size after expansion */
	
	// The syscall is done similarly as before
	long rez = syscall(__NR_mremap, old_address, old_size, new_size, flags);
	
	if (rez >= 0)
		return (void*)rez;
	
	errno = -rez;
	return MAP_FAILED;
}

int munmap(void *addr, size_t length)
{
	// munmap -> deletion of a previously mapped memory region
	/*  addr = start address of the mapped region
		length = length of the mapped region */
	
	// Syscall similar as before
	long rez = syscall(__NR_munmap, addr, length);
	
	if (rez >= 0)
		return rez;
	
	errno = -rez;
	
	return -1;
}
