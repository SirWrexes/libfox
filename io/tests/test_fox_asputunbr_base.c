/*
** EPITECH PROJECT, 2019
** Libfox
** File description:
** UT: Printing an unsigned int in a new allocated string
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "tests/wrap_malloc.h"
#include "fox_io.h"

Test(asputunbr_base, regular_usage)
{
    str_t res = NULL;

    cr_expect_eq(fox_asputunbr_base(&res, 23, "01"), 5);
    cr_assert_not_null(res);
    cr_expect_str_eq(res, "10111");
}

Test(asputunbr_base, print_zero)
{
    str_t res = NULL;

    cr_expect_eq(fox_asputunbr_base(&res, 0, "aeiou"), 1);
    cr_assert_not_null(res);
    cr_expect_str_eq(res, "a");
}

Test(asputunbr_base, invalid_base)
{
    str_t res = NULL;

    cr_expect_eq(fox_asputunbr_base(&res, 0, ""), -1);
    cr_assert_null(res);
    cr_expect_eq(fox_asputunbr_base(&res, 0, "aa"), -1);
    cr_assert_null(res);
}

Test(asputunbr_base, broken_malloc, .init = break_malloc, .fini = fix_malloc)
{
    str_t res = NULL;

    cr_expect_eq(fox_asputunbr_base(&res, 42, "01"), -1);
    cr_expect_null(res);
}
