/*
** EPITECH PROJECT, 2019
** Libfox
** File description:
** Add an item to the stack
*/

#include <stdbool.h>
#include <malloc.h>
#include "datastruct/fox_stack.h"

static bool push_to_top(foxstack_t stack, void *data)
{
    foxsitem_t oldtop = stack->faketop;
    foxsitem_t newtop = malloc(sizeof(*newtop));

    if (newtop == NULL)
        return true;
    newtop->i = ++stack->items;
    newtop->data = data;
    newtop->prev = oldtop;
    stack->faketop = newtop;
    stack->realtop = newtop;
    return false;
}

static bool push_to_first_available(foxstack_t stack, void *data)
{
    foxsitem_t push = stack->faketop;

    while (push->i > stack->items + 1)
        push = push->prev;
    push->data = data;
    push->prev = stack->realtop;
    stack->realtop = push;
    stack->items += 1;
    return false;
}

__Anonnull bool stack_push(foxstack_t stack, void *data)
{
    if (stack->faketop == NULL || stack->faketop->i == stack->items)
        return push_to_top(stack, data);
    return push_to_first_available(stack, data);
}
