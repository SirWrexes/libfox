/*
** (not) EPITECH PROJECT, 2021
** Libfox
** File description:
** Fill flags data in farg->info
*/

#include <stdbool.h>

#include "fox_define.h"
#include "printf/fstruct.h"

__Anonnull __AalwaysILext void get_flags(finfo_t *info, str_t *format)
{
    do {
        switch (**format) {
            case '#': info->alt = true; continue;
            case ' ': info->space = true; continue;
            case '-': info->left = true; continue;
            case '+': info->showsign = true; continue;
            case '\'': info->group = true; continue;
            case '0': info->padchar = '0'; continue;
            default: break;
        }
        break;
    } while (*++*format);
    if (info->left)
        info->padchar = ' ';
}
