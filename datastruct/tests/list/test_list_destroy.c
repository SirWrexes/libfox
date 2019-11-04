/*
** EPITECH PROJECT, 2019
** Libfox
** File description:
** UT: List destruction
*/

#include <malloc.h>
#include <criterion/criterion.h>
#include <criterion/redirect.h>

#include "datastruct/fox_list.h"

static void destructor(char ***s)
{
    free(**s);
    **s = NULL;
}

Test(list_destroy, nonnull_destructor)
{
    foxlist_t list = NULL;
    char *ref[] = {malloc(1), malloc(1), malloc(1)};

    cr_assert_not(list_create(&list));
    for (hindex_t i = 0; i < 3; i += 1)
        cr_assert_not(list_addnode(list, &ref[i]));
    list_destroy(&list, &destructor);
    cr_expect_null(list);
    for (hindex_t i = 0; i < 3; i += 1)
        cr_expect_null(ref[i]);
}

Test(list_destroy, null_destructor, .disabled = true)
{
    foxlist_t list = NULL;
    char *ref[] = {"malloc(1)", "malloc(1)", "malloc(1)"};

    cr_assert_not(list_create(&list));
    for (hindex_t i = 0; i < 3; i += 1)
        cr_assert_not(list_addnode(list, &ref[i]));
    list_destroy(&list, NULL);
    cr_expect_null(list);
}

Test(list_destroy, empty_list)
{
    foxlist_t list = NULL;

    cr_assert_not(list_create(&list));
    list_destroy(&list, NULL);
    cr_expect_null(list);
}

Test(list_destroy, null_list)
{
    foxlist_t list = NULL;

    list_destroy(&list, NULL);
    cr_assert(true);
}
