/*
** (not) EPITECH PROJECT, 2021
** Libfox
** File description:
** Reallocate a pointer and adjust the variable containing its size
*/

#include <malloc.h>

#include "fox_define.h"
#include "fox_memory.h"

__Amalloc void *fox_realloc_sz(void *oldptr, size_t *oldsize, size_t newsize)
{
    void *p = NULL;
    size_t n;

    if (((ulong_t) oldptr | (ulong_t) oldsize))
        n = (oldsize != NULL) ? *oldsize : 0;
    if (newsize != 0)
        p = malloc(newsize);
    if (oldptr != NULL) {
        fox_memcpy(p, oldptr, N_MIN(n, newsize));
        free(oldptr);
    }
    if (oldsize != NULL)
        *oldsize = newsize;
    return p;
}
