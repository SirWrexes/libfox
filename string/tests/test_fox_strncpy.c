/*
** EPITECH PROJECT, 2019
** <project name> unit tests
** File description:
** test_fox_strncpy.c -- No description
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "fox_string.h"

Test(fox_strncpy, n_gt_src_len)
{
    char dest[30] = "You want the truth ?";
    char src[30] = "You can't handle the truth !";

    cr_expect_str_eq(fox_strncpy(dest, src, 50), "You can't handle the");
}

Test(fox_strncpy, n_lt_src_len)
{
    char dest[30] = "You want the truth ?";
    char src[30] = "You can't handle the truth !";

    cr_expect_str_eq(fox_strncpy(dest, src, 9), "You can't");
}

Test(fox_strncpy, n_gt_dest_len)
{
    char dest[30] = "O'Zamman";
    char src[30] = "Best Kebab";

    cr_expect_str_eq(fox_strncpy(dest, src, 10), "Best Keb");
}

Test(fox_strncpy, n_lt_dest_len)
{
    char dest[30] = "Cheese Harissa";
    char src[30] = "Poivre";

    cr_expect_str_eq(fox_strncpy(dest, src, 6), "Poivre");
}

Test(fox_strncpy, n_lt_both_len)
{
    char dest[30] = "suce";
    char src[30] = "pute";

    cr_expect_str_eq(fox_strncpy(dest, src, 12), "pute");
}
