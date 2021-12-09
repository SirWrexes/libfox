/*
** (not) EPITECH PROJECT, 2021
** Libfox
** File description:
** UT: Tokenise a string
*/

#include <string.h>

#include <criterion/criterion.h>
#include <criterion/redirect.h>

#include "fox_string.h"

Test(strtok, regular_usage)
{
    char s1[] = "fixed the israeli-palestinian conflict";
    char s2[] = "fixed the israeli-palestinian conflict";
    str_t t1 = fox_strtok(s1, " ");
    str_t t2 = strtok(s2, " ");

    do {
        cr_expect_str_eq(t1, t2);
        t1 = fox_strtok(NULL, " ");
        t2 = strtok(NULL, " ");
    } while ((ulong_t) t1 | (ulong_t) t2);
    cr_expect_null(t1);
    cr_expect_null(t2);
}
