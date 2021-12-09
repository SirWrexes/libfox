/*
** (not) EPITECH PROJECT, 2021
** Libfox
** File description:
** UT: Print a string format argument
*/

#include <string.h>

#include <criterion/criterion.h>
#include <criterion/redirect.h>

#include "tests/printers.h"

#include "printf/fstruct.h"
#include "printf/printers.h"

Test(print_string, regular_usage, .init = cr_redirect_stdout)
{
    va_list va;
    fstruct_t arg = {0};
    str_t ref = "Acrobatic fucking pirouette";

    setup_va_list(&va, ref);
    arg.info.spec = 's';
    cr_assert_eq(print_string(1, &arg, &va), (scount_t) strlen(ref));
    cr_expect_stdout_eq_str(ref);
    va_end(va);
}

Test(print_string, non_printables, .init = cr_redirect_stdout)
{
    va_list va;
    fstruct_t arg = {0};
    str_t str = "\007ff the\014 handle";
    str_t ref = "\\007ff the\\014 handle";

    setup_va_list(&va, str);
    arg.info.spec = 'S';
    cr_assert_eq(print_string(1, &arg, &va), (scount_t) strlen(ref));
    cr_expect_stdout_eq_str(ref);
    va_end(va);
}

Test(print_string, null_string, .init = cr_redirect_stdout)
{
    va_list va;
    fstruct_t arg = {0};
    str_t ref = "(null)";

    setup_va_list(&va, NULL);
    arg.info.spec = 's';
    cr_assert_eq(print_string(1, &arg, &va), (scount_t) strlen(ref));
    cr_expect_stdout_eq_str(ref);
    va_end(va);
}
