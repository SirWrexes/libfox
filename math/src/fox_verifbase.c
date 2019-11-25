/*
** EPITECH PROJECT, 2019
** Libfox
** File description:
** Check a that a given base is valid
*/

#include <stdbool.h>
#include "fox_define.h"

__Aconst static uchar_t to_index(char c)
{
    return c - ' ';
}

__Apure __a((nonnull(1))) char fox_verifbase(str2c_t base, size_t *size)
{
    bool table[94] = {false};
    size_t sz = 0;
    uchar_t i;

    while (CHAR_IS_PRINTABLE(*base)) {
        i = to_index(*base);
        if (table[i])
            break;
        table[i] = true;
        base += 1;
        sz += 1;
    }
    if (size != NULL)
        *size = sz;
    return *base;
}
