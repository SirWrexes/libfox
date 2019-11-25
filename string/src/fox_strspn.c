/*
** EPITECH PROJECT, 2019
** Libfox
** File description:
** Get the length of a prefix substring
*/

#include "fox_string.h"

__Anonnull __Apure size_t fox_strspn(str3c_t str, str3c_t accept)
{
    size_t i = 0;

    while (fox_isinstr(str[i], accept))
        i += 1;
    return i;
}
