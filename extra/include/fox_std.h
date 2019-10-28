/*
** EPITECH PROJECT, 2019
** Libfox
** File description:
** Standed header
*/

#ifndef FOX_STD_H
#define FOX_STD_H

#include "fox_define.h"

// Convert a string to a long integer
// If endptr != NULL, set it to the adress of the
//   first non numeric character encountered.
__a((nonnull(1))) long fox_strtol(char const *s, char **endptr);

#endif /* !FOX_STD_H */
