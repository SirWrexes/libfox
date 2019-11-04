/*
** EPITECH PROJECT, 2019
** Libfox
** File description:
** Tree with a garbage collector implementation
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
