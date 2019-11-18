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

Test(print_unsigned_base, print_uchar, .init = cr_redirect_stdout)
{
    va_list ap;
    fstruct_t arg = {0};
    str_t ref = "10101101";

    setup_va_list(&ap, 0b10101101);
    arg.info.is_char = true;
    arg.info.spec = 'b';
    cr_assert_eq(print_unsigned_base(&arg, &ap), (scount_t) strlen(ref));
    cr_expect_stdout_eq_str(ref);
    va_end(ap);
}

Test(print_unsigned_base, print_ushort, .init = cr_redirect_stdout)
{
    va_list ap;
    fstruct_t arg = {0};
    char ref[fox_unumsize(ULLONG_MAX)];

    setup_va_list(&ap, ULLONG_MAX);
    arg.info.is_short = true;
    arg.info.spec = 'X';
    cr_assert_eq(
        print_unsigned_base(&arg, &ap), sprintf(ref, "%hX", ULLONG_MAX));
    cr_expect_stdout_eq_str(ref);
    va_end(ap);
}

Test(print_unsigned_base, print_uint, .init = cr_redirect_stdout)
{
    va_list ap;
    fstruct_t arg = {0};
    char ref[fox_unumsize(ULLONG_MAX) + 3];

    setup_va_list(&ap, ULLONG_MAX);
    arg.info.spec = 'o';
    arg.info.alt = true;
    cr_assert_eq(
        print_unsigned_base(&arg, &ap), sprintf(ref, "%#o", ULLONG_MAX));
    cr_expect_stdout_eq_str(ref);
    va_end(ap);
}

Test(print_unsigned_base, print_ulong, .init = cr_redirect_stdout)
{
    va_list ap;
    fstruct_t arg = {0};
    char ref[fox_unumsize(ULLONG_MAX)];

    setup_va_list(&ap, ULLONG_MAX);
    arg.info.is_long = true;
    arg.info.spec = 'x';
    arg.info.alt = true;
    cr_assert_eq(
        print_unsigned_base(&arg, &ap), sprintf(ref, "%#lx", ULLONG_MAX));
    cr_expect_stdout_eq_str(ref);
    va_end(ap);
}

Test(print_unsigned_base, print_ulong_long, .init = cr_redirect_stdout)
{
    va_list ap;
    fstruct_t arg = {0};
    char ref[fox_unumsize(ULLONG_MAX)];

    setup_va_list(&ap, ULLONG_MAX);
    arg.info.is_long_long = true;
    arg.info.spec = 'o';
    cr_assert_eq(
        print_unsigned_base(&arg, &ap), sprintf(ref, "%llo", ULLONG_MAX));
    cr_expect_stdout_eq_str(ref);
    va_end(ap);
}
