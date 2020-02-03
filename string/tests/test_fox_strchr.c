/*
** EPITECH PROJECT, 2019
** Minishell unit tests
** File description:
** test_fox_strchr.c -- No description
*/

#include <string.h>

#include <criterion/criterion.h>
#include <criterion/redirect.h>

#include "fox_string.h"

Test(strchr, regular_usage)
{
    str2c_t s = "Ubne string normale.";

    cr_expect_eq(fox_strchr(s, 'i'), strchr(s, 'i'));
    cr_expect_eq(fox_strchr(s, 'z'), strchr(s, 'z'));
}
