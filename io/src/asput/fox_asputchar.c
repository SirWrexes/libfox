/*
** (not) EPITECH PROJECT, 2021
** Libfox
** File description:
** Allocate a string and print a single character into it
*/

#include <malloc.h>

#include "fox_io.h"

__Anonnull scount_t fox_asputchar(str_t *s, char c)
{
    *s = malloc(2 * sizeof(**s));
    if (*s == NULL)
        return -1;
    return fox_sputchar(*s, c);
}
