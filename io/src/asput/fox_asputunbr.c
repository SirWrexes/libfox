/*
** (not) EPITECH PROJECT, 2021
** Libfox
** File description:
** Allocate a string and print an unsigned number into it
*/

#include <malloc.h>
#include <stdbool.h>
#include <sys/types.h>

#include "fox_define.h"
#include "fox_io.h"
#include "fox_math.h"

__Anonnull scount_t fox_asputunbr(str_t *s, ullong_t n)
{
    *s = malloc((fox_unumsize(n) + 1) * sizeof(**s));
    if (*s == NULL)
        return -1;
    return fox_sputunbr(*s, n);
}
