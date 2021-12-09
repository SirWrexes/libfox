/*
** (not) EPITECH PROJECT, 2021
** Libfox
** File description:
** Wrap open to break it on demand
*/

#include <errno.h>
#include <fcntl.h>

#include "fox_define.h"
#include "fox_internal/foxi_wrapmacro.h"

#include "tests/wrappers/wrap_open.h"

Wrapper(int, open, str3c_t path)
{
    if (open_counter == 0) {
        errno = ENOENT;
        return -1;
    }
    open_counter -= (open_counter != -1);
    return __real_open(path);
}

__Aconst short *open_counter_location(void)
{
    static short n = -1;

    return &n;
}

__AalwaysILext void fix_open(void)
{
    open_counter = -1;
    errno = 0;
}

__AalwaysILext void break_open(void)
{
    open_counter = 0;
}
