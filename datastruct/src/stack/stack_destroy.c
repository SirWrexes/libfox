/*
** EPITECH PROJECT, 2019
** Libfox
** File description:
** Stack destruction
*/

#include <malloc.h>
#include "datastruct/fox_stack.h"

__a((nonnull(1)))
void stack_destroy(stack_t *stack, void (*destructor)())
{
    sitem_t top = NULL;
    sitem_t tmp = NULL;

    if (*stack == NULL)
        return;
    top = (*stack)->faketop;
    while (top != NULL) {
        tmp = top->prev;
        if (destructor != NULL)
            destructor(&top->data);
        free(top);
        top = tmp;
    }
    free(*stack);
    *stack = NULL;
}
