/*
** EPITECH PROJECT, 2019
** Libfox
** File description:
** Stack auto destructor for cleanup attribute
*/

#include "datastruct/fox_stack.h"

__Aconst pilebreaker_t *stackdata_destructor(void)
{
    static pilebreaker_t f = NULL;

    return &f;
}

__Anonnull void jenga(foxstack_t *stackptr)
{
    stack_destroy(stackptr, pilebreaker);
}
