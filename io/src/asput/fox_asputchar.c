/*
** EPITECH PROJECT, 2019
** Libfox
** File description:
** Write a single character
*/

#include <malloc.h>
#include "fox_io.h"

__nonnull
scount_t fox_asputchar(str_t *s, char c)
{
    *s = malloc(2 * sizeof(**s));
    if (*s == NULL)
        return -1;
    return fox_sputchar(*s, c);
}
