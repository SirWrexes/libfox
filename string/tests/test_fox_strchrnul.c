/*
** EPITECH PROJECT, 2020
** Minishell 1
** File description:
** test_fox_strchrnul.c -- No description
*/

#define _GNU_SOURCE
#include <string.h>

#include <criterion/criterion.h>
#include <criterion/redirect.h>

#include "fox_string.h"

Test(strchrnul, regular_usage)
{
    str2c_t s = "palutena OP please nerf";

    cr_expect_eq(fox_strchrnul(s, 'O'), strchrnul(s, 'O'));
    cr_expect_eq(fox_strchrnul(s, '0'), strchrnul(s, '0'));
}
