/*
** EPITECH PROJECT, 2019
** Libfox
** File description:
** UT: Stack destruction
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "datastruct/fox_stack.h"

static void destructor(char ***s)
{
    free(**s);
    **s = NULL;
}

Test(stack_destroy, null_destructor)
{
    foxstack_t stack = NULL;

    cr_assert_not(stack_create(&stack));
    stack_destroy(&stack, NULL);
    cr_expect_null(stack);
    stack_destroy(&stack, NULL);
    cr_assert(true);
}

Test(stack_destroy, nonnull_destructor)
{
    foxstack_t stack = NULL;
    char *s = malloc(1);

    cr_assert_not(stack_create(&stack));
    cr_assert_not(stack_push(stack, &s));
    stack_destroy(&stack, &destructor);
    cr_expect_null(stack);
    cr_expect_null(s);
}
