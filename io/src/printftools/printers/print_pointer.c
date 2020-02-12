/*
** EPITECH PROJECT, 2019
** Libfox
** File description:
** Printing a pointer as its hex value preceeded by 0x
*/

#include <unistd.h>
#include <stdarg.h>

#include "fox_define.h"
#include "fox_io.h"

#include "printf/fstruct.h"
#include "printf/infomask.h"
#include "printf/print_base_extra.h"

__Anonnull static scount_t print_wprefix(ullong_t n, str_t const base[2])
{
    return fox_putstr(base[0]) + fox_putunbr_base(n, base[1]);
}

__Anonnull __AalwaysILext scount_t print_pointer(fstruct_t *arg, va_list *va)
{
    str_t const *b = pick_base(arg->info.spec);
    scount_t (*print)(ullong_t, const str_t[2]) = &print_wprefix;

    arg->value.av_ptr = va_arg(*va, void *);
    arg->info.is_long_long = !(info_to_mask(&arg->info) & MASK_TYPE);
    if (arg->value.av_ptr == NULL)
        arg->chars = write(1, "(nil)", 5);
    else
        switch (info_to_mask(&arg->info) & MASK_TYPE) {
            default: arg->chars = print(arg->value.av_uint, b); break;
            case MASK_CHAR: arg->chars = print(arg->value.av_uchar, b); break;
            case MASK_SHORT: arg->chars = print(arg->value.av_ushort, b);
                break;
            case MASK_LONG: arg->chars = print(arg->value.av_ulong, b); break;
            case MASK_LONGLONG: arg->chars = print(arg->value.av_ullong, b);
                break;
        }
    return arg->chars;
}
