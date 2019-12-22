/*
** EPITECH PROJECT, 2019
** Libfox
** File description:
** UT: Wrap initscr
*/

#include <ncurses.h>

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "tests/wrappers/wrap_initscr.h"

Test(wrap_initscr, regular_usage, .init = break_initscr)
{
    cr_expect_null(initscr());
    fix_initscr();
    cr_expect_not_null(initscr());
}
