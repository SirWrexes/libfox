/*
** EPITECH PROJECT, 2019
** csfml
** File description:
** foxcsfml_sprite.h -- No description
*/

#ifndef FOXCSFML_SPRITE_H
#define FOXCSFML_SPRITE_H

#include <SFML/Graphics/Types.h>
#include <SFML/System/Vector2.h>

#include "define/fox_types.h"

#include "foxcsfml_animation.h"

// Sprite object
typedef struct sprite_info {
    unsigned entid; // Type of the entity the sprite is attached to

    sfSprite *sprite;          // Sprite itself
    sfVector2f position;       // Sprite starting position
    sfVector2f origin;         // Sprite center
    const sfTexture **texture; // Sprite texture

    unsigned curranim;                      // Current animation
    unsigned maxanims;                      // Maximum animation count
    const struct animation_info **animinfo; // Animation info pointer array
} * spinfo_t;

// Texture informatition
typedef const struct texture_info {
    const str_t path;     // Texutre path
    const sfIntRect area; // Texture area
} textureinfo_t;

#endif /* !FOXCSFML_SPRITE_H */
