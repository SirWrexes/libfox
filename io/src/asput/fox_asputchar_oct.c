/*
** (not) EPITECH PROJECT, 2021
** Libfox
** File description:
** Allocate a string and print an octal value into it
*/

#include <malloc.h>
#include <sys/types.h>

#include "fox_define.h"
#include "fox_io.h"

__Anonnull scount_t fox_asputchar_oct(str_t *s, uchar_t c)
{
    *s = malloc(5 * sizeof(**s));
    if (*s == NULL)
        return -1;
    return fox_sputchar_oct(*s, c);
}
