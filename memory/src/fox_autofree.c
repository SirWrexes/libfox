/*
** EPITECH PROJECT, 2019
** Libfox
** File description:
** fox_autofree.c -- No description
*/

#include <malloc.h>

#include "fox_memory.h"

__Ahidden void __fox_autofree(void *p)
{
    if (* (void **) p == NULL)
        return;
    free(* (void **) p);
    *(void **) p = NULL;
}
