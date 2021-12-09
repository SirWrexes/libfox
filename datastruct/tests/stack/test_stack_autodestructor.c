/*
** (not) EPITECH PROJECT, 2021
** Libfox
** File description:
** UT: Stack smart pointer
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

#include "fox_stack.h"

Test(autostack, regular_usage)
{
    autofoxstack_t stack = NULL;

    stack_create(&stack);
    cr_assert(true);
}
