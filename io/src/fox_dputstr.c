/*
** EPITECH PROJECT, 2019
** Libfox
** File description:
** Print a string to a given file descriptor
*/

#include <unistd.h>
#include "fox_define.h"
#include "fox_string.h"

extern inline ssize_t fox_dputstr(int fd, str2c_t str)
{
    if (str == NULL)
        return write(fd, "(null)", 6);
    return write(fd, str, fox_strlen(str));
}
