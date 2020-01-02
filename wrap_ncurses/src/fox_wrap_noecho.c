/*
** EPITECH PROJECT, 2019
** Libfox
** File description:
** Wrap noecho to break it on demand
*/

#include <ncurses.h>

#include "fox_define.h"
#include "tests/wrappers/wrap_noecho.h"

int __real_noecho(void);
int __wrap_noecho(void)
{
    if (noecho_counter == 0)
        return ERR;
    noecho_counter -= (noecho_counter != -1);
    return __real_noecho();
}

__a((const)) short *__noecho_counter(void)
{
    static short n = -1;

    return &n;
}

extern inline void fix_noecho(void)
{
    noecho_counter = -1;
}

extern inline void break_noecho(void)
{
    noecho_counter = 0;
}
