/*
** (not) EPITECH PROJECT, 2021
** Libfox unit tests
** File description:
** UT: Print a number
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
