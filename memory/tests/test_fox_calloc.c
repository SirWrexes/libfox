/*
** (not) EPITECH PROJECT, 2021
** Libfox
** File description:
** UT: Array allocation and initialisation
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "tests/wrappers/wrap_malloc.h"

#include "fox_memory.h"

Test(calloc, regular_usage)
{
    int ref[23] = {[0 ... 22] = 0};
    int *arr = NULL;

    arr = fox_calloc(sizeof(ref) / sizeof(*ref), sizeof(*arr));
    cr_assert_not_null(arr);
    cr_expect_arr_eq(arr, ref, sizeof(ref));
}

Test(calloc, broken_malloc, .init = break_malloc, .fini = fix_malloc)
{
    const uint sz = 23;
    int *arr = NULL;

    arr = fox_calloc(sz, sizeof(*arr));
    cr_assert_null(arr);
}
