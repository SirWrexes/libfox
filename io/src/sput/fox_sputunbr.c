/*
** EPITECH PROJECT, 2019
** Libfox
** File description:
** Write an unsigned integer to already allocated s
*/

#include <stdbool.h>
#include <sys/types.h>

#include "fox_define.h"
#include "fox_math.h"
#include "fox_string.h"

__Anonnull ssize_t fox_sputunbr(str_t s, ullong_t n)
{
    size_t sz = fox_unumsize(n);

    for (hindex_t i = 0; i < sz; i += 1) {
        s[i] = N_TO_CHAR(n % 10);
        n /= 10;
    }
    for (hindex_t i = 0; i < sz / 2; i += 1) {
        s[i] ^= s[sz - i - 1];
        s[sz - i - 1] ^= s[i];
        s[i] ^= s[sz - i - 1];
    }
    s[sz] = '\0';
    return sz;
}
