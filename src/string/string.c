// SPDX-License-Identifier: BSD-3-Clause

#include <string.h>

char *strcpy(char *destination, const char *source)
{
	/* TODO: Implement strcpy(). */

	//  copiez sirul sursa in sirul destinatie
	int index = 0;

	for (index = 0; *(source + index); index++)
		*(destination + index) = *(source + index);
	*(destination + index) = '\0';

	return destination;
}

char *strncpy(char *destination, const char *source, size_t len)
{
	/* TODO: Implement strncpy(). */

	//  copiez len caracterere din sirul sursa in sirul destinatie
	int index = 0;

	for (index = 0; index < (int)len; index++)
		*(destination + index) = *(source + index);

	return destination;
}

char *strcat(char *destination, const char *source)
{
	/* TODO: Implement strcat(). */

	// determin lungimea sirului destinatie
    int lung_string = 0, index = 0;
	for (index = 0; *(destination + index); index++)
		lung_string++;

	// concatenez sirul sursa la sirul destinatie
	for (index = 0; *(source + index); index++)
		*(destination + lung_string + index) = *(source + index);
	*(destination + lung_string + index) = '\0';

	return destination;
}

char *strncat(char *destination, const char *source, size_t len)
{
	/* TODO: Implement strncat(). */
	// determin lungimea sirului destinatie
	int lung_string = 0, index = 0;
	for (index = 0; *(destination + index); index++)
		lung_string++;
	// concatenez len caractere din sirul sursa la sirul destinatie
	for (index = 0; index < (int)len; index++)
		*(destination + lung_string + index) = *(source + index);
	*(destination + lung_string + index) = '\0';

	return destination;
}

int strcmp(const char *str1, const char *str2)
{
	/* TODO: Implement strcmp(). */

	int lung_str1 = 0, index = 0;

	//  determin lungimea primului sir
	for (index = 0; *(str1 + index); index++)
		lung_str1++;
	//  determin lungimea sirului 2
	int lung_str2 = 0;
	for (index = 0; *(str2 + index); index++)
		lung_str2++;
	/* lung maxima dintre siruri pentru parcurgerea 
	completa a ambelor siruri */
	int lung_max = 0;
	if (lung_str1 > lung_str2)
		lung_max = lung_str1;
	else
		lung_max = lung_str2;
	//  compar cele doua siruri dpdv lexicografic
	for (index = 0; index < lung_max ; index++) {
		if (*(str1 + index) > *(str2 + index))
			return 1;
		if (*(str1 + index) < *(str2 + index))
			return -1;
	}
	return 0;
}

int strncmp(const char *str1, const char *str2, size_t len)
{
	/* TODO: Implement strncmp(). */

	/* compar cele doua siruri dpdv lexicografic cat timp 
	nu am parcurs len caractere */  
	int index = 0;
		for (index = 0; index < (int)len ; index++) {
		if (*(str1 + index) > *(str2 + index))
			return 1;
		if (*(str1 + index) < *(str2 + index))
			return -1;
	}
	return 0;
}

size_t strlen(const char *str)
{
	size_t i = 0;

	for (; *str != '\0'; str++, i++)
		;

	return i;
}

char *strchr(const char *str, int c)
{
	/* TODO: Implement strchr(). */

	/* caut caracterul c in sirul str si returnez adresa
	unde am gasit caracterul in sir */
	int index = 0;
	/* cast pentru ca primeam warning daca adunam 
	la ceva constant un intreg */
	char *source = (char *)str;
	for (index = 0; *(source + index); index++) {
		if (*(source + index) == (char)c)
			return source + index;
	}
	return NULL;
}

char *strrchr(const char *str, int c)
{
	/* TODO: Implement strrchr(). */
	// ultima pozitie a caracterului c in string (daca exista)

	int index = 0, lung_string = 0;
	char *string = (char*) str;
	for (index = 0; *(string + index); index++)
		lung_string++;
	//  parcurg sirul in sens invers
	for (index = lung_string - 1; index >= 0; index--)
		if (*(string + index) == (char)c)
			return string + index;
	return NULL;
}

char *strstr(const char *haystack, const char *needle)
{
	/* TODO: Implement strstr(). */

	//  contor in haystack
	int index_0 = 0;
	//  contor in needle
	int index_1 = 0;
	//  cate caratere consec din needle se gasesc in haystack
	int equal_characters = 0;
	//  cast pentru a putea intoarce o expresie aritmetica
	char *needle_found = NULL, *h_stack = (char*)haystack, *ned = (char *)needle;

	while (*(h_stack + index_0) && *(ned + index_1)) {
		if (*(ned + index_1) == *(h_stack + index_0)) {
			index_0++;
			index_1++;
			equal_characters++;  //  nr de caractere egale consecutive
			//  adresa de inceput a sirului needle in sirul haystack
			needle_found = h_stack + index_0;
		} else {
			index_0++;
			//  reinitializez pozitia in needle si nr de caractere egale
			index_1 = 0;
			equal_characters = 0;
		}
	}

	int lung_needle = 0;
	for (index_1 = 0; *(ned + index_1); index_1++)
		lung_needle++;
	/*  daca am intalnit tot sirul needle in sirul haystack 
	=> returnez adresa, altfel NULL  */
	if (equal_characters == lung_needle)
		return needle_found - equal_characters;
	return NULL;
}

char *strrstr(const char *haystack, const char *needle)
{
	/* TODO: Implement strrstr(). */
	/* implementare asemanatoare cu strstr, 
	dar parcurg sirul in sens invers */

	int lung_needle = 0;
	int index_1 = 0;  //  contor in needle
	for (index_1 = 0; *(needle + index_1); index_1++)
		lung_needle++;
	int lung_haystack = 0;
	int index_0 = 0;  //  contor in haystack
	for(index_0 = 0; *(haystack + index_0); index_0++)
		lung_haystack++;
	int equal_characters = 0;
	char *needle_found = NULL, *h_stack = (char *)haystack, *ned = (char *)needle;
	index_0 = lung_haystack - 1;
	index_1 = lung_needle - 1;


	while (index_0 >= 0 && index_1 >= 0) {
		if (*(ned + index_1) == *(h_stack + index_0)) {
			index_1--;
			index_0--;
			equal_characters++;
			needle_found = h_stack + index_0 + 1;
		} else {
			index_0--;
			index_1 = lung_needle - 1;
			equal_characters = 0;
		}
	}
	if (equal_characters == lung_needle)
		return needle_found;
	return NULL;
}

void *memcpy(void *destination, const void *source, size_t num)
{
	/* TODO: Implement memcpy(). */
	/* copiez num biti din blocul de mem al lui source in cel al lui destination
      fara buffer auxiliar */

	//  acelasi motiv pentru castare
	char *dst = (char*) destination, *src = (char*) source;

	int index = 0;
	while (index < (int)num) {
		*(dst + index) = *(src + index);
		index++;
	}

	return dst;
}

void *memmove(void *destination, const void *source, size_t num)
{
	/* TODO: Implement memmove(). */
	//  copiez num biti din source in destination cu un buffer auxiliar

	char *dst = (char *) destination, *src = (char*) source;
	const int kNum = (int)num;
	char aux[kNum];
	int index = 0;
	while (index < (int)num) {
		*(aux + index) = *(src + index);
		index++;
	}

	index = 0;
	while(index < (int)num) {
		*(dst + index) = *(aux + index);
		index++;
	}

	return dst;
}

int memcmp(const void *ptr1, const void *ptr2, size_t num)
{
	/* TODO: Implement memcmp(). */
	/* < 0 => primul byte are o val mai mica in ptr1 daca in ptr2
	   > 0 => primul byte are o val mai mare in ptr1 daca in ptr2
	   = 0 => toti bitii sunt egali in ambele siruri*/

	char *string1 = (char*)ptr1, *string2 = (char*)ptr2;
	/* parcurg byte cu byte si returnez o valoare in fct de 
	cazurile de mai sus */
	int index = 0;
	for (index = 0; index < (int)num; index++) {
		if (*(string1 + index) > *(string2 + index))
			return 1;
		if (*(string1 + index) < *(string2 + index))
			return -1;
	}
	return 0;
}

void *memset(void *source, int value, size_t num)
{
	/* TODO: Implement memset(). */
	// setez primii num biti din source cu value

	char *src = (char *)source;
	int index = 0;

	for (index = 0; index < (int)num; index++)
		*(src + index) = (char)value;

	return src;
}
