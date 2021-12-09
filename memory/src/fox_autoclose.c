/*
** (not) EPITECH PROJECT, 2021
** Libfox
** File description:
** Garbage collector: File descriptor
*/

#include <unistd.h>

#include "fox_memory.h"

__Ahidden void fox_autoclose(int *fdp)
{
    if (*fdp == -1)
        return;
    close(*fdp);
    *fdp = -1;
}
