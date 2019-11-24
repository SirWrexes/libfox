/*
** EPITECH PROJECT, 2019
** Libfox
** File description:
** Create a new list
*/

#include <malloc.h>

#include "datastruct/fox_list.h"

__Anonnull
bool list_create(foxlist_t *listptr)
{
    *listptr = malloc(sizeof(**listptr));
    if (*listptr == NULL)
        return true;
    (*listptr)->nodes = 0;
    (*listptr)->head = NULL;
    (*listptr)->tail = NULL;
    return false;
}
