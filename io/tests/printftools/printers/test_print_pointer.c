/*
** (not) EPITECH PROJECT, 2021
** Libfox
** File description:
** UT: Print a pointer format argument
*/

#include <stdio.h>

#include <criterion/criterion.h>
#include <criterion/redirect.h>

#include "tests/printers.h"

#include "printf/fstruct.h"
#include "printf/printers.h"

Test(print_pointer, caps, .init = cr_redirect_stdout)
{
    va_list ap;
    fstruct_t arg = {0};
    char ref[23] = {0};

    setup_va_list(&ap, &ap);
    arg.info.spec = 'p';
    cr_assert_eq(print_pointer(1, &arg, &ap), sprintf(ref, "%p", &ap));
    cr_expect_stdout_eq_str(ref);
    va_end(ap);
}

Test(print_pointer, no_caps, .init = cr_redirect_stdout)
{
    va_list ap;
    fstruct_t arg = {0};
    char ref[23] = {0};

    setup_va_list(&ap, &ap);
    arg.info.spec = 'P';
    cr_assert_eq(
        print_pointer(1, &arg, &ap), sprintf(ref, "%#llX", (ullong_t) &ap));
    cr_expect_stdout_eq_str(ref);
    va_end(ap);
}

Test(print_pointer, null_pointer, .init = cr_redirect_stdout)
{
    va_list ap;
    fstruct_t arg = {0};
    char ref[23] = {0};

    setup_va_list(&ap, NULL);
    arg.info.spec = 'p';
    cr_assert_eq(print_pointer(1, &arg, &ap), sprintf(ref, "%p", NULL));
    cr_expect_stdout_eq_str(ref);
    va_end(ap);
}
