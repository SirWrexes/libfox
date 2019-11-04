/*
** EPITECH PROJECT, 2019
** Libfox
** File description:
** UT: Stack creation
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "tests/wrap_malloc.h"
#include "datastruct/fox_stack.h"

Test(stack_create, regular_usage)
{
    foxstack_t stack = NULL;

    cr_assert_not(stack_create(&stack));
    cr_assert_not_null(stack);
    cr_expect_eq(stack->items, 0);
    cr_expect_null(stack->faketop);
}

Test(stack_create, broken_malloc, .init = break_malloc, .fini = fix_malloc)
{
    foxstack_t stack = NULL;

    cr_assert(stack_create(&stack));
    cr_assert_null(stack);
}
