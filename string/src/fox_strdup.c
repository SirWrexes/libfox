/*
** EPITECH PROJECT, 2019
** Libfox
** File description:
** Make a new exact copy of str and return its pointer
*/

#include <malloc.h>
#include "fox_string.h"
#include "fox_define.h"

__Anonnull
str_t fox_strdup(str2c_t str)
{
    str_t cpy = malloc((fox_strlen(str) + 1) * sizeof(*cpy));

    if (cpy == NULL)
        return NULL;
    return fox_strcpy(cpy, str);
}
