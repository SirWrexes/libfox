/*
** EPITECH PROJECT, 2019
** Libfox
** File description:
** Count the digits in a number
*/

#include <stddef.h>
#include "fox_define.h"

__const
static size_t fox_nonnull_numsize(llong_t n)
{
    switch (n) {
        case 0: return 0;
        default: return 1 + fox_nonnull_numsize(n / 10);
    }
}

__const
size_t fox_numsize(llong_t n)
{
    switch (n) {
        case 0: return 1;
        default: return fox_nonnull_numsize(n);
    }
}
