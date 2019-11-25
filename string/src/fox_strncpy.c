/*
** EPITECH PROJECT, 2019
** <project name>
** File description:
** fox_strncpy.c -- No description
*/

#include "fox_define.h"
#include "fox_string.h"

__Anonnull str_t fox_strncpy(str_t dst, str2c_t src, size_t n)
{
    size_t i = 0;

    for (i = 0; i < n && src[i] != '\0'; i += 1)
        dst[i] = src[i];
    dst[i] = '\0';
    return dst;
}
