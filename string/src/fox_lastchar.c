/*
** (not) EPITECH PROJECT, 2021
** Libfox
** File description:
** Get the last character of a string
*/

#include "fox_string.h"

__Anonnull __Apure __AalwaysILext char fox_lastchar(str2c_t s)
{
    return *(s + fox_strlen(s) - (*s != '\0'));
}
