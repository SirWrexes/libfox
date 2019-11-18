/*
** EPITECH PROJECT, 2019
** Libfox
** File description:
** Fill flags data in farg->info
*/

#include <stdbool.h>
#include "fox_define.h"

#include "args/farg_datastruct.h"

__nonnull
extern inline void get_flags(finfo_t *info, str_t *format)
{
    do {
        switch (**format) {
            case '#': info->alt = true; break;
            case ' ': info->space = true; break;
            case '-': info->left = true; break;
            case '+': info->showsign = true; break;
            case '\'': info->group = true; break;
            case '0': info->zeropad = true; break;
            default: return;
        }
        *format += 1;
    } while (true);
}
