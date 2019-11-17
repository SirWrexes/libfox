/*
** EPITECH PROJECT, 2019
** Libfox
** File description:
** UT: Counting the digits of an unsigned number
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "fox_math.h"

Test(unumsize, regular_usage)
{
    cr_expect_eq(fox_unumsize(1), 1);
    cr_expect_eq(fox_unumsize(20), 2);
    cr_expect_eq(fox_unumsize(300), 3);
    cr_expect_eq(fox_unumsize(4000), 4);
    cr_expect_eq(fox_unumsize(-0), 1);
}
