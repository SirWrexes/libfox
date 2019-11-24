/*
** EPITECH PROJECT, 2019
** Libfox
** File description:
** List autodestructor for smart pointer implementation
*/

#include "datastruct/fox_list.h"

__Aconst
paperblade_t *listdata_destructor(void)
{
    static paperblade_t f = NULL;

    return &f;
}

__Anonnull
void shredder(foxlist_t *listptr)
{
    list_destroy(listptr, paperblade);
}
