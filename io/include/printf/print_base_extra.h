/*
** EPITECH PROJECT, 2019
** Libfox
** File description:
** Extra tools for conv_base function
*/

#ifndef PRINT_BASE_EXTRA_H
#define PRINT_BASE_EXTRA_H

#include "fox_define.h"

static const str_t BASE_HEX_CAPS[2] = {"0X", "0123456789ABCDEF"};
static const str_t BASE_HEX[2] = {"0x", "0123456789abcdef"};
static const str_t BASE_OCT[2] = {"0", "01234567"};
static const str_t BASE_BIN[2] = {"0b", "01"};

static inline const str_t *pick_base(char spec)
{
    switch (spec) {
        default:
        case 'x': return BASE_HEX;
        case 'X': return BASE_HEX_CAPS;
        case 'o': return BASE_OCT;
        case 'b': return BASE_BIN;
    }
}

#endif /* !PRINT_BASE_EXTRA_H */
