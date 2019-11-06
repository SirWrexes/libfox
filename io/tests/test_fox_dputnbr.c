/*
** EPITECH PROJECT, 2019
** Libfox
** File description:
** UT: Writing numbers
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "fox_io.h"

Test(putnbr, regular_usage, .init = cr_redirect_stdout)
{
    cr_assert_eq(fox_putnbr(-0), 1);
    cr_assert_eq(fox_putnbr(123), 3);
    cr_assert_eq(fox_putnbr(-1), 2);
    cr_expect_stdout_eq_str("0123-1");
}
