/*
** EPITECH PROJECT, 2019
** Libfox
** File description:
** Copy a string up to n bytes
*/

#include "fox_define.h"
#include "fox_memory.h"
#include "fox_string.h"

__a((nonnull(2))) str_t fox_strncpy(str_t dst, str2c_t src, size_t n)
{
    size_t len = fox_strnlen(src, n);

    if (len != n)
        fox_memset(dst + len, '\0', n - len);
    return fox_memcpy(dst, src, len);
}
