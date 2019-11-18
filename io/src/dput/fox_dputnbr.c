/*
** EPITECH PROJECT, 2019
** Libfox
** File description:
** Write a number to a given file descriptor
*/

#include <unistd.h>
#include <stdbool.h>
#include "fox_define.h"
#include "fox_math.h"

ssize_t fox_dputnbr(int fd, llong_t n)
{
    bool isneg = (n < 0);
    size_t sz = fox_numsize(n);
    char conv[sz];

    for (hindex_t i = 0; i < sz; i += 1) {
        conv[i] = N_TO_CHAR(N_ABS(n % 10));
        n /= 10;
    }
    for (hindex_t i = 0; i < sz / 2; i += 1) {
        conv[i] ^= conv[sz - i - 1];
        conv[sz - i - 1] ^= conv[i];
        conv[i] ^= conv[sz - i - 1];
    }
    return write(fd, "-", isneg) + write(fd, conv, sz);
}
