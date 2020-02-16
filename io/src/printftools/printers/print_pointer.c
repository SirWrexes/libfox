/*
** EPITECH PROJECT, 2019
** Libfox
** File description:
** Printing a pointer as its hex value preceeded by 0x
*/

#include <stdarg.h>
#include <unistd.h>

#include "fox_define.h"
#include "fox_io.h"

#include "printf/fstruct.h"
#include "printf/infomask.h"
#include "printf/print_base_extra.h"

__Anonnull static scount_t print_wprefix(int fd, ullong_t n, str_t const *base)
{
    return fox_dputstr(fd, base[0]) + fox_dputunbr_base(fd, n, base[1]);
}

__Anonnull static scount_t print_nonnull(int fd, fstruct_t *arg)
{
    str_t const *b = pick_base(arg->info.spec);
    scount_t (*print)(int fd, ullong_t n, str_t const *base) = &print_wprefix;

    switch (info_to_mask(&arg->info) & MASK_TYPE) {
        default: return print(fd, arg->value.av_uint, b);
        case MASK_CHAR: return print(fd, arg->value.av_uchar, b);
        case MASK_SHORT: return print(fd, arg->value.av_ushort, b);
        case MASK_LONG: return print(fd, arg->value.av_ulong, b);
        case MASK_LONGLONG: return print(fd, arg->value.av_ullong, b);
    }
}

__Anonnull scount_t print_pointer(int fd, fstruct_t *arg, va_list *va)
{
    arg->value.av_ptr = va_arg(*va, void *);
    arg->info.is_long_long = !(info_to_mask(&arg->info) & MASK_TYPE);
    if (arg->value.av_ptr == NULL)
        arg->chars = write(fd, "(nil)", 5);
    else
        arg->chars = print_nonnull(fd, arg);
    return arg->chars;
}
