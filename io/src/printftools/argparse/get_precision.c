/*
** EPITECH PROJECT, 2019
** Libfox
** File description:
** Get thte precision of float printing
*/

#include "fox_std.h"

#include "args/farg_datastruct.h"

__Anonnull
extern inline void get_precision(finfo_t *info, str_t *format)
{
    long tmp = 0;
    str_t end = NULL;

    if (**format != '.')
        return;
    tmp = fox_strtol(*format + 1, &end);
    if (tmp < 0)
        info->is_valid = false;
    else {
        info->prec = tmp;
        *format = end;
    }
}
