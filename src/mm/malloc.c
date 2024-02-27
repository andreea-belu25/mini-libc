// SPDX-License-Identifier: BSD-3-Clause

#include <internal/mm/mem_list.h>
#include <internal/types.h>
#include <internal/essentials.h>
#include <sys/mman.h>
#include <string.h>
#include <stdlib.h>

void *malloc(size_t size)
{
	/* TODO: Implement malloc(). */

	//  aloc zona pe care o vreau mapata si verific
	void *adr_start = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_ANONYMOUS | MAP_PRIVATE, -1, 0);
	if (!adr_start)
		return NULL;
	//  adaug zona de memorie mapata
	int rez = mem_list_add(adr_start, size);
	if (rez == 0)
		return adr_start;
	//  in caz ca a esuat alocarea => dezaloc ce am alocat si returnez NULL
	munmap(adr_start, size);
	return NULL;
}

void *calloc(size_t nmemb, size_t size)
{
	/* TODO: Implement calloc(). */
	//  aloc zona pe care o vreau mapata si verific
	void *adr_start = mmap(NULL, nmemb * size, PROT_READ | PROT_WRITE, MAP_ANONYMOUS | MAP_PRIVATE, -1, 0);
	if (!adr_start)
		return NULL;
	/*  adaug zona de memorie mapata si daca a reusit instr 
		=> initializez totul cu 0 */
	int rez = mem_list_add(adr_start, nmemb * size);
	if (rez == 0) {
		int index = 0;
		for (index = 0; index < (int)(nmemb * size); index++)
			*(char *)(adr_start + index) = 0;
		return adr_start;
	}

	//  in caz ca a esuat alocarea => dezaloc ce am alocat si returnez NULL
	munmap(adr_start, nmemb * size);
	return NULL;
}

void free(void *ptr)
{
	/* TODO: Implement free(). */

	//  verific daca zona pe care vreau sa o dezaloc se afla in lista
	struct mem_list *find = mem_list_find(ptr);
	if (find == NULL)
		return;
	//  dezalocarea continutului celulei
	int ok = munmap(ptr, find->len);
	if(ok == -1)
		return;

	//  stergerea intregii celule
	mem_list_del(ptr);
	return;
}

void *realloc(void *ptr, size_t size)
{
	/* TODO: Implement realloc(). */

	//  verific daca zona pe care vreau sa o dezaloc se afla in lista
	struct mem_list *find = mem_list_find(ptr);
	if (find == NULL)
		return NULL;
	//  aloc o noua zona de memorie
	void *pointer = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_ANONYMOUS | MAP_PRIVATE, -1, 0);
	if (!pointer)
		return NULL;

	//  copiez continutul zonei vechi in zona noua
	int index = 0;
	for (index = 0; index < (int)size; index++)
			*(char *)(pointer + index) = *(char *)ptr;

	//  dezalocare continut + stergere celula dupa ce nu mai am nevoie de zona veche
	int ok = munmap(ptr, find->len);
	if(ok == -1)
		return NULL;

	mem_list_del(ptr);

	//  adaug ce am alocat in lista
	int rez = mem_list_add(pointer, size);
	if (rez == 0)
		return pointer;
	return NULL;
}

void *reallocarray(void *ptr, size_t nmemb, size_t size)
{
	/* TODO: Implement reallocarray(). */

	/*  pasii sunt asemanatori cu cei de la realloc, singura diferenta
		constand in modificarea dimensiunii (size * nmemb) pentru arary*/

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
