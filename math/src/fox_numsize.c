/*
** EPITECH PROJECT, 2019
** Libfox
** File description:
** Count the digits in a number
*/

#include <stddef.h>
#include "preprocessor/fox_macro.h"

__const
size_t fox_nonnull_numsize(long long n)
{
    switch (n) {
    case 0: return 0;
    default: return 1 + fox_nonnull_numsize(n / 10);
    }
}

__const
size_t fox_numsize(long long n)
{
    switch (n) {
    case 0: return 1;
    default: return fox_nonnull_numsize(n);
    }
}
