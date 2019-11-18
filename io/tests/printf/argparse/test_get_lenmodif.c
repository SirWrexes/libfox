/*
** EPITECH PROJECT, 2019
** Libfox
** File description:
** UT: Parsing a length modifier
*/

#include <stddef.h>
#include <stdint.h>
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "printf/fstruct.h"
#include "printf/argparse.h"
#include "printf/infomask.h"
#include "fox_define.h"

Test(get_lenmodif, is_char)
{
    fstruct_t arg = {0};

    arg.fmt = "hh";
    get_lenmodif(&arg.info, &arg.fmt);
    cr_expect(arg.info.is_char);
    cr_expect_not(*arg.fmt);
}

Test(get_lenmodif, is_short)
{
    fstruct_t arg = {0};

    arg.fmt = "h";
    get_lenmodif(&arg.info, &arg.fmt);
    cr_expect(arg.info.is_short);
    cr_expect_not(*arg.fmt);
}

Test(get_lenmodif, is_long)
{
    fstruct_t arg = {0};

    arg.fmt = "l";
    get_lenmodif(&arg.info, &arg.fmt);
    cr_expect(arg.info.is_long);
    cr_expect_not(*arg.fmt);
}

Test(get_lenmodif, is_long_long)
{
    fstruct_t arg = {0};

    arg.fmt = "ll";
    get_lenmodif(&arg.info, &arg.fmt);
    cr_expect(arg.info.is_long_long);
    cr_expect_not(*arg.fmt);
    arg.info.is_long_long = false;
    arg.fmt = "q";
    get_lenmodif(&arg.info, &arg.fmt);
    cr_expect(arg.info.is_long_long);
    cr_expect_not(*arg.fmt);
}

Test(get_lenmodif, is_long_double)
{
    fstruct_t arg = {0};

    arg.fmt = "L";
    get_lenmodif(&arg.info, &arg.fmt);
    cr_expect(arg.info.is_long_double);
    cr_expect_not(*arg.fmt);
}

Test(get_lenmodif, is_size_t)
{
    fstruct_t arg = {0};

    arg.fmt = "z";
    get_lenmodif(&arg.info, &arg.fmt);
    #if LONG_MAX != LONG_LONG_MAX
    cr_expect_eq(arg.info.is_long_long, sizeof(size_t) > sizeof(ulong_t));
    #endif
    cr_expect_eq(arg.info.is_long, sizeof(size_t) > sizeof(uint));
    cr_expect_not(*arg.fmt);
    arg.info.is_long_long = false;
    arg.info.is_long = false;
    arg.fmt = "Z";
    get_lenmodif(&arg.info, &arg.fmt);
    #if LONG_MAX != LONG_LONG_MAX
    cr_expect_eq(arg.info.is_long_long, sizeof(size_t) > sizeof(ulong_t));
    #endif
    cr_expect_eq(arg.info.is_long, sizeof(size_t) > sizeof(uint));
    cr_expect_not(*arg.fmt);
}

Test(get_lenmodif, is_uintmax_t)
{
    fstruct_t arg = {0};

    arg.fmt = "j";
    get_lenmodif(&arg.info, &arg.fmt);
    #if LONG_MAX != LONG_LONG_MAX
    cr_expect_eq(arg.info.is_long_long, sizeof(size_t) > sizeof(ulong_t));
    #endif
    cr_expect_eq(arg.info.is_long, sizeof(size_t) > sizeof(uint));
    cr_expect_not(*arg.fmt);
}

Test(get_lenmodif, is_ptdrdiff_t)
{
    fstruct_t arg = {0};

    arg.fmt = "t";
    get_lenmodif(&arg.info, &arg.fmt);
    #if LONG_MAX != LONG_LONG_MAX
    cr_expect_eq(arg.info.is_long_long, sizeof(ptrdiff_t) > sizeof(long int));
    #endif
    cr_expect_eq(arg.info.is_long, sizeof(ptrdiff_t) > sizeof(uint));
    cr_expect_not(*arg.fmt);
}

Test(get_lenmodif, none)
{
    fstruct_t arg = {0};

    arg.fmt = "U";
    get_lenmodif(&arg.info, &arg.fmt);
    cr_expect_not(info_to_mask(&arg.info));
    cr_expect_eq(*arg.fmt, 'U');
}
