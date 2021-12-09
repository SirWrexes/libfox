/*
** (not) EPITECH PROJECT, 2021
** Libfox
** File description:
** UT: Locate the first occurence of a character in a string
*/

#include <string.h>

#include <criterion/criterion.h>
#include <criterion/redirect.h>

#include "fox_string.h"

Test(strchr, regular_usage)
{
    str2c_t s = "Ubne string normale.";

    cr_expect_eq(fox_strchr(s, 'i'), strchr(s, 'i'));
    cr_expect_eq(fox_strchr(s, 'z'), strchr(s, 'z'));
}
