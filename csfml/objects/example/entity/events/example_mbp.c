/*
** EPITECH PROJECT, 2020
** csfml
** File description:
** example_mbp.c -- No description
*/

#include <unistd.h>

#include "fox_define.h"
#include "fox_csfml.h"

static void event_example_mbp(entity_t __Aunused e)
{
    write(1, "plop", 4);
}
