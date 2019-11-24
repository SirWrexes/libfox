/*
** EPITECH PROJECT, 2019
** Libfox
** File description:
** Pop an item from a stack
*/

#include "datastruct/fox_stack.h"

__Anonnull
void *stack_pop(foxstack_t stack)
{
    foxsitem_t pop = stack->faketop;
    void *data = NULL;

    if (pop == NULL)
        return NULL;
    while (pop->i > stack->items)
        pop = pop->prev;
    data = pop->data;
    pop->data = NULL;
    stack->items -= 1;
    stack->realtop = pop->prev != NULL ? pop->prev : pop;
    return data;
}
