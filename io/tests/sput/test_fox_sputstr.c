/*
** (not) EPITECH PROJECT, 2021
** Libfox
** File description:
** UT: Writ a string into an other already allocated string
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <string.h>
#include "fox_io.h"

Test(sputstr, regular_usage)
{
    char res[] = {[0 ... 30] = '\0'};
    str_t ref = "Je fume des coquelicots";

    cr_expect_eq(fox_sputstr(res, ref), strlen(ref));
    cr_expect_str_eq(res, ref);
}
