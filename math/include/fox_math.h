/*
** (not) EPITECH PROJECT, 2021
** Libfox
** File description:
** Math module header
*/

#ifndef FOX_MATH_H
#define FOX_MATH_H

#include <stddef.h>
#include "fox_define.h"

// Count the digits in a signed integer
size_t fox_numsize(llong_t n) __Aconst;

// Count the digits in an unsigned integer
size_t fox_unumsize(ullong_t n) __Aconst;

// Check if a base is correct. If size != NULL, sets size to base size (DUH !)
// If base is valid, returns 0
// If base is invalid return the first invalid character and sets size to its
// index in the base string
// A base of length 1 is "valid" for this function, but not in maths
char fox_verifbase(str2c_t base, size_t *n) __Apure __a((nonnull(1)));

#endif /* !FOX_MATH_H */
