/*
** EPITECH PROJECT, 2019
** Libfox
** File description:
** Write pad n times
*/

#include <unistd.h>
#include "statics/fox_diopadn.h"
#include "fox_define.h"

static str_t set_padbuff(char padbuff[PADSIZE], uchar_t pad)
{
    for (hindex_t i = 0; i < PADSIZE; i += 1)
        padbuff[i] = pad;
    return padbuff;
}

scount_t fox_diopadn(int fd, int pad, count_t n)
{
    char padbuff[PADSIZE];
    str2c_t padptr;
    scount_t w = 0;

    switch (pad) {
        case ' ': padptr = BLANKS; break;
        case '0': padptr = ZEROES; break;
        default : padptr = set_padbuff(padbuff, pad); break;
    }
    for (; n >= PADSIZE; n -= PADSIZE)
        w += write(fd, padptr, PADSIZE);
    if (n > 0)
        return w + write(fd, padptr, n);
    return w;
}
