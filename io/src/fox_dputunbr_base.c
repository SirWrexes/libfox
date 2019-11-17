/*
** EPITECH PROJECT, 2019
** Libfox
** File description:
** Write a number in given base
*/

#include <unistd.h>
#include "fox_define.h"
#include "fox_math.h"

ssize_t fox_dputunbr_base(int fd, ullong_t n, str2c_t base)
{
    hindex_t i = 0;
    char conv[64] = {0};
    size_t bs = 0;

    if (fox_verifbase(base, &bs) || bs < 2)
        return -1;
    do {
        conv[i++] = base[n % bs];
        n /= bs;
    } while (n != 0);
    for (hindex_t j = 0; j < i / 2; j += 1) {
        conv[j] ^= conv[i - j - 1];
        conv[i - j - 1] ^= conv[j];
        conv[j] ^= conv[i - j - 1];
    }
    return write(fd, conv, i);
}
