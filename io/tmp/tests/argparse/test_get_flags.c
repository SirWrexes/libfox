/*
** EPITECH PROJECT, 2019
** Libfox
** File description:
** UT: Format flags parsing
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

#include "args/farg_datastruct.h"
#include "args/parsers.h"

Test(get_flags, regular_usage)
{
    fstruct_t arg = {0};

    arg.fmt = "#0- +'",
    get_flags(&arg.info, &arg.fmt);
    cr_expect(arg.info.alt);
    cr_expect(arg.info.space);
    cr_expect(arg.info.left);
    cr_expect(arg.info.showsign);
    cr_expect(arg.info.group);
    cr_expect(arg.info.zeropad);
    cr_expect_not(arg.info.is_valid);
}

Test(get_flags, bad_flag)
{
    fstruct_t arg = {0};

    arg.fmt = "non mdr";
    get_flags(&arg.info, &arg.fmt);
    cr_expect_not(arg.info.alt);
    cr_expect_not(arg.info.space);
    cr_expect_not(arg.info.left);
    cr_expect_not(arg.info.showsign);
    cr_expect_not(arg.info.group);
}
