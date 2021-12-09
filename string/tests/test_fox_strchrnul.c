/*
** (not) EPITECH PROJECT, 2021
** Libfox
** File description:
** UT: Locate the first occurrence of a character in a string
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
