/*
** EPITECH PROJECT, 2020
** Minishell 1
** File description:
** print_errstr.c -- No description
*/

#include <stdio.h>
#include <stdarg.h>
#include <errno.h>

#include "fox_define.h"
#include "fox_io.h"

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
    arg->value.av_str = sys_errlist[*errno_storage()];
    arg->chars = fox_dputstr(fd, arg->value.av_str);
    return arg->chars;
}
