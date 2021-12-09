/*
** (not) EPITECH PROJECT, 2021
** Libfox
** File description:
** UT: Count the occurences of given characters at the start of a string
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "fox_define.h"
#include "fox_string.h"

Test(fox_strspn, regular_usage)
{
    cr_expect_eq(fox_strspn("ABC123", STR_ALPHAUP), 3);
}
