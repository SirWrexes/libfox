/*
** EPITECH PROJECT, 2019
** <project name>
** File description:
** fox_strncpy.c -- No description
*/

#include "fox_define.h"
#include "fox_string.h"

__nonnull str_t fox_strncpy(str_t dst, str2c_t src, size_t n)
{
    size_t i;
    size_t len1 = fox_strlen(dst);
    size_t len2 = fox_strlen(src);

    for (i = 0; i < n && i < len1 && i < len2; i += 1)
        dst[i] = src[i];
    for (; i < len1; i += 1)
        dst[i] = '\0';
    return dst;
}
