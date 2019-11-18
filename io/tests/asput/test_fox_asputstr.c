/*
** EPITECH PROJECT, 2019
** Libfox
** File description:
** UT: Writing a string to a newly allocated pointer
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "tests/wrap_malloc.h"
#include "fox_io.h"

Test(asputstr, regular_usage)
{
    str_t res = NULL;
    str_t ref = "Ptdr c presk le mem non";

    cr_expect_eq(fox_asputstr(&res, ref), (ssize_t) strlen(ref));
    cr_assert_not_null(res);
    cr_expect_str_eq(res, ref);
}

Test(asputstr, null_string)
{
    str_t res = NULL;
    str_t ref = "(null)";

    cr_expect_eq(fox_asputstr(&res, NULL), (ssize_t) strlen(ref));
    cr_assert_not_null(res);
    cr_expect_str_eq(res, ref);
}

Test(asputstr, broken_malloc, .init = break_malloc, .fini = fix_malloc)
{
    str_t res = NULL;

    cr_expect_eq(fox_asputstr(&res, "NULL"), -1);
    cr_expect_null(res);
}
