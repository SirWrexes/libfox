/*
** EPITECH PROJECT, 2019
** Libfox
** File description:
** Get the length of a string as a size_t value
*/

#include "fox_define.h"

__Apure __Anonnull static size_t tail_length(str2c_t s, size_t r)
{
    if (r-- == 0 || *s++ == '\0')
        return 0;
    if (r-- == 0 || *s++ == '\0')
        return 1;
    if (r-- == 0 || *s++ == '\0')
        return 2;
    if (r-- == 0 || *s++ == '\0')
        return 3;
    if (r-- == 0 || *s++ == '\0')
        return 4;
    if (r-- == 0 || *s++ == '\0')
        return 5;
    return 6;
}

__Apure __Anonnull size_t fox_strnlen(str_t const str, size_t n)
{
    size_t len;

    for (len = 0; len + 7 <= n; len += 7) {
        if (str[len] == '\0')
            return len;
        if (str[len + 1] == '\0')
            return len + 1;
        if (str[len + 2] == '\0')
            return len + 2;
        if (str[len + 3] == '\0')
            return len + 3;
        if (str[len + 4] == '\0')
            return len + 4;
        if (str[len + 5] == '\0')
            return len + 5;
        if (str[len + 6] == '\0')
            return len + 6;
        if (str[len + 7] == '\0')
            return len + 7;
    }
    return n + tail_length(str + len, n - len);
}
