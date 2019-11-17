/*
** EPITECH PROJECT, 2019
** Libfox
** File description:
** UT: Writing a char in octal in a new string
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "tests/wrap_malloc.h"
#include "fox_io.h"

Test(asputchar_oct, regular_usage)
{
    str_t res = NULL;

    cr_expect_eq(fox_asputchar_oct(&res, 023), 4);
    cr_expect_str_eq(res, "\\023");
}

Test(asputchar_oct, broken_malloc, .init = break_malloc, .fini = fix_malloc)
{
    str_t res = NULL;

    cr_expect_eq(fox_asputchar_oct(&res, 042), -1);
    cr_expect_null(res);
}
