/*
** EPITECH PROJECT, 2019
** <project_name>
** File description:
** lenmodifs.h -- No description
*/

#ifndef LENMODIFS_H
#define LENMODIFS_H

#include <stdint.h>
#include "printf/fstruct.h"
#include "fox_define.h"

__nonnull
static inline void set_lm_h(finfo_t *info, str_t *format)
{
    if (**format != 'h')
        info->is_short = true;
    else {
        *format += 1;
        info->is_char = true;
    }
}

__nonnull
static inline void set_lm_l(finfo_t *info, str_t *format)
{
    if (**format != 'l')
        info->is_long = true;
    else {
        *format += 1;
        info->is_long_long = true;
    }
}

__nonnull
static inline void set_lm_z(finfo_t *info)
{
    #if LONG_MAX != LONG_LONG_MAX
    info->is_long_long = (sizeof(size_t) > sizeof(unsigned long int));
    #endif
    info->is_long = sizeof(size_t) > sizeof(unsigned int);
}

__nonnull
static inline void set_lm_j(finfo_t *info)
{
    #if LONG_MAX != LONG_LONG_MAX
    info->is_long_long = (sizeof(uintmax_t) > sizeof(unsigned long int));
    #endif
    info->is_long = sizeof(uintmax_t) > sizeof(unsigned int);
}

__nonnull
static inline void set_lm_t(finfo_t *info)
{
    #if LONG_MAX != LONG_LONG_MAX
    info->is_long_long = (sizeof(ptrdiff_t) > sizeof(long int));
    #endif
    info->is_long = sizeof(ptrdiff_t) > sizeof(int);
}

#endif /* !LENMODIFS_H */
