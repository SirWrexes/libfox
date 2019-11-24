/*
** EPITECH PROJECT, 2019
** Libfox
** File description:
** Wrap malloc to break it on demand
*/

#include <errno.h>

#include <criterion/criterion.h>

#include "tests/wrap_malloc.h"
#include "fox_define.h"

void *real_malloc(size_t size);
void *wrap_malloc(size_t size)
{
    if (malloc_counter == 0) {
        errno = ENOMEM;
        return NULL;
    }
    malloc_counter -= (malloc_counter != -1);
    return real_malloc(size);
}

__a((const))
short *__malloc_counter(void)
{
    static short n = -1;

    return &n;
}

extern inline void fix_malloc(void)
{
    malloc_counter = -1;
    errno = 0;
}

extern inline void break_malloc(void)
{
    malloc_counter = 0;
}
