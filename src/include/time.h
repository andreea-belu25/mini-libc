// SPDX-License-Identifier: BSD-3-Clause

/* implement time.h library
   useful for sleep and nanosleep */

/*  t1 = time in seconds
    t2 = time in nanoseconds */
struct timespec {
    long t1, t2;
};

int nanosleep(const struct timespec *t1, struct timespec *t2);
