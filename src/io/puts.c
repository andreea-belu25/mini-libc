// SPDX-License-Identifier: BSD-3-Clause

#include <stdio.h>
#include <internal/syscall.h>

int puts(const char *str) {
    /* *(str + index) -> caracter
        str + index -> adresa (pentru syscall imi trebuie adresa) */
    int index = 0;
    for (index = 0; *(str + index); index++)
    //  trebuie printat fiecare byte => syscall write
        syscall(1, 1, str + index, 1);

    syscall(1, 1, "\n", 1);
    //  puts returneaza by default 0 daca reuseste printarea
    return 0;
}
