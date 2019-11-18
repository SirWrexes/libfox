/*
** EPITECH PROJECT, 2019
** Libfox
** File description:
** UT: Getting the field width for a format argument
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

#include "args/farg_datastruct.h"
#include "args/parsers.h"

Test(get_width, regular_usage)
{
    fstruct_t arg = {0};

    arg.fmt = "250llb";
    get_width(&arg.info, &arg.fmt);
    cr_expect_eq(arg.info.width, 250);
    cr_expect_eq(*arg.fmt, 'l');
}

Test(get_width, not_a_number)
{
    fstruct_t arg = {0};

    arg.fmt = "ptdr t ki";
    get_width(&arg.info, &arg.fmt);
    cr_expect_eq(arg.info.width, 0);
    cr_expect_eq(*arg.fmt, 'p');
}
