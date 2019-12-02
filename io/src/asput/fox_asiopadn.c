/*
** EPITECH PROJECT, 2019
** Libfox
** File description:
** Allocate a new string of n length and fill it with pad
*/

#include <malloc.h>

#include "fox_io.h"

__Anonnull scount_t fox_asiopadn(str_t *s, uchar_t pad, scount_t n)
{
    *s = malloc((n + 1) * sizeof(**s));
    if (*s == NULL)
        return -1;
    return fox_siopadn(*s, pad, n);
}
