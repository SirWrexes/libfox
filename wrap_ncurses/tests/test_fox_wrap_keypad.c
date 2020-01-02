/*
** EPITECH PROJECT, 2019
** Libfox
** File description:
** UT: Wrap keypad
*/

#include <ncurses.h>

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "tests/wrappers/wrap_keypad.h"

Test(wrap_keypad, regular_usage, .init = break_keypad)
{
    WINDOW *scr = initscr();

    cr_assert_not_null(scr);
    cr_expect_eq(keypad(scr, true), ERR);
    fix_keypad();
    cr_expect_neq(keypad(scr, true), ERR);
}
