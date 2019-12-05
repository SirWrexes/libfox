/*
** EPITECH PROJECT, 2019
** Libfox
** File description:
** Wrap initscr to break it on demand
*/

#include <errno.h>

#include "fox_define.h"
#include "tests/wrappers/wrap_initscr.h"

void *__real_initscr(size_t size);
void *__wrap_initscr(size_t size)
{
    if (initscr_counter == 0)
        return NULL;
    initscr_counter -= (initscr_counter != -1);
    return __real_initscr(size);
}

__Aconst short *__initscr_counter(void)
{
    static short n = -1;

    return &n;
}

extern inline void fix_initscr(void)
{
    initscr_counter = -1;
    errno = 0;
}

extern inline void break_initscr(void)
{
    initscr_counter = 0;
}
