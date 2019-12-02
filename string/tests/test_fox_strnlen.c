/*
** EPITECH PROJECT, 2019
** <project name> unit tests
** File description:
** test_fox_strlen.c -- No description
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "fox_define.h"
#include "fox_string.h"

Test(strnlen, n_bigger_than_len)
{
    cr_expect_eq(fox_strnlen("", 25), 0);
    cr_expect_eq(fox_strnlen("1", 25), 1);
    cr_expect_eq(fox_strnlen("12", 25), 2);
    cr_expect_eq(fox_strnlen("123", 25), 3);
    cr_expect_eq(fox_strnlen("1234", 25), 4);
    cr_expect_eq(fox_strnlen("12345", 25), 5);
    cr_expect_eq(fox_strnlen("123456", 25), 6);
    cr_expect_eq(fox_strnlen("1234567", 25), 7);
    cr_expect_eq(fox_strnlen("12345678", 25), 8);
    cr_expect_eq(fox_strnlen("123456789", 25), 9);
    cr_expect_eq(fox_strnlen("1234567890", 25), 10);
    cr_expect_eq(fox_strnlen("12345678901", 25), 11);
    cr_expect_eq(fox_strnlen("123456789012", 25), 12);
    cr_expect_eq(fox_strnlen("1234567890123", 25), 13);
    cr_expect_eq(fox_strnlen("12345678901234", 25), 14);
    cr_expect_eq(fox_strnlen("123456789012345", 25), 15);
}

Test(strnlen, n_lower_than_len)
{
    cr_expect_eq(fox_strnlen("1", 0), 0);
    cr_expect_eq(fox_strnlen("12", 1), 1);
    cr_expect_eq(fox_strnlen("123", 2), 2);
    cr_expect_eq(fox_strnlen("1234", 3), 3);
    cr_expect_eq(fox_strnlen("12345", 4), 4);
    cr_expect_eq(fox_strnlen("123456", 5), 5);
    cr_expect_eq(fox_strnlen("1234567", 6), 6);
    cr_expect_eq(fox_strnlen("12345678", 7), 7);
    cr_expect_eq(fox_strnlen("123456789", 8), 8);
    cr_expect_eq(fox_strnlen("1234567890", 9), 9);
    cr_expect_eq(fox_strnlen("12345678901", 10), 10);
    cr_expect_eq(fox_strnlen("123456789012", 11), 11);
    cr_expect_eq(fox_strnlen("1234567890123", 12), 12);
    cr_expect_eq(fox_strnlen("12345678901234", 13), 13);
}

Test(strnlen, extra_branch_testing)
{
    cr_expect_eq(fox_strnlen("123456", 13), 6);
    cr_expect_eq(fox_strnlen("1234567", 13), 7);
    cr_expect_eq(fox_strnlen("12345678", 13), 8);
    cr_expect_eq(fox_strnlen("123456789", 13), 9);
    cr_expect_eq(fox_strnlen("1234567890", 13), 10);
    cr_expect_eq(fox_strnlen("12345678901", 13), 11);
    cr_expect_eq(fox_strnlen("123456789012", 13), 12);
    cr_expect_eq(fox_strnlen("1234567890123", 13), 13);
}
