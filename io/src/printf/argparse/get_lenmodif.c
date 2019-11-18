/*
** EPITECH PROJECT, 2019
** Libfox
** File description:
** Get the length modifier of a format argument
*/

#include <sys/types.h>
#include "printf/fstruct.h"
#include "printf/get_lenmodif_extra.h"

__nonnull
extern inline void get_lenmodif(finfo_t *info, str_t *format)
{
    switch (*(*format)++) {
        case 'h': set_lm_h(info, format); break;
        case 'l': set_lm_l(info, format); break;
        case 'q': info->is_long_long = true; break;
        case 'L': info->is_long_double = true; break;
        case 'z': case 'Z': set_lm_z(info); break;
        case 'j': set_lm_j(info); break;
        case 't': set_lm_t(info); break;
        default: *format -= 1; break;
    }
}
