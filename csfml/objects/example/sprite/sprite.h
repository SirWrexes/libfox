/*
** EPITECH PROJECT, 2020
** csfml
** File description:
** sprite.h -- No description
*/

#ifndef EXAMPLE_SPRITE_H
#define EXAMPLE_SPRITE_H

#include <SFML/Graphics.h>

#include "fox_csfml.h"

#include "../../entids.h"
#include "../anims/animinfo.h"

// This has to be set beforehand in ordrer for the texture ptr to exist.
foxTexture_add(EXAMPLE_TEXTURE, "objects/example/sprite/texture.jpeg", {0});

// Leave fields empty if you want them to be zero'd out by default.
// In this example, the fields that are filled are mandatory.
static const struct sprite_info EXAMPLE_SPINFO = {
    // It is recommended you have an enum with a key for each sprite ID
    // A Sprite ID is the same as the entity ID.
    .entid = ENTID_EXAMPLE,

    // Not having animation info for a sprite is an error.
    .animinfo = EXAMPLE_ANIMINFO,

    // Without this, the animation system may break.
    .maxanims = ARRAY_SIZE(EXAMPLE_ANIMINFO),

    // This needs "two-step" initialization and pointer to pointer hack to work
    // around compile time constant restrictions.
    // Don't worry, I made a macro for this.
    .texture = &EXAMPLE_TEXTURE,
};

#endif /* !EXAMPLE_SPRITE_H */
