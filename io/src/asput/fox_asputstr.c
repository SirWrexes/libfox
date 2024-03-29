/*
** (not) EPITECH PROJECT, 2021
** Libfox
** File description:
** Allocate a string and print another string into it
*/

#include <malloc.h>
#include "fox_string.h"
#include "fox_define.h"

__a((nonnull(1)))
extern inline scount_t fox_asputstr(str_t *s, str2c_t str)
{
    if (str == NULL)
        *s = fox_strdup("(null)");
    else
        *s = fox_strdup(str);
    if (*s == NULL)
        return -1;
    else
        return fox_strlen(*s);
}
