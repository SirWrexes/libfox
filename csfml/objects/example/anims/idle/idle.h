/*
** EPITECH PROJECT, 2019
**
** File description:
** animinfo.h -- No description
*/

#ifndef EXAMPLE_ANIMINFO_IDLE_H
#define EXAMPLE_ANIMINFO_IDLE_H

#include "fox_csfml.h"
#include "fox_memory.h"

static const sfIntRect EXAMPLE_ANIMRECTS_IDLE[] = {
    // Includes make it easier to read.
    // You could also fill this here directly if you prefer.
    #include "rects"
};

// Leave fields empty if you want them to be zero'd out by default.
// In this example, the fields that are filled are mandatory.
static const struct animation_info EXAMPLE_ANIMINFO_IDLE = {
    // If this field is empty, this will be the default
    .type = ANIM_TYPE_NONE,

    // Not setting rects is an error.
    .rect = EXAMPLE_ANIMRECTS_IDLE,

    // Not setting a tick will result in a frame update every loop turn.
    .tick = {foxTick_milliseconds(17)},

    // Without this, the animation system will break.
    .maxframes = ARRAY_SIZE(EXAMPLE_ANIMRECTS_IDLE),
};

#endif /* !EXAMPLE_ANIMINFO_IDLE_H */
