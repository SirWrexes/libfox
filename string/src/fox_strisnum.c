/*
** EPITECH PROJECT, 2019
** Libfox
** File description:
** Check if a string is stricly numeric
*/

#include <stdbool.h>

#include "define/fox_macro.h"
#include "define/fox_types.h"
#include "fox_string.h"

__Anonnull __Apure bool fox_strisnum(str2c_t s)
{
    s += fox_strspn(s, " ");
    s += fox_strspn(s, "+-");
    s += fox_strspn(s, STR_NUMERICS);
    return (*s == '\0')
        || (*s++ == '.' && ! *(s + fox_strspn(s, STR_NUMERICS)));
}
