/*
** EPITECH PROJECT, 2020
** Libfox
** File description:
** Concatenate 2 strings
*/

#include "fox_define.h"
#include "fox_string.h"

__Anonnull str_t fox_strcat(str_t dest, str2c_t s)
{
    str_t tmp = dest;

    tmp += fox_strlen(dest);
    fox_strcpy(tmp, s);
    return dest;
}
