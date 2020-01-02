/*
** EPITECH PROJECT, 2019
** Libfox
** File description:
** Wrap cbreak to break it on demand
*/

#include <ncurses.h>

#include "fox_define.h"
#include "tests/wrappers/wrap_cbreak.h"

int __real_cbreak(void);
int __wrap_cbreak(void)
{
    if (cbreak_counter == 0)
        return ERR;
    cbreak_counter -= (cbreak_counter != -1);
    return __real_cbreak();
}

__Aconst short *__cbreak_counter(void)
{
    static short n = -1;

    return &n;
}

extern inline void fix_cbreak(void)
{
    cbreak_counter = -1;
}

extern inline void break_cbreak(void)
{
    cbreak_counter = 0;
}
