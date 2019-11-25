/*
** EPITECH PROJECT, 2019
** Libfox
** File description:
** Tree auto destructor for cleanup attribute
*/

#include "datastruct/fox_tree.h"

__Aconst leafcutter_t *treedata_destructor(void)
{
    static leafcutter_t f = NULL;

    return &f;
}

__Anonnull void chainsaw(foxtree_t *treeptr)
{
    tree_destroy(treeptr, leafcutter);
}
