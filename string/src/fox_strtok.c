/*
** (not) EPITECH PROJECT, 2021
** Libfox
** File description:
** Tokenize a string
*/

#include "fox_string.h"

str_t fox_strtok(str_t s, str2c_t delim)
{
    static str_t save;

    return fox_strtok_r(s, delim, &save);
}

str_t fox_strtok_r(str_t s, str2c_t delim, str_t *saveptr)
{
    str_t end;

    s = s ?: *saveptr;
    if (*s == '\0') {
        *saveptr = s;
        return NULL;
    }
    s += fox_strspn(s, delim);
    end = s + fox_strcspn(s, delim);
    if (*end == '\0') {
        *saveptr = end;
        return s;
    }
    *end = '\0';
    *saveptr = end + 1;
    return s;
}
