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
#include "fox_memory.h"
#include "fox_string.h"

#include "printf/argparse.h"
#include "printf/fstruct.h"
#include "printf/printers.h"

__Anonnull static ssize_t print_segment(str2c_t *fmt)
{
    size_t s = 0;
    ssize_t r = 0;

    s = fox_strcspn(*fmt, "%");
    r = write(1, *fmt, s);
    *fmt += s;
    return r;
}

__Aformat(printf, 1, 2) __a((nonnull(1))) ssize_t fox_printf(str2c_t fmt, ...)
{
    va_list va;
    ssize_t r = 0;
    fstruct_t arg = {0};

    va_start(va, fmt);
    while (*fmt) {
        r += print_segment(&fmt);
        if (*fmt == '\0')
            break;
        fox_memset(&arg, 0, sizeof(arg));
        parse_arg(&arg, &fmt);
        if (arg.info.is_valid)
            r += arg.print(&arg, &va);
        else
            r += write(1, fmt++, 1);
    }
    return r;
}
