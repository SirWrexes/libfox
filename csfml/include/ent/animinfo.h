/*
** EPITECH PROJECT, 2019
**
** File description:
** animinfo.h -- No description
*/

#ifndef ANIMINFO_H
#define ANIMINFO_H

#include "fox_csfml.h"
#include "fox_memory.h"

static const sfIntRect FOXCSFML_ENT_RECT[] = {
    {.left = 0, .top = 0, .width = 0, .height = 0},
};

__Aunused foxAnimInfo(ENT2) = {0};

static const struct animation_info FOXCSFML_ENT_ANIMINFO[] = {
    {
        .tick.microseconds = foxTick_milliseconds(17),
        .type = ANIM_TYPE_NONE,
        .rect = NULL,  // FOXCSFML_ENT_RECT
        .scale = NULL, // FOXCSFML_ENT_SCALE

        .elapsed = {0},
        .frame = 0,
        .pongstep = 1,
    },

};

#endif /* !ANIMINFO_H */
