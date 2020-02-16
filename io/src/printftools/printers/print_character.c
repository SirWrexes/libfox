/*
** EPITECH PROJECT, 2019
** Libfox
** File description:
** Print a character format argument
*/

#include <stdarg.h>

#include "fox_define.h"
#include "fox_io.h"

#include "printf/fstruct.h"

__Anonnull scount_t print_character(int fd, fstruct_t *arg, va_list *va)
{
    arg->value.av_uint = va_arg(*va, uint);
    if (arg->info.width && arg->info.left == false)
        arg->chars += fox_diopadn(fd, ' ', arg->info.width - 1);
    arg->chars += fox_dputchar(fd, arg->value.av_uchar);
    if (arg->info.width && arg->info.left == true)
        arg->chars += fox_diopadn(fd, ' ', arg->info.width - 1);
    return arg->chars;
}
