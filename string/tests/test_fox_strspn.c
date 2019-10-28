/*
** EPITECH PROJECT, 2019
** <project name> unit tests
** File description:
** test_fox_strspn.c -- No description
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "fox_define.h"
#include "fox_string.h"

Test(fox_strspn, regular_usage)
{
    cr_expect_eq(fox_strspn("ABC123", STR_ALPHAUP), 3);
}
