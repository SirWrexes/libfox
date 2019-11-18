/*
** EPITECH PROJECT, 2019
** Libfox
** File description:
** UT: Allocate a string and print a char into it
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "tests/wrap_malloc.h"
#include "fox_io.h"

Test(asputchar, regular_usage)
{
    str_t res = NULL;

    cr_expect_eq(fox_asputchar(&res, 'c'), 1);
    cr_assert_not_null(res);
    cr_expect_str_eq(res, "c");
    free(res);
}

Test(asputchar, broken_malloc, .init = break_malloc, .fini = fix_malloc)
{
    str_t res = NULL;

    cr_expect_eq(fox_asputchar(&res, 'c'), -1);
    cr_expect_null(res);
}
