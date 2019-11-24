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
size_t fox_strlen(str2c_t str) __Anonnull __Apure;

// Compare two strings
// Returns 0 for identical strings
// Returns s1[x] - s2[x] for x is the index where s1 and s2 differ
char fox_strcmp(str2c_t s1, str2c_t s2) __Anonnull __Apure;

// Compare two strings up to n characters
// Returns 0 for identical strings
// Returns s1[x] - s2[x] for x is the index where s1 and s2 differ
char fox_strncmp(str2c_t s1, str2c_t s2, unsigned n) __Anonnull __Apure;

// Copy src into dest
// Returns dest
str_t fox_strcpy(str_t dest, str2c_t s) __Anonnull;

// Copy src into dest up to n characters
// Returns dest
str_t fox_strncpy(str_t dest, str2c_t s, size_t n) __Anonnull;

// Make an exact copy of s and return its pointer
// Returns null in case of error
str_t fox_strdup(str2c_t s) __Anonnull;

// Revert a string
// Returns s
str_t fox_revstr(str_t s) __Anonnull;

// Check if c is in contained str
bool fox_isinstr(char c, str2c_t str) __Anonnull __Apure;

// Get length of a prefix substring
size_t fox_strspn(str2c_t str, str2c_t accept) __Anonnull __Apure;
size_t fox_strcspn(str2c_t str, str2c_t reject) __Anonnull __Apure;

#endif // FOX_STR_H
