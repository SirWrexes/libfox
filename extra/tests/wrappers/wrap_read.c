/*
** EPITECH PROJECT, 2019
** Libfox
** File description:
** Wrap read to break it on demand
*/

#include <errno.h>
#include <sys/types.h>

#include "fox_define.h"
#include "tests/wrappers/wrap_read.h"

ssize_t __real_read(int fd, void *buff, size_t n);
ssize_t __wrap_read(int fd, void *buff, size_t n)
{
    if (read_counter == 0) {
        errno = EBADF;
        return -1;
    }
    read_counter -= (read_counter != -1);
    return __real_read(fd, buff, n);
}

__Aconst short *__read_counter(void)
{
    static short n = -1;

    return &n;
}

extern inline void fix_read(void)
{
    read_counter = -1;
    errno = 0;
}

extern inline void break_read(void)
{
    read_counter = 0;
}
