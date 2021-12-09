/*
** (not) EPITECH PROJECT, 2021
** Libfox
** File description:
** UT: Get the last character of a string
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
