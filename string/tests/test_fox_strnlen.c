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

Test(strnlen, n_longer_than_string)
{
    cr_expect_eq(fox_strnlen("", 9), 0);
    cr_expect_eq(fox_strnlen("1", 9), 1);
    cr_expect_eq(fox_strnlen("12", 9), 2);
    cr_expect_eq(fox_strnlen("123", 9), 3);
    cr_expect_eq(fox_strnlen("1234", 9), 4);
    cr_expect_eq(fox_strnlen("12345", 9), 5);
    cr_expect_eq(fox_strnlen("123456", 9), 6);
    cr_expect_eq(fox_strnlen("1234567", 9), 7);
    cr_expect_eq(fox_strnlen("12345678", 9), 8);
}
