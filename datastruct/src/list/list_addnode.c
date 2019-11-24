/*
** EPITECH PROJECT, 2019
** Libfox
** File description:
** Add a node to list
*/

#include "datastruct/fox_list.h"

__Anonnull
bool list_addnode(foxlist_t list, void *data)
{
    foxnode_t new = NULL;

    if (node_create(&new, data))
        return true;
    new->i = ++list->nodes;
    if (list->tail == NULL) {
        list->head = new;
        list->tail = new;
    } else {
        new->prev = list->tail;
        list->tail->next = new;
        list->tail = new;
    }
    return false;
}
