/*
** EPITECH PROJECT, 2019
** Libfox
** File description:
** Tree node recursive destruction
*/

#include <malloc.h>
#include "fox_datastruct.h"

__a((nonnull(1)))
void tnode_destroy(foxtnode_t *nodeptr, void (*destructor)())
{
    if (*nodeptr == NULL)
        return;
    if (destructor != NULL && (*nodeptr)->data != NULL)
        destructor(&(*nodeptr)->data);
    if ((*nodeptr)->lnext != NULL)
        tnode_destroy(&(*nodeptr)->lnext, destructor);
    if ((*nodeptr)->rnext != NULL)
        tnode_destroy(&(*nodeptr)->rnext, destructor);
    if ((*nodeptr)->root != NULL)
        (*nodeptr)->root->nodes -= 1;
    free(*nodeptr);
    *nodeptr = NULL;
}
