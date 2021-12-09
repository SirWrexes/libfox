/*
** (not) EPITECH PROJECT, 2021
** Libfox
** File description:
** Create a new tree node
*/

#include <malloc.h>
#include <stdbool.h>
#include "fox_datastruct.h"

__a((nonnull(1))) bool tnode_create(
    foxtnode_t *leafptr, void *data, foxtree_t root)
{
    *leafptr = malloc(sizeof(**leafptr));
    if (*leafptr == NULL)
        return true;
    (*leafptr)->root = root;
    if (root != NULL)
        root->nodes += 1;
    (*leafptr)->data = data;
    (*leafptr)->lnext = NULL;
    (*leafptr)->rnext = NULL;
    return false;
}
