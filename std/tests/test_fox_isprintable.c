/*
** (not) EPITECH PROJECT, 2021
** Libfox unit tests
** File description:
** UT: Check if a character is printable
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

#include "fox_std.h"

Test(isprintable, regular_usage)
{
    cr_expect_not(fox_isprintable('\a'));
    cr_expect(fox_isprintable('\n'));
    cr_expect_not(fox_isprintable('\032'));
    cr_expect(fox_isprintable(' '));
    cr_expect_not(fox_isprintable('\177'));
}
