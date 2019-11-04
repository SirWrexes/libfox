/*
** EPITECH PROJECT, 2019
** Libfox
** File description:
** Destroy a node and its data
*/

#include <malloc.h>
#include <unistd.h>

#include "datastruct/fox_list.h"

__a((nonnull(1)))
void node_destroy(foxnode_t *nodeptr, void (*destructor)())
{
    if (*nodeptr == NULL)
        return;
    if ((*nodeptr)->data != NULL && destructor != NULL)
        destructor(&(*nodeptr)->data);
    free(*nodeptr);
    *nodeptr = NULL;
}
