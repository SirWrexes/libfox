/*
** (not) EPITECH PROJECT, 2021
** Libfox
** File description:
** Print a string format argument
*/

#include <stdarg.h>

#include "fox_define.h"
#include "fox_io.h"

#include "printf/fstruct.h"

__Anonnull scount_t print_string(int fd, fstruct_t *arg, va_list *va)
{
    arg->value.av_str = va_arg(*va, str_t);
    if (arg->info.spec == 's')
        arg->chars = fox_dputstr(fd, arg->value.av_str);
    if (arg->info.spec == 'S')
        arg->chars = fox_dputstr_np(fd, arg->value.av_str);
    return arg->chars;
}
