/*
** EPITECH PROJECT, 2019
** Libfox
** File description:
** Personal implementation of libc's printf
*/

#include <stdarg.h>
#include <unistd.h>
#include "fox_define.h"
#include "fox_io.h"
#include "fox_string.h"

#include "args/farg_datastruct.h"
#include "args/parsers.h"

__nonnull static void reset_fstruct(fstruct_t *arg)
{
    arg->info.prec = 0;
    arg->info.width = 0;
    arg->info.spec = 0;
    arg->info.is_valid = true;
    arg->info.is_char = false;
    arg->info.is_short = false;
    arg->info.is_long = false;
    arg->info.is_long_long = false;
    arg->info.is_long_double = false;
    arg->info.alt = false;
    arg->info.group = false;
    arg->info.left = false;
    arg->info.showsign = false;
    arg->info.space = false;
    arg->info.zeropad = false;
    arg->value.pa_ullong = 0;
    arg->chars = 0;
    arg->fmt = NULL;
    arg->print = NULL;
}

__nonnull static ssize_t print_segment(str_t *fmt)
{
    size_t s = 0;
    ssize_t r = 0;

    s = fox_strcspn(*fmt, "%");
    r = write(1, *fmt, s);
    *fmt += s;
    return r;
}

__format(printf, 1, 2) __a((nonnull(1))) ssize_t my_printf(str_t fmt, ...)
{
    va_list va;
    ssize_t r = 0;
    fstruct_t arg = {0};

    va_start(va, fmt);
    while (*fmt) {
        r += print_segment(&fmt);
        if (*fmt == '\0')
            break;
        parse_arg(&arg, &fmt);
        if (arg.info.is_valid)
            r += arg.print(&arg, &va);
        else
            r += write(1, fmt++, 1);
        reset_fstruct(&arg);
    }
    return r;
}
