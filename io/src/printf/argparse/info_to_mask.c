/*
** EPITECH PROJECT, 2019
** Libfox
** File description:
** Convert an info structur to a binary mask
*/

#include "fox_define.h"

#include "args/farg_datastruct.h"

__nonnull
extern inline bmask_t info_to_mask(finfo_t *info)
{
    return info->is_char << 0
        | info->is_short << 1
        | info->is_long << 2
        | info->is_long_long << 3
        | info->is_long_double << 4;
}
