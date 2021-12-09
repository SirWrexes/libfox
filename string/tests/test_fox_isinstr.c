/*
** (not) EPITECH PROJECT, 2021
** Libfox
** File description:
** UT: Chck that a string contains a given character
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
