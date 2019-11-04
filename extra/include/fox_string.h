/*
** EPITECH PROJECT, 2019
** libfox-2
** File description:
** String module header
*/

#ifndef FOX_STR_H
#define FOX_STR_H

#include <stddef.h>
#include <stdbool.h>
#include "fox_define.h"

// Get a string's length as a size_t value
size_t fox_strlen(str2c_t str)
__nonnull __pure;

// Compare two strings
char fox_strcmp(str2c_t s1, str2c_t s2)
__nonnull __pure;

// Copy src into dest up to n characters
str_t fox_strncpy(str_t dest, str2c_t s, size_t n)
__nonnull;

// Revert a string and return its origin pointer
str_t fox_revstr(str_t s)
__nonnull;

// Check if c is in contained str
bool fox_isinstr(char c, str2c_t str)
__nonnull __pure;

// Get length of a prefix substring
size_t fox_strspn(str2c_t str, str2c_t accept)
__nonnull __pure;
size_t fox_strcspn(str2c_t str, str2c_t reject)
__nonnull __pure;

#endif // FOX_STR_H
