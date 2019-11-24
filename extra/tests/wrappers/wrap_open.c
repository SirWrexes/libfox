/*
** EPITECH PROJECT, 2019
** Libfox
** File description:
** Wrap open to break it on demand
*/

#include <errno.h>
#include <fcntl.h>

#include <criterion/criterion.h>

#include "tests/wrap_open.h"
#include "fox_define.h"

int real_open(str2c_t path);
int wrap_open(str2c_t path)
{
    if (open_counter == 0) {
        errno = ENOMEM;
        return -1;
    }
    open_counter -= (open_counter != -1);
    return real_open(path);
}

__a((const))
short *__open_counter(void)
{
    static short n = -1;

    return &n;
}

extern inline void fix_open(void)
{
    open_counter = -1;
    errno = 0;
}

extern inline void break_open(void)
{
    open_counter = 0;
}
