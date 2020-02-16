/*
** EPITECH PROJECT, 2019
** Libfox
** File description:
** Print an unsigned format argument
*/

#include <stdarg.h>
#include "fox_define.h"
#include "fox_io.h"

#include "printf/fstruct.h"
#include "printf/infomask.h"
#include "printf/printers.h"

__Anonnull scount_t print_unsigned(int fd, fstruct_t *arg, va_list *va)
{
    arg->value.av_ullong = va_arg(*va, ullong_t);
    switch (info_to_mask(&arg->info) & MASK_TYPE) {
        default: arg->chars = fox_dputunbr(fd, arg->value.av_uint); break;
        case MASK_CHAR:
            arg->chars = fox_dputunbr(fd, arg->value.av_uchar);
            break;
        case MASK_SHORT:
            arg->chars = fox_dputunbr(fd, arg->value.av_ushort);
            break;
        case MASK_LONG:
            arg->chars = fox_dputunbr(fd, arg->value.av_ulong);
            break;
        case MASK_LONGLONG:
            arg->chars = fox_dputunbr(fd, arg->value.av_ullong);
            break;
    }
    return arg->chars;
}
