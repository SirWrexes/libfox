/*
** EPITECH PROJECT, 2019
** Libfox
** File description:
** Check if c is contained in str
*/

#include <stdbool.h>
#include "fox_define.h"

__Anonnull __Apure bool fox_isinstr(char c, str2c_t str)
{
    if (c == '\0')
        return false;
    while (c != *str && *str != '\0')
        str += 1;
    return *str != '\0';
}
