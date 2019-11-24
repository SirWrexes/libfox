/*
** EPITECH PROJECT, 2019
** Libfox
** File description:
** UT: Filling a buffer with n times the pad characters
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "fox_io.h"

Test(siopadn, regular_usage)
{
    char const ref[25] = {[0 ... 23] = '0', [24] = '\0'};
    char buff[25] = {[0 ... 24] = '\0'};

    cr_expect_eq(fox_siopadn(buff, '0', 24), 24);
    cr_expect_str_eq(buff, ref);
}
