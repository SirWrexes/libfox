/*
** (not) EPITECH PROJECT, 2021
** Libfox
** File description:
** Print a litteral '%'
*/

#include <stdarg.h>

#include "fox_define.h"
#include "fox_io.h"

#include "printf/fstruct.h"

__Anonnull scount_t print_percent(int fd, fstruct_t *arg, va_list __Aunused *v)
{
    arg->value.av_char = '%';
    arg->chars += fox_dputchar(fd, arg->value.av_char);
    return arg->chars;
}
