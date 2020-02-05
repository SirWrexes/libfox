/*
** EPITECH PROJECT, 2019
** Libfox
** File description:
** Wrap write to break it on demand
*/

#include <errno.h>
#include <sys/types.h>

#include "fox_define.h"
#include "fox_internal/foxi_wrapmacro.h"

#include "tests/wrappers/wrap_write.h"

Wrapper(ssize_t, write, int fd, void *buff, size_t n)
{
    if (write_counter == 0) {
        errno = EBADF;
        return -1;
    }
    write_counter -= (write_counter != -1);
    return __real_write(fd, buff, n);
}

__Aconst short *write_counter_location(void)
{
    static short n = -1;

    return &n;
}

__AalwaysILext void fix_write(void)
{
    write_counter = -1;
    errno = 0;
}

__AalwaysILext void break_write(void)
{
    write_counter = 0;
}
