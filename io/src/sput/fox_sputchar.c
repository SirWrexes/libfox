/*
** EPITECH PROJECT, 2019
** Libfox
** File description:
** Write a single character to an already allocated string
*/

#include "fox_define.h"

__Anonnull __Aconst extern inline size_t fox_sputchar(str_t s, char c)
{
    *s++ = c;
    *s = '\0';
    return 1;
}
