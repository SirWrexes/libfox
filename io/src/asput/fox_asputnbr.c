/*
** (not) EPITECH PROJECT, 2021
** Libfox
** File description:
** Allocate a string and print a number into it
*/

#include <malloc.h>
#include <sys/types.h>

#include "fox_define.h"
#include "fox_io.h"
#include "fox_math.h"

__Anonnull scount_t fox_asputnbr(str_t *s, llong_t n)
{
    *s = malloc((fox_numsize(n) + (n < 0) + 1) * sizeof(**s));
    if (*s == NULL)
        return -1;
    return fox_sputnbr(*s, n);
}
