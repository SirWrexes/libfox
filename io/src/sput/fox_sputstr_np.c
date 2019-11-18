/*
** EPITECH PROJECT, 2019
** Libfox
** File description:
** Write a string (including non-printables) to an already allocated string
*/

#include "fox_io.h"
#include "fox_string.h"
#include "fox_define.h"

__nonnull __const
size_t fox_sputstr_np(str_t s, str2c_t str)
{
    size_t i = 0;
    size_t len = 0;

    while (true) {
        for (i = 0; CHAR_IS_PRINTABLE(str[i]) || str[i] == '\n'; i += 1) {}
        fox_strncpy(s, str, i);
        str += i;
        s += i;
        len += i;
        if (*str == '\0')
            break;
        s += fox_sputchar_oct(s, *str++);
        len += 4;
    }
    return len;
}
