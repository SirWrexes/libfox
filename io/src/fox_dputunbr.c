/*
** EPITECH PROJECT, 2019
** Libfox
** File description:
** Print an unsigned number
*/

#include <unistd.h>
#include "fox_define.h"
#include "fox_math.h"

ssize_t fox_dputunbr(int fd, ullong_t n)
{
    size_t sz = fox_unumsize(n);
    char conv[sz];

    for (hindex_t i = 0; i < sz; i += 1) {
        conv[i] = N_TO_CHAR(n % 10);
        n /= 10;
    }
    for (hindex_t i = 0; i < sz / 2; i += 1) {
        conv[i] ^= conv[sz - i - 1];
        conv[sz - i - 1] ^= conv[i];
        conv[i] ^= conv[sz - i - 1];
    }
    return write(fd, conv, sz);
}
