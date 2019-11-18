/*
** EPITECH PROJECT, 2019
** Libfox
** File description:
** UT: Writing a padding to a given fd
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "statics/fox_diopadn.h"
#include "fox_io.h"

Test(iopadn, zeroes, .init = cr_redirect_stdout)
{
    const uchar_t padref = '0';
    char ref[PADSIZE + 10] = {[0 ... (PADSIZE + 9)] = padref};

    cr_assert_eq(fox_iopadn(padref, PADSIZE + 9), PADSIZE + 9);
    cr_expect_stdout_eq_str(ref);
}

Test(iopadn, blanks, .init = cr_redirect_stdout)
{
    const uchar_t padref = ' ';
    char ref[PADSIZE] = {[0 ... PADSIZE - 1] = padref};

    cr_assert_eq(fox_iopadn(padref, PADSIZE), PADSIZE);
    cr_expect_stdout_eq_str(ref);
}

Test(iopadn, something_else, .init = cr_redirect_stdout)
{
    const uchar_t padref = 'e';
    char ref[PADSIZE + 10] = {[0 ... (PADSIZE + 9)] = padref};

    cr_assert_eq(fox_iopadn(padref, PADSIZE + 9), PADSIZE + 9);
    cr_expect_stdout_eq_str(ref);
}
