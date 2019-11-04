/*
** EPITECH PROJECT, 2019
** Libfox
** File description:
** Input/Output header
*/

#ifndef FOX_IO_H
#define FOX_IO_H

#include <sys/types.h>
#include "fox_define.h"

// Print a string to stdout
#define fox_putstr(str) fox_dputstr(1, (str))

// Print a string to stderr
#define fox_eputstr(str) fox_dputstr(2, (str))

// Print a string to a given file descriptor
ssize_t fox_dputstr(int fd, str2c_t str);

#endif /* !FOX_IO_H */
