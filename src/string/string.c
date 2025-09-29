// SPDX-License-Identifier: BSD-3-Clause

#include <string.h>

char *strcpy(char *destination, const char *source)
{
	// Copy the source string to the destination string
	int index = 0;

	for (index = 0; *(source + index); index++)
		*(destination + index) = *(source + index);
	
	*(destination + index) = '\0';

	return destination;
}

char *strncpy(char *destination, const char *source, size_t len)
{
	// Copy len characters from the source string to the destination string
	int index = 0;

	for (index = 0; index < (int)len; index++)
		*(destination + index) = *(source + index);

	return destination;
}

char *strcat(char *destination, const char *source)
{
	// Determine the length of the destination string
	int lung_string = 0, index = 0;
	
	for (index = 0; *(destination + index); index++)
		lung_string++;

	// Concatenate the source string to the destination string
	for (index = 0; *(source + index); index++)
		*(destination + lung_string + index) = *(source + index);
	
	*(destination + lung_string + index) = '\0';

	return destination;
}

char *strncat(char *destination, const char *source, size_t len)
{
	// Determine the length of the destination string
	int lung_string = 0, index = 0;
	
	for (index = 0; *(destination + index); index++)
		lung_string++;
	
	// Concatenate len characters from the source string to the destination string
	for (index = 0; index < (int)len; index++)
		*(destination + lung_string + index) = *(source + index);
	
	*(destination + lung_string + index) = '\0';

	return destination;
}

int strcmp(const char *str1, const char *str2)
{
	int lung_str1 = 0, index = 0;

	// Determine the length of the first string
	for (index = 0; *(str1 + index); index++)
		lung_str1++;
	
	// Determine the length of string 2
	int lung_str2 = 0;
	
	for (index = 0; *(str2 + index); index++)
		lung_str2++;
	
	/* Maximum length between strings for complete traversal 
	   of both strings */
	int lung_max = 0;
	
	if (lung_str1 > lung_str2)
		lung_max = lung_str1;
	else
		lung_max = lung_str2;
	
	// Compare the two strings lexicographically
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
	/* Compare the two strings lexicographically while 
	   I haven't traversed len characters */
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
	/* Search for character c in string str and return the address
	   where I found the character in the string */
	int index = 0;
	
	/* Cast because I was getting a warning if adding 
	   an integer to something constant */
	char *source = (char *)str;
	
	for (index = 0; *(source + index); index++) {
		if (*(source + index) == (char)c)
			return source + index;
	}
	
	return NULL;
}

char *strrchr(const char *str, int c)
{
	// Last position of character c in string (if it exists)
	int index = 0, lung_string = 0;
	char *string = (char*) str;
	
	for (index = 0; *(string + index); index++)
		lung_string++;
	
	// Traverse the string in reverse
	for (index = lung_string - 1; index >= 0; index--)
		if (*(string + index) == (char)c)
			return string + index;
	
	return NULL;
}

char *strstr(const char *haystack, const char *needle)
{
	// Counter in haystack
	int index_0 = 0;
	
	// Counter in needle
	int index_1 = 0;
	
	// How many consecutive characters from needle are found in haystack
	int equal_characters = 0;
	
	// Cast to be able to return an arithmetic expression
	char *needle_found = NULL, *h_stack = (char*)haystack, *ned = (char *)needle;

	while (*(h_stack + index_0) && *(ned + index_1)) {
		if (*(ned + index_1) == *(h_stack + index_0)) {
			index_0++;
			index_1++;
			equal_characters++;  // Number of consecutive equal characters
			
			// Start address of the needle string in the haystack string
			needle_found = h_stack + index_0;
		} else {
			index_0++;
			
			// Reinitialize the position in needle and the number of equal characters
			index_1 = 0;
			equal_characters = 0;
		}
	}

	int lung_needle = 0;
	
	for (index_1 = 0; *(ned + index_1); index_1++)
		lung_needle++;
	
	/* If I encountered the entire needle string in the haystack string 
	   => return the address, otherwise NULL */
	if (equal_characters == lung_needle)
		return needle_found - equal_characters;
	
	return NULL;
}

char *strrstr(const char *haystack, const char *needle)
{
	/* Implementation similar to strstr, 
	   but traverse the string in reverse */
	int lung_needle = 0;
	int index_1 = 0;  // Counter in needle
	
	for (index_1 = 0; *(needle + index_1); index_1++)
		lung_needle++;
	
	int lung_haystack = 0;
	int index_0 = 0;  // Counter in haystack
	
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
	/* Copy num bytes from the memory block of source to that of destination
	   without auxiliary buffer */
	
	// Same reason for casting
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
	// Copy num bytes from source to destination with an auxiliary buffer
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
	/* < 0 => the first byte has a smaller value in ptr1 than in ptr2
	   > 0 => the first byte has a larger value in ptr1 than in ptr2
	   = 0 => all bytes are equal in both strings */
	
	char *string1 = (char*)ptr1, *string2 = (char*)ptr2;
	
	/* Traverse byte by byte and return a value according to 
	   the cases above */
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
	// Set the first num bytes from source with value
	char *src = (char *)source;
	int index = 0;

	for (index = 0; index < (int)num; index++)
		*(src + index) = (char)value;

	return src;
}
