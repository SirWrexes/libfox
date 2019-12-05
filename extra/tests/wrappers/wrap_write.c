/*
** EPITECH PROJECT, 2019
** Libfox
** File description:
** Wrap write to break it on demand
*/

#include <errno.h>
#include <sys/types.h>

#include "fox_define.h"
#include "tests/wrappers/wrap_write.h"

ssize_t __real_write(int fd, void *buff, size_t n);
ssize_t __wrap_write(int fd, void *buff, size_t n)
{
    if (write_counter == 0) {
        errno = EBADF;
        return -1;
    }
    write_counter -= (write_counter != -1);
    return __real_write(fd, buff, n);
}

__Aconst short *__write_counter(void)
{
    static short n = -1;

    return &n;
}

extern inline void fix_write(void)
{
    write_counter = -1;
    errno = 0;
}

extern inline void break_write(void)
{
    write_counter = 0;
}
