/*
** EPITECH PROJECT, 2020
** Libfox
** File description:
** UT: Counting words in a string
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

#include "fox_string.h"

Test(wordcount, regular_usage)
{
    cr_expect_eq(fox_wordcount("::a:b::::c:d:::", ":"), 4);
    cr_expect_eq(fox_wordcount("aeiou swag lol", "1"), 1);
    cr_expect_eq(fox_wordcount("cocorico fils de pute", STR_WHITESPACE), 4);
    cr_expect_eq(fox_wordcount("top kek", "top ke"), 0);
}
