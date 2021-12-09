/*
** (not) EPITECH PROJECT, 2021
** Libfox
** File description:
** Garbage collector: Pointer
*/

#include <malloc.h>

#include "fox_memory.h"

__Ahidden void fox_autofree(void *p)
{
    if (* (void **) p == NULL)
        return;
    free(* (void **) p);
    *(void **) p = NULL;
}
