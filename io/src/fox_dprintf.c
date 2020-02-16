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

#include "printf/argparse.h"
#include "printf/errno.h"
#include "printf/fstruct.h"
#include "printf/printers.h"

__Anonnull static ssize_t print_segment(int fd, str2c_t *fmt)
{
    size_t s = 0;
    ssize_t r = 0;

    s = fox_strcspn(*fmt, "%");
    r = write(fd, *fmt, s);
    *fmt += s;
    return r;
}

__Anonnull static ssize_t fox_dprintf_internal(
    int fd, str2c_t format, va_list *va)
{
    ssize_t r = 0;
    fstruct_t arg = {0};

    save_errno();
    do {
        if (*format == '\0')
            break;
        r += print_segment(fd, &format);
        if (*format == '\0')
            break;
        parse_arg(&arg, &format);
        if (arg.info.is_valid)
            r += arg.print(fd, &arg, va);
        else
            r += write(fd, format++, 1);
    } while (true);
    return r;
}

__Aformat(printf, 1, 2) __a((nonnull(1))) ssize_t
    fox_eprintf(str2c_t format, ...)
{
    va_list va;

    va_start(va, format);
    return fox_dprintf_internal(2, format, &va);
}

__Aformat(printf, 2, 3) __a((nonnull(2))) ssize_t
    fox_dprintf(int fd, str2c_t format, ...)
{
    va_list va;

    va_start(va, format);
    return fox_dprintf_internal(fd, format, &va);
}

__Aformat(printf, 1, 2) __a((nonnull(1))) ssize_t
    fox_printf(str2c_t format, ...)
{
    va_list va;

    va_start(va, format);
    return fox_dprintf_internal(1, format, &va);
}
