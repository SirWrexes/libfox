/*
** EPITECH PROJECT, 2019
** Libfox
** File description:
** UT: String comparison
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "fox_string.h"

Test(strcmp, regular_usage)
{
    cr_expect_eq(fox_strcmp("123", "123"), 0);
    cr_expect_eq(fox_strcmp("321", "123"), 2);
    cr_expect_eq(fox_strcmp("125", "123"), 2);
    cr_expect_eq(fox_strcmp("aaaaa", ""), 'a');
    cr_expect_eq(fox_strcmp("", "123"), -'1');
}
