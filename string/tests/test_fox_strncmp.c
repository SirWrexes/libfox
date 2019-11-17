/*
** EPITECH PROJECT, 2019
** Libfox
** File description:
** UT: Comparing a string up to n characters
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <string.h>
#include "fox_string.h"

Test(strncmp, same_strings)
{
    str_t s = "S1 et S2 seront parfaitement identiques";

    cr_expect_eq(fox_strncmp(s, s, 0), strncmp(s, s, 0));
    cr_expect_eq(fox_strncmp(s, s, 1), strncmp(s, s, 1));
    cr_expect_eq(fox_strncmp(s, s, 2), strncmp(s, s, 2));
    cr_expect_eq(fox_strncmp(s, s, 3), strncmp(s, s, 3));
    cr_expect_eq(fox_strncmp(s, s, 4), strncmp(s, s, 4));
    cr_expect_eq(fox_strncmp(s, s, 5), strncmp(s, s, 5));
    cr_expect_eq(fox_strncmp(s, s, 6), strncmp(s, s, 6));
    cr_expect_eq(fox_strncmp(s, s, 7), strncmp(s, s, 7));
    cr_expect_eq(fox_strncmp(s, s, 8), strncmp(s, s, 8));
    cr_expect_eq(fox_strncmp(s, s, 9), strncmp(s, s, 9));
    cr_expect_eq(fox_strncmp(s, s, 10), strncmp(s, s, 10));
    cr_expect_eq(fox_strncmp(s, s, 30), strncmp(s, s, 30));
}

Test(strncmp, extra_branch_testing)
{
    cr_expect_eq(fox_strncmp("ptdr", "ptdr t ki", 20),
        strncmp("ptdr", "ptdr t ki", 20));
    cr_expect_eq(fox_strncmp("suce", "sauce", 12),
        strncmp("suce", "sauce", 12));
}
