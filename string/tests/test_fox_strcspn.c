/*
** EPITECH PROJECT, 2019
** <project name> unit tests
** File description:
** test_fox_strcspn.c -- No description
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "fox_define.h"
#include "fox_string.h"

Test(fox_strcspn, regular_usage)
{
    cr_expect_eq(fox_strcspn("123ABC", STR_ALPHAUP), 3);
    cr_expect_eq(fox_strcspn("123456", STR_ALPHAUP), 6);
}
