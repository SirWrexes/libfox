/*
** EPITECH PROJECT, 2019
** Libfox
** File description:
** UT: Wrap cbreak
*/

#include <ncurses.h>

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "tests/wrappers/wrap_cbreak.h"

Test(wrap_cbreak, regular_usage, .init = break_cbreak)
{
    cr_expect_eq(cbreak(), ERR);
    fix_cbreak();
    cr_expect_neq(cbreak(), ERR);
    nocbreak();
}
