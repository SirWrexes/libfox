/*
** (not) EPITECH PROJECT, 2021
** Libfox
** File description:
** Print a non-printable character in octal form in an already allocated string
*/

#include "fox_io.h"

__Anonnull size_t fox_sputchar_oct(str_t s, uchar_t c)
{
    hindex_t i = 1;

    s[0] = '\\';
    s[1] = '0';
    s[2] = '0';
    s[3] = '0';
    do {
        s[i++] = "01234567"[c % 8];
        c /= 8;
    } while (c != 0);
    s[1] ^= s[3];
    s[3] ^= s[1];
    s[1] ^= s[3];
    s[4] = '\0';
    return 4;
}
