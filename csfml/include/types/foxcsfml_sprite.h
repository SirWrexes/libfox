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

#include "foxcsfml_animation.h"

// Sprite object
typedef struct sprite_info {
    unsigned entid;      // Type of the entity the sprite is attached to
    sfSprite *sprite;    // Sprite itself
    sfVector2f position; // Sprite starting position
    sfVector2f origin;   // Sprite center

    unsigned curranim;                // Current animation
    struct animation_info animinfo[]; // Animation info array
} * spinfo_t;

#endif /* !FOXCSFML_SPRITE_H */
