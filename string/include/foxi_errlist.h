/*
** (not) EPITECH PROJECT, 2021
** Libfox
** File description:
** Definition of errno strings
*/

// This header should not be included anywhere.
// You should use fox_strerror() from the string module instead.

#ifndef ERRLIST_H
#define ERRLIST_H

#include <errno.h>

#include "fox_types.h"

#ifndef FOX_ERRMAP
    #define FOX_ERRMAP(n) (n)
#endif

static str2c_t fox_errlist[] = {
#define ERRNO_ENTRY(index, str) [FOX_ERRMAP(index)] = (str),
#include "foxi_errno_entries.h"
#undef ERRNO_ENTRY
};

#endif /* !ERRLIST_H */
