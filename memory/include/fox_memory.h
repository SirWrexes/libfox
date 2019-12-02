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

void *fox_memcpy(void *dest, const void *src, size_t n)
    __a((nonnull(2))) __Aconst;

#endif /* !FOX_MEMORY_H */
