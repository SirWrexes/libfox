/*
** (not) EPITECH PROJECT, 2021
** Libfox
** File description:
** Allocate a string and print an unsigned number in given base into it
*/

#include <malloc.h>
#include <sys/types.h>

#include "fox_define.h"
#include "fox_io.h"
#include "fox_math.h"

__Anonnull ssize_t fox_asputunbr_base(str_t *s, ullong_t n, str2c_t base)
{
    ssize_t res;

    *s = malloc(64 * sizeof(*s));
    if (*s == NULL)
        return -1;
    res = fox_sputunbr_base(*s, n, base);
    if (res == -1) {
        free(*s);
        *s = NULL;
    }
    return res;
}
