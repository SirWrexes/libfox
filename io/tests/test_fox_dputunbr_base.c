/*
** EPITECH PROJECT, 2019
** Libfox
** File description:
** UT: Printing a number in given base
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "fox_io.h"

Test(putunbr_base, regular_usage, .init = cr_redirect_stdout)
{
    cr_expect_eq(fox_putunbr_base(23, "01"), 5);
    cr_expect_stdout_eq_str("10111");
}

Test(putunbr_base, print_zero, .init = cr_redirect_stdout)
{
    cr_expect_eq(fox_putunbr_base(0, "aeiou"), 1);
    cr_expect_stdout_eq_str("a");
}

Test(putunbr_base, invalid_base)
{
    cr_expect_eq(fox_putunbr_base(0, ""), -1);
    cr_expect_eq(fox_putunbr_base(0, "aa"), -1);
}
