/*
** EPITECH PROJECT, 2019
** Libfox
** File description:
** Print a string to a given file descriptor including non printables
*/

#include <unistd.h>
#include "fox_define.h"
#include "fox_string.h"
#include "fox_io.h"

extern inline ssize_t fox_dputstr_np(int fd, str2c_t str)
{
    size_t i = 0;
    ssize_t r = 0;

    if (str == NULL)
        return write(fd, "(null)", 6);
    while (true) {
        for (i = 0; CHAR_IS_PRINTABLE(str[i]) || str[i] == '\n'; i += 1) {}
        r += write(fd, str, i);
        str += i;
        if (*str == '\0')
            break;
        r += fox_dputchar_oct(fd, *str++);
    }
    return r;
}
