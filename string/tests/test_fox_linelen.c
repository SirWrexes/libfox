/*
** EPITECH PROJECT, 2019
** Libfox
** File description:
** UT: Getting the length of a line
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

#include "fox_define.h"
#include "fox_string.h"

Test(linelen, regular_usage)
{
    cr_expect_eq(fox_linelen(""), 0);
    cr_expect_eq(fox_linelen("1"), 1);
    cr_expect_eq(fox_linelen("12"), 2);
    cr_expect_eq(fox_linelen("123"), 3);
    cr_expect_eq(fox_linelen("1234"), 4);
    cr_expect_eq(fox_linelen("12345"), 5);
    cr_expect_eq(fox_linelen("123456"), 6);
    cr_expect_eq(fox_linelen("1234567"), 7);
    cr_expect_eq(fox_linelen("12345678"), 8);
    cr_expect_eq(fox_linelen("\n"), 0);
    cr_expect_eq(fox_linelen("1\n"), 1);
    cr_expect_eq(fox_linelen("12\n"), 2);
    cr_expect_eq(fox_linelen("123\n"), 3);
    cr_expect_eq(fox_linelen("1234\n"), 4);
    cr_expect_eq(fox_linelen("12345\n"), 5);
    cr_expect_eq(fox_linelen("123456\n"), 6);
    cr_expect_eq(fox_linelen("1234567\n"), 7);
    cr_expect_eq(fox_linelen("12345678\n"), 8);
}
