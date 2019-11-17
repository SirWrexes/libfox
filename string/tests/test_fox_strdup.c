/*
** EPITECH PROJECT, 2019
** Libfox
** File description:
** UT: Duplicating a string
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "tests/wrap_malloc.h"
#include "fox_string.h"

Test(strdup, regular_usage)
{
    str_t s1 = "TZ da best";
    str_t s2 = fox_strdup(s1);

    cr_assert_not_null(s2);
    cr_expect_str_eq(s2, s1);
    free(s2);
}

Test(strdup, broken_malloc, .init = break_malloc, .fini = fix_malloc)
{
    str_t s1 = "Vriska cool too";
    str_t s2 = fox_strdup(s1);

    cr_assert_null(s2);
}
