/*
** EPITECH PROJECT, 2019
** Libfox
** File description:
** Check if a character is a valid ASCII char
*/

#include <stdbool.h>

#include "define/fox_macro.h"
#include "fox_std.h"

__Aconst bool fox_isprintable(u_char c)
{
    if (c >= '\t' && c <= '\v')
        return true;
    if (c >= ' ' && c < '\177')
        return true;
    return false;
}
