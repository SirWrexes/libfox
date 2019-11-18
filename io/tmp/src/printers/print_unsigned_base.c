/*
** EPITECH PROJECT, 2019
** Libfox
** File description:
** Printing a number in hexadecimal
*/

#include <unistd.h>
#include <stdarg.h>
#include "fox_io.h"
#include "fox_define.h"

#include "private/print_base_extra.h"
#include "args/farg_datastruct.h"
#include "args/infomask.h"


__nonnull
static scount_t alt_off(ullong_t n, str_t const base[2])
{
    return fox_putunbr_base(n, base[1]);
}

__nonnull
static scount_t alt_on(ullong_t n, str_t const base[2])
{
    return fox_putstr(base[0]) + fox_putunbr_base(n, base[1]);
}

__nonnull
scount_t print_unsigned_base(fstruct_t *arg, va_list *va)
{
    str_t const *b = pick_base(arg->info.spec);
    scount_t (*print)(ullong_t, const str_t[2]) = arg->info.alt
        ? &alt_on : &alt_off;

    arg->value.pa_ullong = va_arg(*va, ullong_t);
    switch (info_to_mask(&arg->info)) {
        default: arg->chars = print(arg->value.pa_uint, b); break;
        case MASK_CHAR: arg->chars = print(arg->value.pa_uchar, b); break;
        case MASK_SHORT: arg->chars = print(arg->value.pa_ushort, b); break;
        case MASK_LONG: arg->chars = print(arg->value.pa_ulong, b); break;
        case MASK_LONGLONG: arg->chars = print(arg->value.pa_ullong, b); break;
    }
    return arg->chars;
}
