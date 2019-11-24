/*
** EPITECH PROJECT, 2019
** Libfox
** File description:
** Check if two strings are identical up to n chars
*/

#include "fox_define.h"

__Anonnull __Apure
char fox_strncmp(str2c_t s1, str2c_t s2, unsigned n)
{
    uchar_t c1 = '\0';
    uchar_t c2 = '\0';

    while (n > 0) {
        c1 = (uchar_t) *s1++;
        c2 = (uchar_t) *s2++;
        if (c1 == '\0' || c1 != c2)
            return c1 - c2;
        n -= 1;
    }
    return c1 - c2;
}
