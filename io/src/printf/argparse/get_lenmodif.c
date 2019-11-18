/*
** EPITECH PROJECT, 2019
** Libfox
** File description:
** Get the length modifier of a format argument
*/

#include "fox_string.h"

#include "args/farg_datastruct.h"
#include "private/lenmodifs.h"

__nonnull
extern inline void get_lenmodif(finfo_t *info, str_t *format)
{
    hsize_t lmsize = fox_strspn(*format, LM_CHARS);

    if (lmsize == 0)
        return;
    for (hindex_t i = 0; i < LM_CNT; i += 1) {
        if (lmsize != LM_SIZE[i] || fox_strncmp(*format, LM_STR[i], lmsize))
            continue;
        LM_SET[i](info, format);
        return;
    }
}
