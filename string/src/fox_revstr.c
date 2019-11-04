/*
** EPITECH PROJECT, 2019
** Libfox
** File description:
** Revert a string
*/

#include "fox_define.h"
#include "fox_string.h"

__nonnull
str_t fox_revstr(str_t s)
{
    char c;
    size_t len = fox_strlen(s);

    for (size_t i = 0; i < len / 2; i += 1) {
        c = s[i];
        s[i] = s[len - i - 1];
        s[len - i - 1] = c;
    }
    return s;
}
