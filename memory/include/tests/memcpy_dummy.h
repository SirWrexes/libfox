/*
** EPITECH PROJECT, 2019
** Libfox
** File description:
** Dummy structure to test fox_memcpy
*/

#ifndef MEMCPY_DUMMY_H
#define MEMCPY_DUMMY_H

#include <sys/types.h>

typedef struct {
    size_t dummy_size;
    char *dummy_str;
    int dummy_arr[6];
    char dummy_pad[4];
} memcpy_dummy_t;

static memcpy_dummy_t DUM_REF = {
    .dummy_size = 2342,
    .dummy_str = "The numbers are bad !",
    .dummy_arr = {4, 8, 15, 16, 23, 42},
    .dummy_pad = {'l', 'o', 's', 't'}
};

static char DUM_REFSTR[23] = "See you in another life";

#endif /* !MEMCPY_DUMMY_H */
