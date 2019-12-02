/*
** EPITECH PROJECT, 2019
** Libfox
** File description:
** Print an unsigned number in given base into an already allocated string
*/

#include <sys/types.h>

#include "fox_define.h"
#include "fox_math.h"

__Anonnull ssize_t fox_sputunbr_base(str_t s, ullong_t n, str2c_t base)
{
    hindex_t i = 0;
    size_t bs = 0;

    if (fox_verifbase(base, &bs) || bs < 2)
        return -1;
    do {
        s[i++] = base[n % bs];
        n /= bs;
    } while (n != 0);
    for (hindex_t j = 0; j < i / 2; j += 1) {
        s[j] ^= s[i - j - 1];
        s[i - j - 1] ^= s[j];
        s[j] ^= s[i - j - 1];
    }
    return i;
}
