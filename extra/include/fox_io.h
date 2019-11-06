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

// Print a single character to a given file descriptor
ssize_t fox_dputchar(int fd, char c);
#define fox_putchar(c)  fox_dputchar(1, c) // -> STDOUT
#define fox_eputchar(c) fox_dputchar(2, c) // -> STDERR

// Print a string to a given file descriptor
ssize_t fox_dputstr(int fd, str2c_t str);
#define fox_putstr(str)  fox_dputstr(1, (str)) // -> STDOUT
#define fox_eputstr(str) fox_dputstr(2, (str)) // -> STDERR

// Print a number to a given file descriptor
size_t fox_dputnbr(int fd, long long n);
#define fox_putnbr(n)  fox_dputnbr(1, (n)) // -> STDOUT
#define fox_eputnbr(n) fox_dputnbr(2, (n)) // -> STDERR

#endif /* !FOX_IO_H */
