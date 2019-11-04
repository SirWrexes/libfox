/*
** EPITECH PROJECT, 2019
** Libfox
** File description:
** UT: Node destruction
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <string.h>

#include "datastruct/fox_list.h"

static void destructor(char ***s)
{
    free(**s);
    **s = NULL;
}

Test(node_destroy, null_destructor)
{
    foxnode_t node = NULL;
    char *s = "Je suis fatigué.";

    cr_assert_not(node_create(&node, &s));
    node_destroy(&node, NULL);
    cr_expect_null(node);
}

Test(node_destroy, nonnull_destructor)
{
    foxnode_t node = NULL;
    char *s = strdup("J'ai besoin d'un café.");

    cr_assert_not(node_create(&node, &s));
    node_destroy(&node, &destructor);
    cr_expect_null(node);
    cr_expect_null(s);
    cr_assert_not(node_create(&node, &s));
    node->data = NULL;
    node_destroy(&node, &destructor);
    cr_assert(true);
}

Test(node_destroy, null_node)
{
    foxnode_t node = NULL;

    node_destroy(&node, NULL);
    cr_assert(true);
}
