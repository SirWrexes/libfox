/*
** EPITECH PROJECT, 2019
** Libfox
** File description:
** UT: list smart pointer
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

#include "datastruct/fox_list.h"

Test(autolist, regular_usage)
{
    autofoxlist_t list = NULL;

    list_create(&list);
    cr_assert(true);
}
