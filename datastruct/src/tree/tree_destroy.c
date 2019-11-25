/*
** EPITECH PROJECT, 2019
** Libfox
** File description:
** Destroy a tree and all its nodes
*/

#include <malloc.h>
#include "fox_datastruct.h"

__a((nonnull)) void tree_destroy(foxtree_t *treeptr, void (*destructor)())
{
    if (*treeptr == NULL)
        return;
    tnode_destroy(&(*treeptr)->trunk, destructor);
    free(*treeptr);
    *treeptr = NULL;
}
