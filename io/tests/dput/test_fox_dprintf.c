/*
** (not) EPITECH PROJECT, 2021
** Libfox
** File description:
** UT: Print a format string with multiple conversion specifiers at once
*/

#define _GNU_SOURCE
#include <stdio.h>

#include <criterion/criterion.h>
#include <criterion/redirect.h>

#include "fox_io.h"

Test(dprintf, mixed_string_and_number, .init = cr_redirect_stdout)
{
    str_t ref = NULL;
    str2c_t s = "Astek";
    int d = 42;

    cr_expect_eq(fox_printf("%%s%%d%s%d%%\n", s, d),
        asprintf(&ref, "%%s%%d%s%d%%\n", s, d));
    cr_expect_stdout_eq_str(ref);
}
