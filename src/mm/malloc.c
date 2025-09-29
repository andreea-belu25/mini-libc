// SPDX-License-Identifier: BSD-3-Clause
#include <internal/mm/mem_list.h>
#include <internal/types.h>
#include <internal/essentials.h>
#include <sys/mman.h>
#include <string.h>
#include <stdlib.h>

void *malloc(size_t size)
{
	// Allocate the memory region I want mapped and verify
	void *adr_start = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_ANONYMOUS | MAP_PRIVATE, -1, 0);
	
	if (!adr_start)
		return NULL;
	
	// Add the mapped memory region
	int rez = mem_list_add(adr_start, size);
	
	if (rez == 0)
		return adr_start;
	
	// If allocation failed => deallocate what I allocated and return NULL
	munmap(adr_start, size);
	return NULL;
}

void *calloc(size_t nmemb, size_t size)
{
	// Allocate the memory region I want mapped and verify
	void *adr_start = mmap(NULL, nmemb * size, PROT_READ | PROT_WRITE, MAP_ANONYMOUS | MAP_PRIVATE, -1, 0);
	
	if (!adr_start)
		return NULL;
	
	/* Add the mapped memory region and if instruction succeeded
	   => initialize everything with 0 */
	int rez = mem_list_add(adr_start, nmemb * size);
	
	if (rez == 0) {
		int index = 0;
		
		for (index = 0; index < (int)(nmemb * size); index++)
			*(char *)(adr_start + index) = 0;
		
		return adr_start;
	}
	
	// If allocation failed => deallocate what I allocated and return NULL
	munmap(adr_start, nmemb * size);
	return NULL;
}

void free(void *ptr)
{
	// Check if the region I want to deallocate is in the list
	struct mem_list *find = mem_list_find(ptr);
	
	if (find == NULL)
		return;
	
	// Deallocating the cell's content
	int ok = munmap(ptr, find->len);
	
	if(ok == -1)
		return;
	
	// Deleting the entire cell
	mem_list_del(ptr);
	return;
}

void *realloc(void *ptr, size_t size)
{
	// Check if the region I want to deallocate is in the list
	struct mem_list *find = mem_list_find(ptr);
	
	if (find == NULL)
		return NULL;
	
	// Allocate a new memory region
	void *pointer = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_ANONYMOUS | MAP_PRIVATE, -1, 0);
	
	if (!pointer)
		return NULL;
	
	// Copy the content of the old region to the new region
	int index = 0;
	
	for (index = 0; index < (int)size; index++)
			*(char *)(pointer + index) = *(char *)ptr;
	
	// Deallocate content + delete cell after I no longer need the old region
	int ok = munmap(ptr, find->len);
	
	if(ok == -1)
		return NULL;
	
	mem_list_del(ptr);
	
	// Add what I allocated to the list
	int rez = mem_list_add(pointer, size);
	
	if (rez == 0)
		return pointer;
	
	return NULL;
}

void *reallocarray(void *ptr, size_t nmemb, size_t size)
{
	/* The steps are similar to those from realloc, the only difference
	   being the modification of the size (size * nmemb) for array */
	struct mem_list *find = mem_list_find(ptr);
	
	if (find == NULL)
		return NULL;
	
	void *pointer = mmap(NULL, size * nmemb, PROT_READ | PROT_WRITE, MAP_ANONYMOUS | MAP_PRIVATE, -1, 0);
	
	if (!pointer)
		return NULL;
	
	int index = 0;
	
	for (index = 0; index < (int)(nmemb * size); index++)
			*(char *)(pointer + index) = *(char *)(ptr + index);
	
	int ok = munmap(ptr, find->len);
	
	if(ok == -1)
		return NULL;
	
	mem_list_del(ptr);
	
	int rez = mem_list_add(pointer, size * nmemb);
	
	if (rez == 0)
		return pointer;
	
	return NULL;
}
