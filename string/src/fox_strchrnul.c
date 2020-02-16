/*
** EPITECH PROJECT, 2020
** Libfox
** File description:
** Locate a character in a string
*/

#include "fox_define.h"
#include "fox_string.h"

__Anonnull __Apure char *fox_strchrnul(str2c_t s, char c)
{
    while (*s != '\0' && *s != c)
        s += 1;
    return (char *) s;
}
