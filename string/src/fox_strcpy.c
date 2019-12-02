/*
** EPITECH PROJECT, 2019
** Libfox
** File description:
** Copy src into dst
*/

#include "fox_define.h"
#include "fox_memory.h"
#include "fox_string.h"

__a((nonnull(2))) extern inline str_t fox_strcpy(str_t dst, str2c_t src)
{
    return fox_memcpy(dst, src, fox_strlen(src) + 1);
}
