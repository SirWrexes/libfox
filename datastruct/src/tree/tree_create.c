/*
** EPITECH PROJECT, 2019
** Libfox
** File description:
** Binary tree creation
*/

#include <malloc.h>
#include <stdbool.h>
#include "fox_datastruct.h"
#include "fox_define.h"

__nonnull
bool tree_create(foxtree_t *treeptr)
{
    *treeptr = malloc(sizeof(**treeptr));
    if (*treeptr == NULL)
        return true;
    (*treeptr)->nodes = 0;
    (*treeptr)->trunk = NULL;
    return false;
}
