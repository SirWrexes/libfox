/*
** EPITECH PROJECT, 2019
** Libfox
** File description:
** UT: Getting the precision of a format argument
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

#include "args/farg_datastruct.h"
#include "args/parsers.h"

Test(get_precision, regular_usage)
{
    fstruct_t arg = {0};

    arg.fmt = ".20";
    get_precision(&arg.info, &arg.fmt);
    cr_expect_eq(arg.info.prec, 20);
    cr_expect_eq(*arg.fmt, '\0');
}

Test(get_precision, zero_precision)
{
    fstruct_t arg = {0};

    arg.fmt = ".";
    get_precision(&arg.info, &arg.fmt);
    cr_expect_eq(arg.info.prec, 0);
    cr_expect_eq(*arg.fmt, '\0');
    arg.fmt = ".0";
    get_precision(&arg.info, &arg.fmt);
    cr_expect_eq(arg.info.prec, 0);
    cr_expect_eq(*arg.fmt, '\0');
}

Test(get_precision, invalid_precision)
{
    fstruct_t arg = {0};

    arg.fmt = ".-42";
    get_precision(&arg.info, &arg.fmt);
    cr_expect_eq(arg.info.prec, 0);
    cr_expect_eq(*arg.fmt, '.');
    arg.fmt = "pute";
    get_precision(&arg.info, &arg.fmt);
    cr_expect_eq(arg.info.prec, 0);
    cr_expect_eq(*arg.fmt, 'p');
}
