/*
** (not) EPITECH PROJECT, 2021
** Libfox
** File description:
** Get the field width for a format argument
*/

#include "fox_std.h"

#include "printf/fstruct.h"

__Anonnull __AalwaysILext void get_width(finfo_t *info, str_t *format)
{
    info->width = (unsigned) fox_strtol(*format, format);
}
