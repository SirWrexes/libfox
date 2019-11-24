/*
** EPITECH PROJECT, 2019
** Libfox
** File description:
** Copy src into dst
*/

#include "fox_define.h"
#include "fox_string.h"

__Anonnull
str_t fox_strcpy(str_t dst, str2c_t src)
{
    index_t i = 0;

    for (; src[i] != '\0'; i += 1)
        dst[i] = src[i];
    dst[i] = '\0';
    return dst;
}
