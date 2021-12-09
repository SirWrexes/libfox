/*
** (not) EPITECH PROJECT, 2021
** Libfox
** File description:
** UT: list smart pointer
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

#include "fox_list.h"

Test(autolist, regular_usage)
{
    autofoxlist_t list = NULL;

    list_create(&list);
    cr_assert(true);
}
