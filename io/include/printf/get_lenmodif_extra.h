/*
** (not) EPITECH PROJECT, 2021
** Libfox
** File description:
** Length modifier indification helpers
*/

#ifndef LENMODIFS_H
#define LENMODIFS_H

#include <stdint.h>
#include "printf/fstruct.h"
#include "fox_define.h"

__Anonnull __AalwaysIL static inline void set_lm_h(finfo_t *info, str_t *fmt)
{
    if (**fmt != 'h')
        info->is_short = true;
    else {
        *fmt += 1;
        info->is_char = true;
    }
}

__Anonnull __AalwaysIL static inline void set_lm_l(finfo_t *info, str_t *fmt)
{
    if (**fmt != 'l')
        info->is_long = true;
    else {
        *fmt += 1;
        info->is_long_long = true;
    }
}

__Anonnull __AalwaysIL static inline void set_lm_z(finfo_t *info)
{
#if LONG_MAX != LONG_LONG_MAX
    info->is_long_long = (sizeof(size_t) > sizeof(unsigned long int));
#endif
    info->is_long = sizeof(size_t) > sizeof(unsigned int);
}

__Anonnull __AalwaysIL static inline void set_lm_j(finfo_t *info)
{
#if LONG_MAX != LONG_LONG_MAX
    info->is_long_long = (sizeof(uintmax_t) > sizeof(unsigned long int));
#endif
    info->is_long = sizeof(uintmax_t) > sizeof(unsigned int);
}

__Anonnull __AalwaysIL static inline void set_lm_t(finfo_t *info)
{
#if LONG_MAX != LONG_LONG_MAX
    info->is_long_long = (sizeof(ptrdiff_t) > sizeof(long int));
#endif
    info->is_long = sizeof(ptrdiff_t) > sizeof(int);
}

#endif /* !LENMODIFS_H */
