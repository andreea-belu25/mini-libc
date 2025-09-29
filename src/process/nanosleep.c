// SPDX-License-Identifier: BSD-3-Clause

#include <internal/syscall.h>
#include <errno.h>
#include <time.h>

int nanosleep(const struct timespec *t1, struct timespec *t2)
{
	// nanosleep makes the syscall and sleep calls nanosleep
	// t1 and t2 provide the time for the process's sleep
	
	/* nanosleep system call; if the call succeeded
	   I return its value, otherwise I modify errno and return -1 */
	int rez = syscall(__NR_nanosleep, t1, t2);
	
	if (rez >= 0)
		return rez;
	
	errno = -rez;
	
	return -1;
}
