/*
** EPITECH PROJECT, 2019
** Libfox
** File description:
** UT: Tree node creation
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "tests/wrap_malloc.h"
#include "fox_datastruct.h"

Test(tnode_create, regular_usage_no_null)
{
    tree_t tree = NULL;

    cr_assert_not(tree_create(&tree));
    cr_assert_not(tnode_create(&tree->trunk, &tree, tree));
    cr_assert_not_null(tree->trunk);
    cr_expect_eq(tree->nodes, 1);
    cr_expect_null(tree->trunk->lnext);
    cr_expect_null(tree->trunk->rnext);
    cr_expect_eq(tree->trunk->data, &tree);
    cr_expect_eq(tree->trunk->root, tree);
}

Test(tnode_create, regular_null_data)
{
    tree_t tree = NULL;

    cr_assert_not(tree_create(&tree));
    cr_assert_not(tnode_create(&tree->trunk, NULL, tree));
    cr_assert_not_null(tree->trunk);
    cr_expect_eq(tree->nodes, 1);
    cr_expect_null(tree->trunk->lnext);
    cr_expect_null(tree->trunk->rnext);
    cr_expect_null(tree->trunk->data);
    cr_expect_eq(tree->trunk->root, tree);
}

Test(tnode_create, regular_null_root)
{
    tree_t tree = NULL;

    cr_assert_not(tree_create(&tree));
    cr_assert_not(tnode_create(&tree->trunk, &tree, NULL));
    cr_assert_not_null(tree->trunk);
    cr_expect_null(tree->trunk->lnext);
    cr_expect_null(tree->trunk->rnext);
    cr_expect_eq(tree->trunk->data, &tree);
    cr_expect_null(tree->trunk->root);
}

Test(tnode_create, broken_malloc, .fini = fix_malloc)
{
    tree_t tree = NULL;

    cr_assert_not(tree_create(&tree));
    malloc_counter = 0;
    cr_expect(tnode_create(&tree->trunk, NULL, NULL));
}
