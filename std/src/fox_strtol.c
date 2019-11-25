/*
** EPITECH PROJECT, 2019
** Libfox
** File description:
** Convert a numeric string into a long int
*/

#include <limits.h>
#include <stdbool.h>
#include "fox_define.h"
#include "fox_string.h"

__Anonnull static size_t numsize(char const **s)
{
    size_t n = 0;

    while (**s == '0')
        *s += 1;
    while (CHAR_IS_NUM((*s)[n]))
        n += 1;
    return n;
}

__Anonnull static bool get_sign(char const **s)
{
    bool isneg = false;

    *s += fox_strspn(*s, STR_WHITESPACE);
    while (CHAR_IS_SIGN(**s))
        isneg ^= (bool) (*(*s)++ == '-');
    return isneg;
}

__a((nonnull(1))) long fox_strtol(char const *s, char **endptr)
{
    ulong_t ret = 0;
    bool isneg = get_sign(&s);
    size_t size = numsize(&s);

    if (endptr != NULL)
        *endptr = (str_t) s + size;
    if (size > 19)
        return 0;
    for (hindex_t i = 0; i < size;) {
        ret += CHAR_TO_N(s[i]);
        if (++i < size)
            ret *= 10;
    }
    if (ret > (ulong_t) LONG_MAX + isneg)
        ret = 0;
    return isneg ? (signed long) -ret : (signed long) ret;
}
