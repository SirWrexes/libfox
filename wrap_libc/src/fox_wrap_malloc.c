/*
** EPITECH PROJECT, 2019
** Libfox
** File description:
** Wrap malloc to break it on demand
*/

#include <errno.h>

#include "fox_define.h"
#include "fox_internal/foxi_wrapmacro.h"

#include "tests/wrappers/wrap_malloc.h"

Wrapper(void *, malloc, size_t size)
{
    if (malloc_counter == 0) {
        errno = ENOMEM;
        return NULL;
    }
    malloc_counter -= (malloc_counter != -1);
    return __real_malloc(size);
}

__Aconst short *malloc_counter_location(void)
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
