/*
** EPITECH PROJECT, 2019
** <project name>
** File description:
** autodestructor.c -- No description
*/

#include "fox_datastruct.h"

__const
leafcutter_t *treedata_destructor(void)
{
    static leafcutter_t f = NULL;

    return &f;
}

__nonnull
void chainsaw(tree_t *treeptr)
{
    tree_destroy(treeptr, leafcutter);
}
