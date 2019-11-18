/*
** EPITECH PROJECT, 2019
** Libfox
** File description:
** UT: Writing a non-printable character in the form of \xxx
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "fox_io.h"

Test(dputchar_oct, regular_usage, .init = cr_redirect_stdout)
{
    cr_expect_eq(fox_putchar_oct(12), 4);
    cr_expect_stdout_eq_str("\\014");
}

Test(dputchar_oct, printable_char, .init = cr_redirect_stdout)
{
    cr_expect_eq(fox_putchar_oct('a'), 4);
    cr_expect_stdout_eq_str("\\141");
}
