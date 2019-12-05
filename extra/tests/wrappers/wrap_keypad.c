/*
** EPITECH PROJECT, 2019
** Libfox
** File description:
** Wrap keypad to break it on demand
*/

#include <ncurses.h>

#include "fox_define.h"
#include "tests/wrappers/wrap_keypad.h"

int __real_keypad(WINDOW *window, bool bf);
int __wrap_keypad(WINDOW *window, bool bf)
{
    if (keypad_counter == 0)
        return ERR;
    keypad_counter -= (keypad_counter != -1);
    return __real_keypad(window, bf);
}

__Aconst short *__keypad_counter(void)
{
    static short n = -1;

    return &n;
}

extern inline void fix_keypad(void)
{
    keypad_counter = -1;
}

extern inline void break_keypad(void)
{
    keypad_counter = 0;
}
