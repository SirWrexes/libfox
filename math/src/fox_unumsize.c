/*
** EPITECH PROJECT, 2019
** Libfox
** File description:
** Get the length of an unsigned int
*/

#include <stddef.h>
#include "fox_define.h"

__Aconst static size_t fox_nonnull_numsize(ullong_t n)
{
    switch (n) {
        case 0: return 0;
        default: return 1 + fox_nonnull_numsize(n / 10);
    }
}

__Aconst size_t fox_unumsize(ullong_t n)
{
    switch (n) {
        case 0: return 1;
        default: return fox_nonnull_numsize(n);
    }
}
