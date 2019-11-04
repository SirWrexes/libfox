/*
** EPITECH PROJECT, 2019
** Libfox
** File description:
** UT: Adding a node to a list
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "tests/wrap_malloc.h"

#include "datastruct/fox_list.h"

Test(list_addnode, regular_usage)
{
    foxlist_t list = NULL;
    char *ref[] = {"ref0", "ref1"};

    cr_assert_not(list_create(&list));
    cr_assert_not(list_addnode(list, ref[0]));
    cr_assert_not_null(list->head);
    cr_assert_not_null(list->tail);
    cr_expect_eq(list->head, list->tail);
    cr_expect_eq(list->head->data, ref[0]);
    cr_expect_eq(list->nodes, 1);
    cr_assert_not(list_addnode(list, ref[1]));
    cr_expect_neq(list->head, list->tail);
    cr_expect_eq(list->tail->data, ref[1]);
    cr_expect_eq(list->nodes, 2);
}

Test(list_addnode, broken_malloc, .fini = fix_malloc)
{
    foxlist_t list = NULL;

    malloc_counter = 1;
    cr_assert_not(list_create(&list));
    cr_assert(list_addnode(list, &list));
    cr_expect_null(list->head);
    cr_expect_null(list->tail);
    cr_expect_eq(list->nodes, 0);
}
