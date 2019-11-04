/*
** EPITECH PROJECT, 2019
** <project name> unit tests
** File description:
** test_stack_push.c -- No description
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "tests/wrap_malloc.h"

#include "datastruct/fox_stack.h"

Test(stack_push, regular_usage)
{
    foxstack_t stack = NULL;

    cr_assert_not(stack_create(&stack));
    cr_assert_not(stack_push(stack, &stack));
    cr_expect_eq(stack->items, 1);
    cr_assert_not(stack_push(stack, &stack));
    cr_expect_eq(stack->items, 2);
    cr_expect_eq(stack_pop(stack), &stack);
    cr_expect_eq(stack->items, 1);
    cr_expect_eq(stack->faketop->i, 2);
    cr_expect_null(stack->faketop->data);
    cr_assert_not(stack_push(stack, &stack));
    cr_expect_eq(stack->items, 2);
    stack_pop(stack);
    stack_pop(stack);
    cr_assert_not(stack_push(stack, &stack));
    cr_assert_not(stack_push(stack, &stack));
}

Test(stack_push, broken_malloc, .fini = fix_malloc)
{
    foxstack_t stack = NULL;

    malloc_counter = 1;
    cr_assert_not(stack_create(&stack));
    cr_assert(stack_push(stack, &stack));
    cr_expect_eq(stack->items, 0);
}
