/*
** EPITECH PROJECT, 2019
** Libfox
** File description:
** Get the length of a prefix substring
*/

#include "fox_string.h"

__Anonnull __Apure
size_t fox_strcspn(str2c_t str, str2c_t reject)
{
    size_t i = 0;

    while (str[i] && !fox_isinstr(str[i], reject))
        i += 1;
    return i;
}
