/*
** EPITECH PROJECT, 2019
** Libfox
** File description:
** Get the length of a line
*/

#include "fox_define.h"

__Apure __Anonnull size_t fox_linelen(str_t const str)
{
    size_t len;

    for (len = 0;; len += 7) {
        if (CHAR_IS_EOL(str[len]))
            return len;
        if (CHAR_IS_EOL(str[len + 1]))
            return len + 1;
        if (CHAR_IS_EOL(str[len + 2]))
            return len + 2;
        if (CHAR_IS_EOL(str[len + 3]))
            return len + 3;
        if (CHAR_IS_EOL(str[len + 4]))
            return len + 4;
        if (CHAR_IS_EOL(str[len + 5]))
            return len + 5;
        if (CHAR_IS_EOL(str[len + 6]))
            return len + 6;
        if (CHAR_IS_EOL(str[len + 7]))
            return len + 7;
    }
}
