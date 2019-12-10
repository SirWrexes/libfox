/*
** EPITECH PROJECT, 2019
** Libfox
** File description:
** Set a whole memory area to given data
*/

#include "fox_define.h"
#include "fox_memory.h"

void *fox_memset(void *dst, int c, size_t n)
{
    typeof(c) chunk[32] = {[0 ... 31] = c};
    unsigned chnksz = sizeof(chunk);
    unsigned chnkln = chnksz / sizeof(chunk[0]);
    typeof(c) *dstp = dst;

    if (dstp != NULL) {
        while (n / chnksz != 0) {
            fox_memcpy(dstp, chunk, chnksz);
            dstp += chnkln;
            n -= chnksz;
        }
        fox_memcpy(dstp, chunk, n);
    }
    return dst;
}
