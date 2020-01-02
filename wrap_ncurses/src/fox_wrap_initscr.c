/*
** EPITECH PROJECT, 2019
** Libfox
** File description:
** Wrap initscr to break it on demand
*/

#include <ncurses.h>

#include "fox_define.h"
#include "tests/wrappers/wrap_initscr.h"

WINDOW *__real_initscr(void);
WINDOW *__wrap_initscr(void)
{
    if (initscr_counter == 0)
        return NULL;
    initscr_counter -= (initscr_counter != -1);
    return __real_initscr();
}

__Aconst short *__initscr_counter(void)
{
    static short n = -1;

    return &n;
}

extern inline void fix_initscr(void)
{
    initscr_counter = -1;
}

extern inline void break_initscr(void)
{
    initscr_counter = 0;
}
