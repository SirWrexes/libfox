/*
** (not) EPITECH PROJECT, 2021
** Libfox
** File description:
** Wrap close to break it on demand
*/

#include <errno.h>
#include <unistd.h>

#include "fox_define.h"
#include "fox_internal/foxi_wrapmacro.h"

#include "tests/wrappers/wrap_close.h"

Wrapper(int, close, int fd)
{
    if (close_counter == 0) {
        errno = EBADF;
        return -1;
    }
    close_counter -= (close_counter != -1);
    return __real_close(fd);
}

__Aconst short *close_counter_location(void)
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
