/*
** (not) EPITECH PROJECT, 2021
** Libfox
** File description:
** Print the last errno value's corresponding message as format argument
*/

#include <stdio.h>
#include <stdarg.h>
#include <errno.h>

#include <stdlib.h>
#include <string.h>

#include "fox_define.h"
#include "fox_io.h"
#include "fox_string.h"

#include "printf/errno.h"
#include "printf/fstruct.h"

__Aconst static int *errno_storage(void)
{
    static int errsto = 0;

    return &errsto;
}

__AalwaysILext void save_errno(void)
{
    *errno_storage() = errno;
}

scount_t print_strerror(int fd, fstruct_t *arg, __Aunused va_list *va)
{
    arg->value.av_str = fox_strerror(*errno_storage());
    arg->chars = fox_dputstr(fd, arg->value.av_str);
    return arg->chars;
}
