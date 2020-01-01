/*
** EPITECH PROJECT, 2020
** csfml
** File description:
** entdefaults.c -- No description
*/

#include "fox_csfml.h"

#include "entids.h"
#include "objects/example/anims/animinfo.h"
#include "objects/example/entity/entity.h"
#include "objects/example/sprite/sprite.h"

const struct constructor_data FOXCSFML_ENTITY_DEFAULTS[ENTID_CNT] = {
    [ENTID_EXAMPLE] =
        {
            .entinfo = &EXAMPLE_ENTITY,
            .spinfo = &EXAMPLE_SPINFO,
        },
};
