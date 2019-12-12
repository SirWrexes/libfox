/*
** EPITECH PROJECT, 2019
** Libfox unit tests
** File description:
** UT: Checking if a string is stricly numeric
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

#include "fox_string.h"

Test(strisnum, regular_usage)
{
    cr_expect(fox_strisnum("123"));
    cr_expect(fox_strisnum("++--123"));
    cr_expect(fox_strisnum("-+123.25"));
    cr_expect(fox_strisnum("   -+123.25"));
    cr_expect_not(fox_strisnum("  abc"));
    cr_expect_not(fox_strisnum("+ 123"));
    cr_expect_not(fox_strisnum("   +12o"));
    cr_expect_not(fox_strisnum("1.2.3"));
}
