/*
** EPITECH PROJECT, 2019
** Libfox
** File description:
** Print a character format argument
*/

#include <stdarg.h>

#include "fox_define.h"
#include "fox_io.h"

#include "printf/fstruct.h"

__Anonnull scount_t conv_character(fstruct_t *arg, va_list *va)
{
    arg->value.av_uint = va_arg(*va, uint);
    return fox_asputchar(&arg->buff, arg->value.av_uchar);
}
