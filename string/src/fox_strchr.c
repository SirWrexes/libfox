/*
** EPITECH PROJECT, 2020
** Minishell
** File description:
** fox_strchr.c -- No description
*/

#include "fox_define.h"

__Anonnull __Apure str_t fox_strchr(str2c_t s, char c)
{
    while (*s != '\0' && *s != c)
        s += 1;
    return (str_t) (*s != '\0' ? s : NULL);
}
