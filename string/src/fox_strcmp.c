/*
** EPITECH PROJECT, 2019
** Libfox
** File description:
** Check if two strings are identical
*/

#include "fox_define.h"

__nonnull __pure
char fox_strcmp(str2c_t s1, str2c_t s2)
{
    while (*s1 != '\0' && *s1 == *s2) {
        s1 += 1;
        s2 += 1;
    }
    return *s1 - *s2;
}
