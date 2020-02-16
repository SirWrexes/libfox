/*
** EPITECH PROJECT, 2019
** Libfox
** File description:
** Wiritng a whole string
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
