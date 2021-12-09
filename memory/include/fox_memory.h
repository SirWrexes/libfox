/*
** (not) EPITECH PROJECT, 2021
** Libfox
** File description:
** Memory module header
*/

#ifndef FOX_MEMORY_H
#define FOX_MEMORY_H

#include <sys/types.h>

#include "fox_define.h"

// Make a pointer smarter
#define __smart __Acleanup(fox_autofree)
void fox_autofree(void *p) __Ahidden;

// Make an fd autoclose
#define __close __Acleanup(fox_autoclose)
void fox_autoclose(int *fdp) __Ahidden;

// Copy n bytes of memory from src into dst
void *fox_memcpy(void *dst, const void *src, size_t n) __a((nonnull(2)));

// Set n bytes of pointed dst memory to value c
void *fox_memset(void *dst, int c, size_t n);

// Allocate a pointer for n items of size sz
// Newly allocated memory is initialized to 0
void *fox_calloc(size_t n, size_t sz) __Amalloc __AallocSz(1, 2);

// Reallocate a pointer and set oldsz to newsz's value on success
// If oldsz is NULL or points to a 0 value, a new pointer will be created
// If oldp is NULL, a new pointer will be created
// If newsz is 0, the pointer will be freed
void *fox_realloc_sz(void *oldp, size_t *oldsz, size_t newsz) __Amalloc;

#endif /* !FOX_MEMORY_H */
