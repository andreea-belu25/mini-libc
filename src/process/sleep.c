// SPDX-License-Identifier: BSD-3-Clause

#include <time.h>
#include <errno.h>

unsigned int sleep(unsigned int seconds)
{
    //  declarare structuri t1 si t2 pentru apel la nanosleep
    struct timespec t1 = {seconds, 0};
    struct timespec t2 = {seconds, 0};
	// seconds = timpul de asteptare (sleep) al procesului
	/* apel de sistem sleep; daca apelul a reusit 
	ii returnez valoarea, altfel modific errno si returnez
	-1 */
    int rez = nanosleep(&t1, &t2);
    if (rez >= 0)
        return rez;
    errno = -rez;
    return -1;
}
