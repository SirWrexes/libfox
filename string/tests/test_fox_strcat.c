/*
** EPITECH PROJECT, 2020
** Minishell 1
** File description:
** test_fox_strcat.c -- No description
*/

#include <string.h>

#include <criterion/criterion.h>
#include <criterion/redirect.h>

#include "fox_string.h"

Test(fox_strcat, regular_usage)
{
    str2c_t s1 = "Hello ";
    str2c_t s2 = "world!";
    char tst[13] = {0};
    char ref[13] = {0};

    cr_expect_eq(fox_strcat(tst, s1), tst);
    cr_expect_eq(fox_strcat(tst, s2), tst);
    strcat(ref, s1);
    strcat(ref, s2);
    cr_expect_str_eq(tst, ref);
}
