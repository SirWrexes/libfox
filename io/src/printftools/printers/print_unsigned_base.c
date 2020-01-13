/*
** EPITECH PROJECT, 2019
** Libfox
** File description:
** Printing a number in hexadecimal
*/

#include <stdarg.h>
#include <unistd.h>

#include "fox_define.h"
#include "fox_io.h"

#include "printf/fstruct.h"
#include "printf/infomask.h"
#include "printf/print_base_extra.h"

__Anonnull static scount_t alt_off(ullong_t n, str_t const base[2])
{
    return fox_putunbr_base(n, base[1]);
}

__Anonnull static scount_t alt_on(ullong_t n, str_t const base[2])
{
    return fox_putstr(base[0]) + fox_putunbr_base(n, base[1]);
}

__Anonnull scount_t print_unsigned_base(fstruct_t *arg, va_list *va)
{
    str_t const *b = pick_base(arg->info.spec);
    scount_t (*print)(ullong_t, const str_t[2]) =
        arg->info.alt ? &alt_on : &alt_off;

    arg->value.av_ullong = va_arg(*va, ullong_t);
    switch (info_to_mask(&arg->info)) {
        default: arg->chars = print(arg->value.av_uint, b); break;
        case MASK_CHAR: arg->chars = print(arg->value.av_uchar, b); break;
        case MASK_SHORT: arg->chars = print(arg->value.av_ushort, b); break;
        case MASK_LONG: arg->chars = print(arg->value.av_ulong, b); break;
        case MASK_LONGLONG: arg->chars = print(arg->value.av_ullong, b); break;
    }
    return arg->chars;
}
