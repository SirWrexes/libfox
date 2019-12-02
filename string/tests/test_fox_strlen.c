/*
** EPITECH PROJECT, 2019
** Libfox
** File description:
** UT: Getting the length of a string
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

#include "fox_define.h"
#include "fox_string.h"

Test(strlen, regular_usage)
{
    cr_expect_eq(fox_strlen(""), 0);
    cr_expect_eq(fox_strlen("1"), 1);
    cr_expect_eq(fox_strlen("12"), 2);
    cr_expect_eq(fox_strlen("123"), 3);
    cr_expect_eq(fox_strlen("1234"), 4);
    cr_expect_eq(fox_strlen("12345"), 5);
    cr_expect_eq(fox_strlen("123456"), 6);
    cr_expect_eq(fox_strlen("1234567"), 7);
    cr_expect_eq(fox_strlen("12345678"), 8);
}
