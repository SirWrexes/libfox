/*
** EPITECH PROJECT, 2019
** <project name>
** File description:
** fox_asputchar_oct.c -- No description
*/

#include <malloc.h>
#include <sys/types.h>
#include "fox_io.h"
#include "fox_define.h"

__Anonnull
scount_t fox_asputchar_oct(str_t *s, uchar_t c)
{
    *s = malloc(5 * sizeof(**s));
    if (*s == NULL)
        return -1;
    return fox_sputchar_oct(*s, c);
}
