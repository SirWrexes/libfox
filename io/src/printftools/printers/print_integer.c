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
#include "fox_math.h"

#include "printf/fstruct.h"
#include "printf/infomask.h"

__Anonnull static scount_t showsign_off(int fd, llong_t n)
{
    return fox_dputnbr(fd, n);
}

__Anonnull static scount_t showsign_on(int fd, llong_t n)
{
    return write(fd, "+", n >= 0) + fox_dputnbr(fd, n);
}

__Anonnull static size_t get_width(fstruct_t *arg, bmask_t typemask)
{
    switch (typemask) {
        default:
            return (arg->info.showsign || arg->value.av_int < 0)
                + fox_numsize(arg->value.av_int);
        case MASK_CHAR:
            return (arg->info.showsign || arg->value.av_char < 0)
                + fox_numsize(arg->value.av_char < 0);
        case MASK_SHORT:
            return (arg->info.showsign || arg->value.av_short < 0)
                + fox_numsize(arg->value.av_short < 0);
        case MASK_LONG:
            return (arg->info.showsign || arg->value.av_long < 0)
                + fox_numsize(arg->value.av_long < 0);
        case MASK_LONGLONG:
            return (arg->info.showsign || arg->value.av_llong < 0)
                + fox_numsize(arg->value.av_llong < 0);
    }
}

__Anonnull scount_t print_integer(int fd, fstruct_t *arg, va_list *va)
{
    size_t padding;
    scount_t (*print)(int fd, llong_t val) =
        arg->info.showsign ? &showsign_on : &showsign_off;
    bmask_t typemask = info_to_mask(&arg->info) & MASK_TYPE;

    arg->value.av_llong = va_arg(*va, llong_t);
    padding = get_width(arg, typemask);
    padding = arg->info.width > padding ? arg->info.width - padding : 0;
    if (padding && arg->info.left == false)
        arg->chars += fox_diopadn(fd, arg->info.padchar, padding);
    switch (typemask) {
        default: arg->chars += print(fd, arg->value.av_int); break;
        case MASK_CHAR: arg->chars += print(fd, arg->value.av_char); break;
        case MASK_SHORT: arg->chars += print(fd, arg->value.av_short); break;
        case MASK_LONG: arg->chars += print(fd, arg->value.av_long); break;
        case MASK_LONGLONG:
            arg->chars += print(fd, arg->value.av_llong);
            break;
    }
    if (padding && arg->info.left == true)
        arg->chars += fox_diopadn(fd, ' ', padding);
    return arg->chars;
}
