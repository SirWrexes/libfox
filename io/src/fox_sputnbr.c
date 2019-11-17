/*
** EPITECH PROJECT, 2019
** Libfox
** File description:
** Write a number to an already allocated string
*/

#include <stdbool.h>
#include <sys/types.h>
#include "fox_math.h"
#include "fox_string.h"
#include "fox_define.h"

__nonnull
ssize_t fox_sputnbr(str_t s, llong_t n)
{
    bool isneg = (n < 0);
    size_t sz = fox_numsize(n);

    *s = '-' * isneg;
    s += isneg;
    for (hindex_t i = 0; i < sz; i += 1) {
        s[i] = N_TO_CHAR(N_ABS(n % 10));
        n /= 10;
    }
    for (hindex_t i = 0; i < sz / 2; i += 1) {
        s[i] ^= s[sz - i - 1];
        s[sz - i - 1] ^= s[i];
        s[i] ^= s[sz - i - 1];
    }
    s[sz] = '\0';
    return sz + isneg;
}
