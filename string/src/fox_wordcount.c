/*
** (not) EPITECH PROJECT, 2021
** Libfox
** File description:
** Count the words in a string with delim as separator(s)
*/

#include "fox_string.h"

__Anonnull count_t fox_wordcount(str2c_t input, str2c_t delim)
{
    count_t n = 0;

    input += fox_strspn(input, delim);
    while (*input != '\0') {
        n += 1;
        input += fox_strcspn(input, delim);
        input += fox_strspn(input, delim);
    }
    return n;
}
