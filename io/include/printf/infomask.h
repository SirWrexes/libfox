/*
** (not) EPITECH PROJECT, 2021
** Libfox
** File description:
** Bit masks to work with fstruct values
*/

#ifndef INFOMASK_H
#define INFOMASK_H

#include "printf/fstruct.h"

enum {
    MASK_CHAR       = 0b0000000000000001, // (1 <<  0)
    MASK_SHORT      = 0b0000000000000010, // (1 <<  1)
    MASK_LONG       = 0b0000000000000100, // (1 <<  2)
    MASK_LONGLONG   = 0b0000000000001000, // (1 <<  3)
    MASK_LONGDOUBLE = 0b0000000000010000, // (1 <<  4)

    MASK_ALT        = 0b0000000000100000, // (1 <<  5)
    MASK_GROUP      = 0b0000000001000000, // (1 <<  6)
    MASK_LEFT       = 0b0000000010000000, // (1 <<  7)
    MASK_SHOWSIGN   = 0b0000000100000000, // (1 <<  8)
    MASK_SPACE      = 0b0000001000000000, // (1 <<  9)
    MASK_ZEROPAD    = 0b0000010000000000, // (1 << 10)

    MASK_TYPE =
        MASK_SHORT
        | MASK_CHAR
        | MASK_LONG
        | MASK_LONGLONG
        | MASK_LONGDOUBLE,

    MASK_FLAG =
        MASK_ALT
        | MASK_GROUP
        | MASK_LEFT
        | MASK_SHOWSIGN
        | MASK_SPACE
        | MASK_ZEROPAD
};

__Anonnull static inline hbmask_t info_to_mask(finfo_t *info)
{
    return info->is_char * MASK_CHAR
        | info->is_short * MASK_SHORT
        | info->is_long * MASK_LONG
        | info->is_long_long * MASK_LONGLONG
        | info->is_long_double * MASK_LONGDOUBLE
        | info->alt * MASK_ALT
        | info->group * MASK_GROUP
        | info->left * MASK_LEFT
        | info->showsign * MASK_SHOWSIGN
        | info->space * MASK_SPACE;
}

#endif /* !INFOMASK_H */
