/*
** EPITECH PROJECT, 2019
** Libfox
** File description:
** UT: Printing a single character
*/

#include <stdarg.h>

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "tests/printers.h"

#include "printf/fstruct.h"
#include "printf/printers.h"

Test(print_character, regular_usage, .init = cr_redirect_stdout)
{
    va_list ap;
    fstruct_t arg = {0};
    char ref = 'c';

    setup_va_list(&ap, ref);
    cr_assert_eq(print_character(1, &arg, &ap), 1);
    cr_expect_stdout_eq_str("c");
    va_end(ap);
}

Test(print_character, right_padding, .init = cr_redirect_stdout)
{
    va_list ap;
    fstruct_t arg = {0};
    char ref = 'c';

    setup_va_list(&ap, ref);
    arg.info.width = 5;
    cr_assert_eq(print_character(1, &arg, &ap), 5);
    cr_expect_stdout_eq_str("    c");
    va_end(ap);
}

Test(print_character, left_padding, .init = cr_redirect_stdout)
{
    va_list ap;
    fstruct_t arg = {0};
    char ref = 'c';

    setup_va_list(&ap, ref);
    arg.info.width = 5;
    arg.info.left = true;
    cr_assert_eq(print_character(1, &arg, &ap), 5);
    cr_expect_stdout_eq_str("c    ");
    va_end(ap);
}
