/*
** EPITECH PROJECT, 2019
** Libfox
** File description:
** Print an integer format argument
*/

#include <unistd.h>
#include <stdarg.h>
#include "fox_io.h"
#include "fox_define.h"

#include "args/farg_datastruct.h"
#include "args/infomask.h"

__nonnull
static scount_t showsign_off(llong_t n)
{
    return fox_putnbr(n);
}

__nonnull
static scount_t showsign_on(llong_t n)
{
    return write(1, "+", n >= 0) + fox_putnbr(n);
}

__nonnull
scount_t print_integer(fstruct_t *arg, va_list *va)
{
    scount_t (*print)(llong_t) = arg->info.showsign
        ? &showsign_on : &showsign_off;

    arg->value.pa_llong = va_arg(*va, llong_t);
    switch (info_to_mask(&arg->info)) {
        default: arg->chars += print(arg->value.pa_int); break;
        case MASK_CHAR: arg->chars += print(arg->value.pa_char); break;
        case MASK_SHORT: arg->chars += print(arg->value.pa_short); break;
        case MASK_LONG: arg->chars += print(arg->value.pa_long); break;
        case MASK_LONGLONG: arg->chars += print(arg->value.pa_llong); break;
    }
    return arg->chars;
}
