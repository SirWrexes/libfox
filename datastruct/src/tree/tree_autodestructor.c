/*
** EPITECH PROJECT, 2019
** Libfox
** File description:
** Tree auto destructor for cleanup attribute
*/

#include "datastruct/fox_tree.h"

__const
leafcutter_t *treedata_destructor(void)
{
    static leafcutter_t f = NULL;

    return &f;
}

__nonnull
void chainsaw(foxtree_t *treeptr)
{
    tree_destroy(treeptr, leafcutter);
}
