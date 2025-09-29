// SPDX-License-Identifier: BSD-3-Clause

#include <time.h>
#include <errno.h>

unsigned int sleep(unsigned int seconds)
{
	// Declare structures t1 and t2 for nanosleep call
	struct timespec t1 = {seconds, 0};
	struct timespec t2 = {seconds, 0};
	
	// seconds = the waiting time (sleep) of the process
	
	/* sleep system call; if the call succeeded
	   I return its value, otherwise I modify errno and return -1 */
	int rez = nanosleep(&t1, &t2);
	
	if (rez >= 0)
		return rez;
	
	errno = -rez;
	return -1;
}
