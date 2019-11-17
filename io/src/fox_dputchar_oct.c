/*
** EPITECH PROJECT, 2019
** Libfox
** File description:
** Print a non-printable character in the form of \xxx
*/

#include <unistd.h>
#include "fox_io.h"

ssize_t fox_dputchar_oct(int fd, uchar_t c)
{
    hindex_t i = 1;
    char conv[4] = "\\000";

    do {
        conv[i++] = "01234567"[c % 8];
        c /= 8;
    } while (c != 0);
    conv[1] ^= conv[3];
    conv[3] ^= conv[1];
    conv[1] ^= conv[3];
    return write(fd, conv, 4);
}
