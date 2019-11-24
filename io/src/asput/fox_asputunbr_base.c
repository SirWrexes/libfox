/*
** EPITECH PROJECT, 2019
** Libfox
** File description:
** Print an unsigned number in given base into a newly allocated string
*/

#include <sys/types.h>
#include <malloc.h>
#include "fox_math.h"
#include "fox_io.h"
#include "fox_define.h"

__Anonnull
ssize_t fox_asputunbr_base(str_t *s, ullong_t n, str2c_t base)
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
