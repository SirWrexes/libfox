/*
** EPITECH PROJECT, 2019
** Libfox
** File description:
** Print a string (including non printables) to a newly allocated pointer
*/

#include <malloc.h>

#include "fox_define.h"
#include "fox_io.h"
#include "fox_std.h"
#include "fox_string.h"

__Apure static count_t getlen(str2c_t str)
{
    count_t i = 0;

    for (; *str != '\0'; str += 1)
        i += fox_isprintable(*str) ? 1 : 4;
    return i;
}

__Anonnull scount_t fox_asputstr_np(str_t *s, str2c_t str)
{
    count_t len = getlen(str);

    *s = malloc((len + 1) * sizeof(**s));
    if (*s == NULL)
        return -1;
    return fox_sputstr_np(*s, str);
}
