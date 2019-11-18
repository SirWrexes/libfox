/*
** EPITECH PROJECT, 2019
** Libfox
** File description:
** Write a single character
*/

#include <unistd.h>

extern inline ssize_t fox_dputchar(int fd, char c)
{
    return write(fd, &c, 1);
}
