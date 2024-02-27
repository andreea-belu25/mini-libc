# Mini-libc

## Description

A **minimalistic** [**standard C library**](https://en.wikipedia.org/wiki/C_standard_library) implementation for Linux systems (named **mini-libc**), that can be used as a replacement for the **system libc** ([glibc](https://www.gnu.org/software/libc/) in Linux).
The goal is to have a minimally functional libc with features such as string management, basic memory support and POSIX file I/O.

The implementation of mini-libc will be **freestanding**, i.e. it will not use any outside library calls.
It will be implemented on top of the system call interface provided by Linux on an `x86_64` architecture.
Any function you require, that is typically part of libc, you will have to implement.
You can reuse functions that you implement in other parts of the mini-libc.

In case you are using a macOS device with ARM64 / Aarch64, you will have to install an `x86_64` virtual machine.

### API and Implementation Tasks

The application programming interface (API) of the C standard library is declared in a number of header files.
Each header file contains one or more function declarations, data type definitions and macros.
For your minimal implementation, the following header files are of interest:

- `<string.h>`: defines string-handling functions

  For this assignment, you will have to implement the following functions: `strcpy()`, `strcat()`, `strlen()`, `strncpy()`, `strncat()`, `strcmp()`, `strncmp()`, `strstr()`, `strrstr()`, `memcpy()`, `memset()`, `memmove()`, `memcmp()`.

- `<stdio.h>`: defines printing and I/O functions

  For this assignment, you will have to implement `puts()`.

- `<unistd.h>`, `<sys/fcntl.h>` and `<sys/stat.h>`: define I/O primitives

  For this assignment, you will have to implement the following functions: `open()`, `close()`, `lseek()`, `stat()`, `fstat()`, `truncate()`, `ftruncate()`.

  You will also have to implement the `nanosleep()` and `sleep()` functions.

- `<stdlib.h`> and `<sys/mman.h>` define memory allocation functions

  For this assignment, you will have to implement the following functions: `malloc()`, `free()`, `calloc()`, `realloc()`, `realloc_array()`, `mmap()`, `mremap()`, `munmap()`.

  For managing memory areas, a basic list structure is provided in `include/internal/mm/mem_list.h` and `mm/mem_list.c`.

- `<errno.h>` and `errno.c`: declare and define the integer variable `errno`, which is set by system calls and some library functions in the event of an error to indicate what went wrong.

## Resources

- [GNU libc manual](https://www.gnu.org/software/libc/manual/html_mono/libc.html)

- [musl implementation of the standard C library for Linux-based systems](https://elixir.bootlin.com/musl/latest/source)

- Syscall interface in Linux - [Linux man pages online](https://man7.org/linux/man-pages/index.html)

- [glibc implementation of the standard C library for Linux-based systems](https://elixir.bootlin.com/glibc/latest/source)
