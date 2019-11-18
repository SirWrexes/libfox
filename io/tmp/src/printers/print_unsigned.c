/*
** EPITECH PROJECT, 2019
** Libfox
** File description:
** Print an unsigned format argument
*/

#include <stdarg.h>
#include "fox_io.h"
#include "fox_define.h"

#include "args/farg_datastruct.h"
#include "args/infomask.h"

__nonnull
scount_t print_unsigned(fstruct_t *arg, va_list *va)
{
    arg->value.pa_ullong = va_arg(*va, ullong_t);
    switch (info_to_mask(&arg->info)) {
        default: arg->chars = fox_putunbr(arg->value.pa_uint);
            break;
        case MASK_CHAR: arg->chars = fox_putunbr(arg->value.pa_uchar);
            break;
        case MASK_SHORT: arg->chars = fox_putunbr(arg->value.pa_ushort);
            break;
        case MASK_LONG: arg->chars = fox_putunbr(arg->value.pa_ulong);
            break;
        case MASK_LONGLONG: arg->chars = fox_putunbr(arg->value.pa_ullong);
            break;
    }
    return arg->chars;
}
