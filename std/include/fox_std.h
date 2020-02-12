/*
** EPITECH PROJECT, 2019
** Libfox
** File description:
** Standed header
*/

#ifndef FOX_STD_H
#define FOX_STD_H

#include <getopt.h>
#include <stdbool.h>
#include <sys/types.h>

#include "fox_define.h"

// Check if a character is printable
// Returns true if c is either a whitespace
// or somlething of value between '\040' (' ') and '\0177' (DEL)
bool fox_isprintable(u_char c) __Aconst;

// Convert a string to a long integer
// If endptr != NULL, set it to the adress of the first non numeric character
long fox_strtol(str2c_t s, char **endptr) __a((nonnull(1)));

// getopt(3) copycat
// Uses the same global variables as the original one
int fox_getopt(int argc, str_t *const argv, str2c_t optstr) __Anonnull;

#endif /* !FOX_STD_H */
