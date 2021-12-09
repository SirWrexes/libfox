/*
** (not) EPITECH PROJECT, 2021
** Libfox
** File description:
** UT: Revert a string
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "fox_string.h"

Test(revstr, empty_string)
{
    char str[] = "";

    cr_expect_str_eq(fox_revstr(str), "");
}

Test(revstr, string_with_only_one_char)
{
    char str[] = "a";

    cr_expect_str_eq(fox_revstr(str), "a");
}

Test(revstr, normal_string)
{
    char str[] = "aeiou";

    cr_expect_str_eq(fox_revstr(str), "uoiea");
}
