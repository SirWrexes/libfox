/*
** EPITECH PROJECT, 2019
** Libfox
** File description:
** fox_autofree.c -- No description
*/

#include <unistd.h>

#include "fox_memory.h"

__Ahidden void __fox_autoclose(int *fdp)
{
    if (*fdp == -1)
        return;
    close(*fdp);
    *fdp = -1;
}
