/*
** EPITECH PROJECT, 2019
** Libfox
** File description:
** Memory module header
*/

#ifndef FOX_MEMORY_H
#define FOX_MEMORY_H

#include <sys/types.h>

#include "fox_define.h"

// Copy n bytes of memory from src into dst
void *fox_memcpy(void *dst, const void *src, size_t n) __a((nonnull(2)));

// Set n bytes of pointed dst memory to value c
void *fox_memset(void *dst, int c, size_t n);

#endif /* !FOX_MEMORY_H */
