/*
** (not) EPITECH PROJECT, 2021
** Libfox unit tests
** File description:
** UT: Reallocate a pointer
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

#include "tests/wrappers/wrap_malloc.h"

#include "fox_memory.h"

Test(realloc, new_pointer)
{
    size_t sz = 0;
    __smart void *p = fox_realloc_sz(NULL, NULL, sizeof(int));

    cr_assert_not_null(p);
    p = fox_realloc_sz(p, NULL, sizeof(int));
    cr_assert_not_null(p);
    free(p);
    p = fox_realloc_sz(NULL, &sz, sizeof(int));
}

Test(realloc, free)
{
    void *p = malloc(sizeof(int));

    cr_assert_not_null(p);
    cr_assert_null(fox_realloc_sz(p, NULL, 0));
}

Test(realloc, new_is_bigger)
{
    str_t s = "Glou glou miaou miaou jeej";
    str_t p = strdup(s);
    size_t oldsz = strlen(s) * sizeof(*s);
    size_t const newsz = oldsz * 2;

    cr_assert_not_null(p);
    cr_assert_str_eq(s, p);
    p = fox_realloc_sz(p, &oldsz, newsz);
    cr_expect_eq(oldsz, newsz);
    cr_expect_str_eq(p, s);
}

Test(realloc, new_is_smaller)
{
    str_t s = "Glou glou miaou miaou jeej";
    str_t p = strdup(s);
    size_t oldsz = strlen(s) * sizeof(*s);
    size_t const newsz = oldsz / 2;

    cr_assert_not_null(p);
    cr_assert_str_eq(s, p);
    p = fox_realloc_sz(p, &oldsz, newsz);
    cr_expect_eq(oldsz, newsz);
    cr_expect_arr_eq(p, s, newsz);
}

Test(realloc, broken_malloc, .init = break_malloc, .fini = fix_malloc)
{
    void *p = fox_realloc_sz(NULL, NULL, sizeof(int));

    cr_assert_null(p);
}
