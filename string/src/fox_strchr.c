/*
** (not) EPITECH PROJECT, 2021
** Libfox
** File description:
** Locate the first occurence of a character in a string
*/

#include "fox_define.h"

__Anonnull __Apure str_t fox_strchr(str2c_t s, char c)
{
    while (*s != '\0' && *s != c)
        s += 1;
    return (str_t) (*s != '\0' ? s : NULL);
}
