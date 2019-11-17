/*
** EPITECH PROJECT, 2019
** Libfox
** File description:
** UT: Writing numbers
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "tests/wrap_malloc.h"
#include "fox_io.h"

Test(asputunbr, zero)
{
    str_t res = NULL;

    cr_assert_eq(fox_asputunbr(&res, 0), 1);
    cr_assert_not_null(res);
    cr_expect_str_eq(res, "0");
    free(res);
}

Test(asputunbr, regular_usage)
{
    str_t res = NULL;

    cr_assert_eq(fox_asputunbr(&res, 123), 3);
    cr_assert_not_null(res);
    cr_expect_str_eq(res, "123");
    free(res);
}

Test(asputunbr, broken_malloc, .init = break_malloc, .fini = fix_malloc)
{
    str_t res = NULL;

    cr_assert_eq(fox_asputunbr(&res, 23), -1);
    cr_expect_null(res);
}
