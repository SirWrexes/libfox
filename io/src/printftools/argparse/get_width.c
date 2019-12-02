/*
** EPITECH PROJECT, 2019
** Libfox
** File description:
** Get the field width for a format argument
*/

#include "fox_std.h"
#include "printf/fstruct.h"

__Anonnull extern inline void get_width(finfo_t *info, str_t *format)
{
    info->width = (unsigned) fox_strtol(*format, format);
}
