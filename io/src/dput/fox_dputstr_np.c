/*
** (not) EPITECH PROJECT, 2021
** Libfox
** File description:
** Print a string to a given file descriptor including non printables
*/

#include <unistd.h>

#include "fox_io.h"
#include "fox_macro.h"
#include "fox_memory.h"
#include "fox_std.h"
#include "fox_types.h"

__Apure static count_t getlen(str2c_t str)
{
    count_t i = 0;

    for (; *str != '\0'; str += 1)
        i += fox_isprintable(*str) ? 1 : 4;
    return i;
}

static scount_t putstrnp_nonnull(int fd, str2c_t str)
{
    count_t ln = getlen(str);
    char buff[ln];

    fox_memset(buff, '\0', ln);
    return write(fd, buff, fox_sputstr_np(buff, str));
}

scount_t fox_dputstr_np(int fd, str2c_t str)
{
    if (str == NULL)
        return write(fd, "(null)", 6);
    return putstrnp_nonnull(fd, str);
}
