// SPDX-License-Identifier: BSD-3-Clause

/* implementare biblioteca time.h
   utila pentru sleep si nanosleep */

/*  t1 = timp in secunde
    t2 = timp in nanosecunde */
struct timespec {
    long t1, t2;
};

int nanosleep(const struct timespec *t1, struct timespec *t2);
