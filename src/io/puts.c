// SPDX-License-Identifier: BSD-3-Clause

#include <stdio.h>
#include <internal/syscall.h>

int puts(const char *str) {
    /* *(str + index) -> character
       str + index -> address (for syscall I need the address) */
    int index = 0;
    
    for (index = 0; *(str + index); index++)
        //  each byte must be printed => syscall write
        syscall(1, 1, str + index, 1);

    syscall(1, 1, "\n", 1);
    
    //  puts returns 0 by default if the printing succeeds
    return 0;
}
