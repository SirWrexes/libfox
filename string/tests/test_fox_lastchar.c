/*
** EPITECH PROJECT, 2020
** Minishell 1
** File description:
** test_fox_lastchar.c -- No description
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

#include "fox_string.h"

Test(lastchar, regular_usage)
{
    cr_expect_eq(fox_lastchar("sauce"), 'e');
}

Test(lastchar, empty_string)
{
    cr_expect_eq(fox_lastchar(""), '\0');
}
