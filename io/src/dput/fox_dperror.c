/*
** (not) EPITECH PROJECT, 2021
** Libfox
** File description:
** Print a message correspoding to last errno value
*/

#include <errno.h>
#include <stdio.h>
#include "printf/errno.h"

#include "fox_io.h"
#include "fox_types.h"
#include "fox_string.h"

scount_t fox_dperror(int fd, str2c_t s)
{
    scount_t r = 0;
    int errsave = errno;

    if (s != NULL && *s != '\0') {
        r += fox_dputstr(fd, s);
        r += fox_dputstr(fd, ": ");
    }
    r += fox_dputstr(fd, fox_strerror(errsave));
    return r;
}
