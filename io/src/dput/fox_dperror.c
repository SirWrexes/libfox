/*
** EPITECH PROJECT, 2019
** Libfox
** File description:
** Print a message correspoding to last errno status
*/

#include <errno.h>
#include <stdio.h>

#include "define/fox_types.h"
#include "fox_io.h"

scount_t fox_dperror(int fd, str2c_t s)
{
    scount_t r = 0;
    int errsave = errno;

    if (s != NULL && *s != '\0') {
        r += fox_dputstr(fd, s);
        r += fox_dputstr(fd, ": ");
    }
    r += fox_dputstr(fd, sys_errlist[errsave]);
    return r;
}
