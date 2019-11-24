/*
** EPITECH PROJECT, 2019
** Libfox
** File description:
** List node creation
*/

#include <malloc.h>

#include "datastruct/fox_list.h"

__Anonnull
bool node_create(foxnode_t *nodeptr, void *data)
{
    *nodeptr = malloc(sizeof(**nodeptr));
    if (*nodeptr == NULL)
        return true;
    (*nodeptr)->i = 0;
    (*nodeptr)->data = data;
    (*nodeptr)->prev = NULL;
    (*nodeptr)->next = NULL;
    return false;
}
