/*
** EPITECH PROJECT, 2019
** Libfox
** File description:
** UT: List creation
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "tests/wrap_malloc.h"

#include "datastruct/fox_list.h"

Test(list_create, regular_usage)
{
    foxlist_t list = NULL;

    cr_assert_not(list_create(&list));
    cr_assert_not_null(list);
    cr_expect_null(list->head);
    cr_expect_null(list->tail);
    cr_expect_eq(list->nodes, 0);
}

Test(list_create, broken_malloc, .init = break_malloc, .fini = fix_malloc)
{
    foxlist_t list = NULL;

    cr_assert(list_create(&list));
    cr_assert_null(list);
}
