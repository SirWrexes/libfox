/*
** EPITECH PROJECT, 2020
** csfml
** File description:
** foxcsfml_constructordata.h -- No description
*/

#ifndef FOXCSFML_CONSTRUCTORDATA_H
#define FOXCSFML_CONSTRUCTORDATA_H

#include "foxcsfml_animation.h"
#include "foxcsfml_entity.h"
#include "foxcsfml_sprite.h"

struct constructor_data {
    const struct game_entity *entinfo;      // Entity info defaults
    const struct sprite_info *spinfo;       // Sprite info defaults
};

// It's declared, but you need to define it in a source.
// See objects/entdefaults.c for a quick example.
extern const struct constructor_data FOXCSFML_ENTITY_DEFAULTS[];

#endif /* !FOXCSFML_CONSTRUCTORDATA_H */
