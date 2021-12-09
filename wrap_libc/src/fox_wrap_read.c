/*
** (not) EPITECH PROJECT, 2021
** Libfox
** File description:
** Wrap read to break it on demand
*/

#include <errno.h>
#include <sys/types.h>

#include "fox_define.h"
#include "fox_internal/foxi_wrapmacro.h"

#include "tests/wrappers/wrap_read.h"

Wrapper(ssize_t, read, int fd, void *buff, size_t n)
{
    if (read_counter == 0) {
        errno = EBADF;
        return -1;
    }
    read_counter -= (read_counter != -1);
    return __real_read(fd, buff, n);
}

__Aconst short *read_counter_location(void)
{
    static short n = -1;

    return &n;
}

__AalwaysILext void fix_read(void)
{
    read_counter = -1;
    errno = 0;
}

__AalwaysILext void break_read(void)
{
    read_counter = 0;
}
