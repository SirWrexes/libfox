/*
** (not) EPITECH PROJECT, 2021
** Libfox
** File description:
** Copy a string into another
*/

#include "fox_define.h"
#include "fox_memory.h"
#include "fox_string.h"

__a((nonnull(2))) __AalwaysILext str_t fox_strcpy(str_t dst, str2c_t src)
{
    return fox_memcpy(dst, src, fox_strlen(src) + 1);
}
