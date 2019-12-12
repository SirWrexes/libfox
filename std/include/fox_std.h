/*
** EPITECH PROJECT, 2019
** Libfox
** File description:
** Standed header
*/

#ifndef FOX_STD_H
#define FOX_STD_H

#include <stdbool.h>
#include <sys/types.h>

#include "define/fox_macro.h"
#include "fox_define.h"

// Check if a character is printable
// Returns true if c is either a whitespace
// or somlething of value between '\040' (' ') and '\0177' (DEL)
bool fox_isprintable(u_char c) __Aconst;

// Convert a string to a long integer
// If endptr != NULL, set it to the adress of the first non numeric character
long fox_strtol(char const *s, char **endptr) __a((nonnull(1)));

#endif /* !FOX_STD_H */
