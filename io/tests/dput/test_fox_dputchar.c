/*
** (not) EPITECH PROJECT, 2021
** Libfox
** File description:
** UT: Write a single character
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "fox_io.h"

Test(putchar, regular_usage, .init = cr_redirect_stdout)
{
    cr_assert_eq(fox_putchar('c'), 1);
    cr_expect_stdout_eq_str("c");
}
