/*
** EPITECH PROJECT, 2019
** Libfox
** File description:
** UT: Copying up to n chars of a string into another
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <signal.h>
#include "fox_string.h"

Test(fox_strncpy, n_gt_src_len)
{
    char dest[30] = "You want the truth ?";
    char src[30] = "You can't handle the truth !";

    cr_expect_arr_eq(fox_strncpy(dest, src, 50), src, strlen(src));
}

Test(fox_strncpy, n_lt_src_len)
{
    char dest[30] = "You want the truth ?";
    char src[30] = "You can't handle the truth !";

    cr_expect_arr_eq(fox_strncpy(dest, src, 9), src, 9);
}

Test(fox_strncpy, n_lt_dest_len)
{
    char dest[30] = "Cheese Harissa";
    char src[30] = "Poivre";

    cr_expect_str_eq(fox_strncpy(dest, src, 7), "Poivre");
}

Test(fox_strncpy, n_lt_both_len)
{
    char dest[30] = "suce";
    char src[30] = "pute";

    cr_expect_str_eq(fox_strncpy(dest, src, 12), "pute");
}
