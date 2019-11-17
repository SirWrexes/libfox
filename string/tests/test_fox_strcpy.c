/*
** EPITECH PROJECT, 2019
** Libfox
** File description:
** UT: Copying a full string into another
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <string.h>
#include "fox_string.h"

Test(strcpy, regular_usage)
{
    str_t s1 = "Karkat funny boi";
    char s2[strlen(s1) + 1];

    cr_expect_str_eq(fox_strcpy(s2, s1), s1);
}
