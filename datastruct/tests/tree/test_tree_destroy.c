/*
** (not) EPITECH PROJECT, 2021
** Libfox
** File description:
** UT: Destroy a tree
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <stdbool.h>
#include "fox_datastruct.h"

Test(tree_destroy, regular_usage)
{
    foxtree_t tree = NULL;

    cr_expect_not(tree_create(&tree));
    cr_assert_not_null(tree);
    tree_destroy(&tree, NULL);
    cr_expect_null(tree);
}

Test(tree_destroy, null_tree)
{
    foxtree_t tree = NULL;

    tree_destroy(&tree, NULL);
    cr_assert(true);
}
