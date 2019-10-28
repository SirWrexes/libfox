/*
** EPITECH PROJECT, 2019
** Libfox
** File description:
** Pop an item from a stack
*/

#include "datastruct/fox_stack.h"

__nonnull
void *stack_pop(stack_t stack)
{
    sitem_t pop = stack->faketop;
    void *data = NULL;

    if (pop == NULL)
        return NULL;
    while (pop != NULL && pop->data == NULL)
        pop = pop->prev;
    data = pop->data;
    pop->data = NULL;
    stack->items -= 1;
    return data;
}
