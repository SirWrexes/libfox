/*
** (not) EPITECH PROJECT, 2021
** Libfox unit tests
** File description:
** UT: Pop an item from a stack
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

#include "fox_stack.h"

Test(stack_pop, regular_usage)
{
    foxstack_t stack = NULL;

    cr_assert_not(stack_create(&stack));
    cr_assert_not(stack_push(stack, &stack));
    cr_assert_not(stack_push(stack, &stack));
    cr_assert_not(stack_push(stack, &stack));
    cr_expect_eq(stack->items, 3);
    cr_expect_eq(stack_pop(stack), &stack);
    cr_expect_eq(stack->items, 2);
    cr_expect_eq(stack_pop(stack), &stack);
    cr_expect_eq(stack->items, 1);
    cr_expect_eq(stack_pop(stack), &stack);
    cr_expect_eq(stack->items, 0);
}

Test(stack_pop, empty_stack)
{
    foxstack_t stack = NULL;

    cr_assert_not(stack_create(&stack));
    cr_expect_eq(stack_pop(stack), NULL);
}
