/*
** EPITECH PROJECT, 2019
** Libfox
** File description:
** UT: Writing numbers to a new string
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "tests/wrap_malloc.h"
#include "fox_io.h"

Test(asputnbr, negative_zero)
{
    str_t res = NULL;

    cr_assert_eq(fox_asputnbr(&res, -0), 1);
    cr_assert_not_null(res);
    cr_expect_str_eq(res, "0");
    free(res);
}

Test(asputnbr, regular_usage_pos)
{
    str_t res = NULL;

    cr_assert_eq(fox_asputnbr(&res, 123), 3);
    cr_assert_not_null(res);
    cr_expect_str_eq(res, "123");
    free(res);
}

Test(asputnbr, regular_usage_neg)
{
    str_t res = NULL;

    cr_assert_eq(fox_asputnbr(&res, -1), 2);
    cr_assert_not_null(res);
    cr_expect_str_eq(res, "-1");
    free(res);
}

Test(asputnbr, broken_malloc, .init = break_malloc, .fini = fix_malloc)
{
    str_t res = NULL;

    cr_assert_eq(fox_asputnbr(&res, 23), -1);
    cr_expect_null(res);
}
