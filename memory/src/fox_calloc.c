/*
** (not) EPITECH PROJECT, 2021
** Libfox
** File description:
** Allocate and initialize an array of n items of size sz.
*/

#include <malloc.h>

#include "fox_define.h"
#include "fox_memory.h"

__Amalloc __AallocSz(1, 2) __AalwaysILext void *fox_calloc(size_t n, size_t sz)
{
    return fox_memset(malloc(n * sz), 0, n * sz);
}
