/*
** EPITECH PROJECT, 2019
** Libfox
** File description:
** Write a string into another already allocated string
*/

#include "fox_string.h"
#include "fox_define.h"

__nonnull __const
extern inline size_t fox_sputstr(str_t s, str_t str)
{
    return fox_strlen(fox_strcpy(s, str));
}
