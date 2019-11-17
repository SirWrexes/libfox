/*
** EPITECH PROJECT, 2019
** Libfox
** File description:
** Print a string (including non printables) to a newly allocated pointer
*/

#include <malloc.h>
#include "fox_string.h"
#include "fox_io.h"
#include "fox_define.h"

__pure
static size_t getlen(str2c_t str)
{
    size_t i = 0;

    for (; *str != '\0'; str += 1)
        i += CHAR_IS_PRINTABLE(*str) ? 1 : 4;
    return i;
}

__nonnull
ssize_t fox_asputstr_np(str_t *s, str2c_t str)
{
    size_t len = getlen(str);

    *s = malloc((len + 1) * sizeof(**s));
    if (*s == NULL)
        return -1;
    return fox_sputstr_np(*s, str);
}
