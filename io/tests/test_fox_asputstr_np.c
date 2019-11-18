/*
** EPITECH PROJECT, 2019
** Libfox
** File description:
** UT: Printing a string (including non-printables) to a new pointer
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "tests/wrap_malloc.h"
#include "fox_io.h"

Test(asputstr_np, regular_usage)
{
    char str[] = "J'ai \023 perdu.\177\n";
    char ref[] = {[0 ... 30] = '\0'};
    str_t res = NULL;

    cr_expect_eq(
        fox_asputstr_np(&res, str), sprintf(ref, "J'ai \\023 perdu.\\177\n"));
    cr_assert_not_null(res);
    cr_expect_str_eq(res, ref);
}

Test(asputstr_np, broken_malloc, .init = break_malloc, .fini = fix_malloc)
{
    str_t res = NULL;

    cr_expect_eq(fox_asputstr_np(&res, "raté"), -1);
    cr_expect_null(res);
}
