/*
** EPITECH PROJECT, 2019
** <project name> unit tests
** File description:
** test_fox_putunbr.c -- No description
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "fox_io.h"

Test(putunbr, regular_usage, .init = cr_redirect_stdout)
{
    cr_assert_eq(fox_putunbr(-0), 1);
    cr_assert_eq(fox_putunbr(123), 3);
    cr_expect_stdout_eq_str("0123");
}
