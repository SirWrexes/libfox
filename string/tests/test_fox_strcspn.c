/*
** (not) EPITECH PROJECT, 2021
** Libfox
** File description:
** UT: Count the prefix characters not from delim in a string
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
