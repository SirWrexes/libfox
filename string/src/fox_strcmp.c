/*
** EPITECH PROJECT, 2019
** Libfox
** File description:
** Check if two strings are identical
*/

#include "fox_define.h"

__Anonnull __Apure
char fox_strcmp(str2c_t s1, str2c_t s2)
{
    char c1 = '\0';
    char c2 = '\0';

    do {
        c1 = (uchar_t) *s1++;
        c2 = (uchar_t) *s2++;
        if (c1 == '\0')
            return c1 - c2;
    } while (c1 == c2);
    return c1 - c2;
}
