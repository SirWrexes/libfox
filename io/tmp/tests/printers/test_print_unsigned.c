/*
** EPITECH PROJECT, 2019
** Libfox
** File description:
** UT: Printing an unsigned format argument
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

Test(print_unsigned, print_uchar, .init = cr_redirect_stdout)
{
    va_list ap;
    fstruct_t arg = {0};
    char ref[fox_unumsize(ULLONG_MAX)];

    setup_va_list(&ap, ULLONG_MAX);
    arg.info.is_char = true;
    cr_assert_eq(print_unsigned(&arg, &ap), sprintf(ref, "%hhu", ULLONG_MAX));
    cr_expect_stdout_eq_str(ref);
    va_end(ap);
}

Test(print_unsigned, print_ushort, .init = cr_redirect_stdout)
{
    va_list ap;
    fstruct_t arg = {0};
    char ref[fox_unumsize(ULLONG_MAX)];

    setup_va_list(&ap, ULLONG_MAX);
    arg.info.is_short = true;
    cr_assert_eq(print_unsigned(&arg, &ap), sprintf(ref, "%hu", ULLONG_MAX));
    cr_expect_stdout_eq_str(ref);
    va_end(ap);
}

Test(print_unsigned, print_uint, .init = cr_redirect_stdout)
{
    va_list ap;
    fstruct_t arg = {0};
    char ref[fox_unumsize(ULLONG_MAX)];

    setup_va_list(&ap, ULLONG_MAX);
    cr_assert_eq(print_unsigned(&arg, &ap), sprintf(ref, "%u", ULLONG_MAX));
    cr_expect_stdout_eq_str(ref);
    va_end(ap);
}

Test(print_unsigned, print_ulong, .init = cr_redirect_stdout)
{
    va_list ap;
    fstruct_t arg = {0};
    char ref[fox_unumsize(ULLONG_MAX)];

    setup_va_list(&ap, ULLONG_MAX);
    arg.info.is_long = true;
    cr_assert_eq(print_unsigned(&arg, &ap), sprintf(ref, "%lu", ULLONG_MAX));
    cr_expect_stdout_eq_str(ref);
    va_end(ap);
}

Test(print_unsigned, print_ulong_long, .init = cr_redirect_stdout)
{
    va_list ap;
    fstruct_t arg = {0};
    char ref[fox_unumsize(ULLONG_MAX)];

    setup_va_list(&ap, ULLONG_MAX);
    arg.info.is_long_long = true;
    cr_assert_eq(print_unsigned(&arg, &ap), sprintf(ref, "%llu", ULLONG_MAX));
    cr_expect_stdout_eq_str(ref);
    va_end(ap);
}
