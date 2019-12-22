/*
** EPITECH PROJECT, 2019
** Libfox
** File description:
** Copy a memory area of n bytes
*/

#include "fox_define.h"
#include "fox_memory.h"

static const size_t ULSIZE = sizeof(ulong_t);

__a((nonnull(2))) void *fox_memcpy(void *dst, const void *src, size_t n)
{
    ulong_t *srcp = (ulong_t *) src;
    ulong_t *dstp = (ulong_t *) dst;
    byte_t *srcbp;
    byte_t *dstbp;

    if (dst != NULL) {
        while (n / ULSIZE != 0) {
            *dstp++ = *srcp++;
            n -= ULSIZE;
        }
        srcbp = (byte_t *) srcp;
        dstbp = (byte_t *) dstp;
        while (n-- != 0)
            *dstbp++ = *srcbp++;
    }
    return dst;
}
