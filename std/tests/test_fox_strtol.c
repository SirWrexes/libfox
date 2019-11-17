/*
** EPITECH PROJECT, 2019
** Libfox
** File description:
** Unit tests for fox_strtol
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "fox_define.h"
#include "fox_std.h"

Test(fox_strtol, regular_usage)
{
    str_t endptr = NULL;
    str_t num = "          +---0123cul";
    long res = fox_strtol(num, &endptr);

    cr_expect_eq(res, -123, "res = %ld", res);
    cr_expect_eq(endptr, num + strspn(num, " +-0123456789"));
}

Test(fox_strtol, overflow_and_underflow)
{
    long res = fox_strtol("-9223372036854775809", NULL);

    cr_expect_eq(res, 0, "Undeflow : res = %ld", res);
    res = fox_strtol("9223372036854775808", NULL);
    cr_expect_eq(res, 0, "Overflow : res = %ld", res);
}

Test(fox_strtol, num_too_big)
{
    long res = fox_strtol(
        "-922337203685477580913548453135487352123547", NULL);

    cr_expect_eq(res, 0, "res = %ld", res);
}

Test(strtol, not_a_number)
{
    long res = fox_strtol("sucepute 23", NULL);

    cr_expect_eq(res, 0);
}
