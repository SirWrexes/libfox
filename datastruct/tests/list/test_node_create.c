/*
** EPITECH PROJECT, 2019
** Libfox
** File description:
** UT: Node creation
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "tests/wrap_malloc.h"

#include "datastruct/fox_list.h"

Test(node_create, regular_usage)
{
    foxnode_t node = NULL;

    cr_assert_not(node_create(&node, &node));
    cr_assert_not_null(node);
    cr_expect_eq(node->i, 0);
    cr_expect_eq(node->data, &node);
    cr_expect_null(node->prev);
    cr_expect_null(node->next);
}

Test(node_create, broken_malloc, .init = break_malloc, .fini = fix_malloc)
{
    foxnode_t node = NULL;

    cr_assert(node_create(&node, &node));
    cr_assert_null(node);
}
