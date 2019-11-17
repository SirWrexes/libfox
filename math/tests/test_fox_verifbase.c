/*
** EPITECH PROJECT, 2019
** Libfox
** File description:
** UT: Base validity check
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "fox_define.h"
#include "fox_math.h"

Test(verifbase, regular_usage)
{
    str2c_t base = "0123456789abcdef";
    size_t size = 0;

    cr_expect_not(fox_verifbase(base, NULL));
    cr_expect_not(fox_verifbase(base, &size));
    cr_expect_eq(size, 16);
}

Test(verifbase, duplicate_character)
{
    str2c_t base = "01234560123";
    size_t size = 0;

    cr_expect_eq(fox_verifbase(base, &size), '0');
    cr_expect_eq(base[size], '0');
    cr_expect_neq(size, 0);
}

Test(verifbase, non_printable)
{
    str2c_t base = "pedo\ncule de navet";
    char extra[] = {'a', 'e', 'i', 127};

    cr_expect_eq(fox_verifbase(base, NULL), '\n');
    cr_expect_eq(fox_verifbase(extra, NULL), 127, "extra branch testing");
}
