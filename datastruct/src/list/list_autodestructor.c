/*
** EPITECH PROJECT, 2019
** Libfox
** File description:
** List autodestructor for smart pointer implementation
*/

#include "datastruct/fox_list.h"

__const
paperblade_t *listdata_destructor(void)
{
    static paperblade_t f = NULL;

    return &f;
}

__nonnull
void shredder(foxlist_t *listptr)
{
    list_destroy(listptr, paperblade);
}
