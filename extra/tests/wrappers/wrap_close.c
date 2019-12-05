/*
** EPITECH PROJECT, 2019
** Libfox
** File description:
** Wrap Close to break it on demand
*/

#include <errno.h>
#include <fcntl.h>

#include "fox_define.h"
#include "tests/wrappers/wrap_close.h"

int __real_close(int fd);
int __wrap_close(int fd)
{
    if (close_counter == 0) {
        errno = EBADF;
        return -1;
    }
    close_counter -= (close_counter != -1);
    return __real_close(fd);
}

__Aconst short *__close_counter(void)
{
    static short n = -1;

    return &n;
}

extern inline void fix_close(void)
{
    close_counter = -1;
    errno = 0;
}

extern inline void break_close(void)
{
    close_counter = 0;
}
