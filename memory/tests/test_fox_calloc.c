/*
** EPITECH PROJECT, 2019
** Libfox unit tests
** File description:
** UT: Array alloc & init
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "tests/fox_wrappers.h"

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
