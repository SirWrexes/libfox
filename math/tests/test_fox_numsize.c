/*
** EPITECH PROJECT, 2019
** Libfox
** File description:
** UT: Counting the digits of a number
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "fox_math.h"

Test(numsize, regular_usage)
{
    cr_expect_eq(fox_numsize(1), 1);
    cr_expect_eq(fox_numsize(20), 2);
    cr_expect_eq(fox_numsize(300), 3);
    cr_expect_eq(fox_numsize(4000), 4);
    cr_expect_eq(fox_numsize(-20), 2);
    cr_expect_eq(fox_numsize(-0), 1);
}
