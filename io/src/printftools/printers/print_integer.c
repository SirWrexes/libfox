/*
** EPITECH PROJECT, 2019
** Libfox
** File description:
** Print an integer format argument
*/

#include <stdarg.h>
#include <unistd.h>

#include "fox_define.h"
#include "fox_io.h"

#include "printf/fstruct.h"
#include "printf/infomask.h"

__Anonnull static scount_t showsign_off(llong_t n)
{
    return fox_putnbr(n);
}

__Anonnull static scount_t showsign_on(llong_t n)
{
    return write(1, "+", n >= 0) + fox_putnbr(n);
}

__Anonnull scount_t print_integer(fstruct_t *arg, va_list *va)
{
    scount_t (*print)(llong_t) =
        arg->info.showsign ? &showsign_on : &showsign_off;

    arg->value.av_llong = va_arg(*va, llong_t);
    switch (info_to_mask(&arg->info) & MASK_TYPE) {
        default: arg->chars += print(arg->value.av_int); break;
        case MASK_CHAR: arg->chars += print(arg->value.av_char); break;
        case MASK_SHORT: arg->chars += print(arg->value.av_short); break;
        case MASK_LONG: arg->chars += print(arg->value.av_long); break;
        case MASK_LONGLONG: arg->chars += print(arg->value.av_llong); break;
    }
    return arg->chars;
}
