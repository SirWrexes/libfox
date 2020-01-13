/*
** EPITECH PROJECT, 2019
** Libfox
** File description:
** Wiritng a whole string
*/

#include <stdarg.h>
#include "fox_io.h"
#include "fox_define.h"

#include "args/farg_datastruct.h"

__nonnull
scount_t print_string(fstruct_t *arg, va_list *va)
{
    arg->value.va_str = va_arg(*va, str_t);
    if (arg->info.spec == 's')
        arg->chars = fox_putstr(arg->value.va_str);
    if (arg->info.spec == 'S')
        arg->chars = fox_putstr_np(arg->value.va_str);
    return arg->chars;
}
