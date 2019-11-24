/*
** EPITECH PROJECT, 2019
** Libfox
** File description:
** Write pad n times in already allocated string
*/

#include <unistd.h>
#include "fox_define.h"

__Anonnull __Aconst
count_t fox_siopadn(str_t s, int pad, count_t n)
{
    count_t i = 0;

    while(--n - 1 > 0)
        s[i++] = pad;
    s[i] = '\0';
    return i;
}
