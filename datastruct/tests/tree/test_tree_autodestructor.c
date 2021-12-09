/*
** (not) EPITECH PROJECT, 2021
** Libfox
** File description:
** UT: Tree with a garbage collector implementation
*/

#include <signal.h>
#include <stddef.h>
#include <criterion/criterion.h>
#include <criterion/redirect.h>

#include "fox_datastruct.h"

Test(autotree, regular_usage)
{
    autofoxtree_t tree = NULL;

    tree_create(&tree);
}
