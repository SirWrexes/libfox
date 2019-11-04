/*
** EPITECH PROJECT, 2019
** <project name> unit tests
** File description:
** test_tnode_destroy.c -- No description
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "fox_datastruct.h"

static void destructor(char ***s)
{
    free(**s);
    **s = NULL;
}

Test(tnode_destroy, simple_destruction)
{
    foxtree_t tree = NULL;
    char *s = malloc(1);

    cr_assert_not_null(s);
    cr_assert_not(tree_create(&tree));
    cr_assert_not(tnode_create(&tree->trunk, &s, tree));
    cr_expect_eq(tree->nodes, 1);
    cr_assert_not_null(tree->trunk);
    tnode_destroy(&tree->trunk, &destructor);
    cr_expect_eq(tree->nodes, 0);
    cr_expect_null(tree->trunk);
    cr_expect_null(s);
    tnode_destroy(&tree->trunk, NULL);
    cr_assert(true);
}

Test(tnode_destroy, recursive_destruction)
{
    foxtree_t tree = NULL;
    char *s = malloc(1);

    cr_assert_not_null(s);
    cr_assert_not(tree_create(&tree));
    cr_assert_not(tnode_create(&tree->trunk, &s, tree));
    cr_assert_not(tnode_create(&tree->trunk->lnext, NULL, tree));
    cr_assert_not(tnode_create(&tree->trunk->rnext, NULL, tree));
    cr_expect_eq(tree->nodes, 3);
    cr_assert_not_null(tree->trunk);
    cr_assert_not_null(tree->trunk->rnext);
    cr_assert_not_null(tree->trunk->lnext);
    tnode_destroy(&tree->trunk, &destructor);
    cr_expect_eq(tree->nodes, 0);
    cr_expect_null(tree->trunk);
    cr_expect_null(s);
}

Test(tnode_destroy, extra_branch_testing)
{
    foxtree_t tree = NULL;

    cr_assert_not(tree_create(&tree));
    cr_assert_not(tnode_create(&tree->trunk, NULL, NULL));
    tnode_destroy(&tree->trunk, NULL);
}
