/*
** EPITECH PROJECT, 2019
** Libfox
** File description:
** Get the length modifier of a format argument
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

#include "args/farg_datastruct.h"
#include "args/parsers.h"

Test(get_lenmodif, regular_usage)
{
    fstruct_t arg = {0};

    arg.fmt = "hh";
    get_lenmodif(&arg.info, &arg.fmt);
    cr_expect(arg.info.is_char);
    cr_expect_eq(*arg.fmt, '\0');
    arg.fmt = "h";
    get_lenmodif(&arg.info, &arg.fmt);
    cr_expect(arg.info.is_short);
    cr_expect_eq(*arg.fmt, '\0');
    arg.fmt = "l";
    get_lenmodif(&arg.info, &arg.fmt);
    cr_expect(arg.info.is_long);
    cr_expect_eq(*arg.fmt, '\0');
    arg.fmt = "ll";
    get_lenmodif(&arg.info, &arg.fmt);
    cr_expect(arg.info.is_long_long);
    cr_expect_eq(*arg.fmt, '\0');
    arg.fmt = "L";
    get_lenmodif(&arg.info, &arg.fmt);
    cr_expect(arg.info.is_long_double);
}

Test(get_lenmodif, not_a_lenmodif)
{
    fstruct_t arg = {0};

    arg.fmt = "moule";
    get_lenmodif(&arg.info, &arg.fmt);
    cr_expect_not(arg.info.is_char);
    cr_expect_not(arg.info.is_short);
    cr_expect_not(arg.info.is_long);
    cr_expect_not(arg.info.is_long_long);
    cr_expect_not(arg.info.is_long_double);
    cr_expect_eq(*arg.fmt, 'm');
}
