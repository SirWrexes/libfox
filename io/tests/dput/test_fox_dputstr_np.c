/*
** EPITECH PROJECT, 2019
** Libfox
** File description:
** UT: Printing a string including no printables in \xxx form
*/

#include <stdio.h>
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "fox_io.h"

Test(putstr_np, regular_usage, .init = cr_redirect_stdout)
{
    char str[] = {12, 148, 's', 'u', 'p', 'e', 'r', 0177, 85, '\n', 0};
    char ref[] = {[0 ... 30] = '\0'};

    cr_expect_eq(
        sprintf(ref, "\\%03o\\%03osuper\\177U\n", 12, 148), fox_putstr_np(str));
    cr_expect_stdout_eq_str(ref);
}

Test(putstr_np, null_string, .init = cr_redirect_stdout)
{
    cr_expect_eq(fox_putstr_np(NULL), 6);
    cr_expect_stdout_eq_str("(null)");
}
