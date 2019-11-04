/*
** EPITECH PROJECT, 2019
** Libfox
** File description:
** Destroy a list and all of it elements
*/

#include <malloc.h>

#include "datastruct/fox_list.h"

__nonnull
void list_destroy(foxlist_t *listptr, void (*destructor)())
{
    foxnode_t node = NULL;
    foxnode_t temp = NULL;

    if (*listptr == NULL)
        return;
    for (node = (*listptr)->head; node != NULL; node = temp) {
        temp = node->next;
        node_destroy(&node, destructor);
    }
    free(*listptr);
    *listptr = NULL;
}
