/*
** EPITECH PROJECT, 2019
** Libfox
** File description:
** UT: Integer format arg printer
*/

#include <limits.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stdio.h>
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "fox_define.h"
#include "fox_math.h"
#include "tests/printers.h"

#include "printers.h"
#include "args/farg_datastruct.h"

Test(print_integer, print_char, .init = cr_redirect_stdout)
{
    va_list ap;
    fstruct_t arg = {0};
    char ref[fox_numsize(LLONG_MAX)];

    setup_va_list(&ap, LLONG_MAX);
    arg.info.is_char = true;
    cr_assert_eq(print_integer(&arg, &ap), sprintf(ref, "%hhi", LLONG_MAX));
    cr_expect_stdout_eq_str(ref);
    va_end(ap);
}

Test(print_integer, print_short, .init = cr_redirect_stdout)
{
    va_list ap;
    fstruct_t arg = {0};
    char ref[fox_numsize(LLONG_MAX)];

    setup_va_list(&ap, LLONG_MAX);
    arg.info.is_short = true;
    cr_assert_eq(print_integer(&arg, &ap), sprintf(ref, "%hi", LLONG_MAX));
    cr_expect_stdout_eq_str(ref);
    va_end(ap);
}

Test(print_integer, print_int, .init = cr_redirect_stdout)
{
    va_list ap;
    fstruct_t arg = {0};
    char ref[fox_numsize(LLONG_MAX)];

    setup_va_list(&ap, LLONG_MAX);
    cr_assert_eq(print_integer(&arg, &ap), sprintf(ref, "%i", LLONG_MAX));
    cr_expect_stdout_eq_str(ref);
    va_end(ap);
}

Test(print_integer, print_long, .init = cr_redirect_stdout)
{
    va_list ap;
    fstruct_t arg = {0};
    char ref[fox_numsize(LLONG_MAX)];

    setup_va_list(&ap, LLONG_MAX);
    arg.info.is_long = true;
    cr_assert_eq(print_integer(&arg, &ap), sprintf(ref, "%li", LLONG_MAX));
    cr_expect_stdout_eq_str(ref);
    va_end(ap);
}

Test(print_integer, print_long_long, .init = cr_redirect_stdout)
{
    va_list ap;
    fstruct_t arg = {0};
    char ref[fox_numsize(LLONG_MAX) + 2];

    setup_va_list(&ap, LLONG_MAX);
    arg.info.is_long_long = true;
    arg.info.showsign = true;
    cr_assert_eq(print_integer(&arg, &ap), sprintf(ref, "%+lli", LLONG_MAX));
    cr_expect_stdout_eq_str(ref);
    va_end(ap);
}
