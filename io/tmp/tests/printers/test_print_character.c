/*
** EPITECH PROJECT, 2019
** Libfox
** File description:
** UT: Printing a single character
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <stdarg.h>
#include "tests/printers.h"

#include "printers.h"
#include "args/farg_datastruct.h"

Test(print_character, regular_usage, .init = cr_redirect_stdout)
{
    va_list ap;
    fstruct_t arg = {0};
    char ref = 'c';

    setup_va_list(&ap, ref);
    cr_assert_eq(print_character(&arg, &ap), 1);
    cr_expect_stdout_eq_str("c");
    va_end(ap);
}
