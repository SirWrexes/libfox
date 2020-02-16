/*
** EPITECH PROJECT, 2019
** Libfox
** File description:
** Private header for diopadn
*/

#ifndef FOX_DIOPADN_H
#define FOX_DIOPADN_H

#include "fox_define.h"

#define PADSIZE 16
// clang-format off
// It breaks the '...' operator by  removing the space after it
static const char BLANKS[] = {[0 ... (PADSIZE - 1)] = ' '};
static const char ZEROES[] = {[0 ... (PADSIZE - 1)] = '0'};
// clang-format on

__Anonnull static inline str_t set_padbuff(char padbuff[PADSIZE], uchar_t pad)
{
    for (hindex_t i = 0; i < PADSIZE; i += 1)
        padbuff[i] = pad;
    return padbuff;
}

#endif /* !FOX_DIOPADN_H */
