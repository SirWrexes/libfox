/*
** EPITECH PROJECT, 2019
** <project name> unit tests
** File description:
** test_fox_dputstr.c -- No description
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <string.h>
#include "fox_io.h"

static void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(putstr, regular_usage, .init = redirect_all_std)
{
    str_t s = "MIIIIIIIIICKEY MOUSE";

    cr_assert_eq(fox_putstr(s), (ssize_t) strlen(s));
    cr_expect_stdout_eq_str(s);
    cr_assert_eq(fox_eputstr(s), (ssize_t) strlen(s));
    cr_expect_stderr_eq_str(s);
}

Test(putstr, null_string, .init = redirect_all_std)
{
    str_t s = NULL;

    cr_assert_eq(fox_putstr(s), 6);
    cr_expect_stdout_eq_str("(null)");
    cr_assert_eq(fox_eputstr(s), 6);
    cr_expect_stderr_eq_str("(null)");
}
