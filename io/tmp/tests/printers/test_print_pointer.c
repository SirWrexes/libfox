/*
** EPITECH PROJECT, 2019
** Libfox
** File description:
** UT: Printing a pointer
*/

#include <stdio.h>
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "tests/printers.h"

#include "printers.h"
#include "args/farg_datastruct.h"

Test(print_pointer, caps, .init = cr_redirect_stdout)
{
    va_list ap;
    fstruct_t arg = {0};
    char ref[23] = {0};

    setup_va_list(&ap, &ap);
    arg.info.spec = 'x';
    cr_assert_eq(print_pointer(&arg, &ap), sprintf(ref, "%x", &ap));
    cr_expect_stdout_eq_str(ref);
    va_end(ap);
}

Test(print_pointer, no_caps, .init = cr_redirect_stdout)
{
    va_list ap;
    fstruct_t arg = {0};
    char ref[23] = {0};

    setup_va_list(&ap, &ap);
    arg.info.spec = 'X';
    cr_assert_eq(print_pointer(&arg, &ap), sprintf(ref, "%X", &ap));
    cr_expect_stdout_eq_str(ref);
    va_end(ap);
}

Test(print_pointer, null_pointer, .init = cr_redirect_stdout)
{
    va_list ap;
    fstruct_t arg = {0};
    char ref[23] = {0};

    setup_va_list(&ap, NULL);
    arg.info.spec = 'X';
    cr_assert_eq(print_pointer(&arg, &ap), sprintf(ref, "%X", NULL));
    cr_expect_stdout_eq_str(ref);
    va_end(ap);
}
