/*
** EPITECH PROJECT, 2019
** Libfox
** File description:
** Stack creation
*/

#include <malloc.h>
#include <stdbool.h>
#include "datastruct/fox_stack.h"

__nonnull
bool stack_create(foxstack_t *stack)
{
    *stack = malloc(sizeof(**stack));

    if (*stack == NULL)
        return true;
    (*stack)->items = 0;
    (*stack)->faketop = NULL;
    return false;
}
