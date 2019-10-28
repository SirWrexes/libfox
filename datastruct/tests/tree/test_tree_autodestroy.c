/*
** EPITECH PROJECT, 2019
** Libfox
** File description:
** Tree with a garbage collector implementation
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "fox_datastruct.h"

Test(autotree, regular_usage)
{
    autotree_t tree = NULL;

    tree_create(&tree);
    cr_assert(true);
}
