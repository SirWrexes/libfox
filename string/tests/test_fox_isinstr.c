/*
** EPITECH PROJECT, 2019
** <project name> unit tests
** File description:
** test_fox_isinstr.c -- No description
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "fox_string.h"

Test(isinstr, instr_char)
{
    cr_expect(fox_isinstr('a', STR_ALPHALO));
}

Test(isinstr, ininstr_char)
{
    cr_expect_not(fox_isinstr('a', STR_ALPHAUP));
}

Test(isinstr, null_char)
{
    cr_expect_not(fox_isinstr('\0', STR_ALPHAUP));
}
