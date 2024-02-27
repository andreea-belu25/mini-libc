// SPDX-License-Identifier: BSD-3-Clause

#include <internal/syscall.h>
#include <errno.h>
#include <time.h>

int nanosleep(const struct timespec *t1, struct timespec *t2)
{
    // 	nanosleep face syscall-ul si sleep cheama nanosleep-ul

	// t1 si t2 imi ofera timpul pentru sleep al procesului
	/* apel de sistem nanosleep; daca apelul a reusit 
	ii returnez valoarea, altfel modific errno si returnez
	-1 */
    int rez = syscall(__NR_nanosleep, t1, t2);

    if (rez >= 0)
        return rez;

    errno = -rez;
    return -1;
}
