/*
** (not) EPITECH PROJECT, 2021
** Libfox
** File description:
** Check if a string is stricly numeric
*/

#include <stdbool.h>

#include "fox_macro.h"
#include "fox_string.h"
#include "fox_types.h"

__Anonnull __Apure bool fox_strisnum(str2c_t s)
{
    s += fox_strspn(s, " ");
    s += fox_strspn(s, "+-");
    s += fox_strspn(s, STR_NUMERICS);
    return (*s == '\0')
        || (*s++ == '.' && !*(s + fox_strspn(s, STR_NUMERICS)));
}
