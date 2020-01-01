/*
** EPITECH PROJECT, 2020
** csfml
** File description:
** foxcsfml_ent_create.c -- No description
*/

#include <malloc.h>

#include "fox_memory.h"

#include "types/foxcsfml_constructordata.h"

__Anonnull bool foxcsfml_ent_create(unsigned entid, entity_t *e)
{
    const struct constructor_data *ref = &FOXCSFML_ENTITY_DEFAULTS[entid];

    *e = fox_calloc(1, sizeof(**e));
    if (*e == NULL)
        return true;
    fox_memcpy(*e, ref->entinfo, sizeof(**e) - sizeof((**e).spinfo));
    fox_memcpy(&(**e).spinfo, ref->spinfo, sizeof(*ref->spinfo));
    return false;
}
