/*
** EPITECH PROJECT, 2019
** csfml
** File description:
** animinfo_funcs.h -- No description
*/

#ifndef ANIMINFO_FUNCS_H
#define ANIMINFO_FUNCS_H

#include <stdbool.h>

#include "fox_define.h"
#include "datastruct.h"

/*******************************************************************
**
** ANIMATION HELPER FUNCTIONS
** ↓
****/

// Get thte type of the current animation
animtype_t ai_type(animinfo_t ai) __Anonnull;

// Get the adress of the current animation rectangle
const sfIntRect *ai_rect_current(animinfo_t ai) __Anonnull;

// Get the adress of the next animation rectangle
const sfIntRect *ai_rect_next(animinfo_t ai) __Anonnull;

// Check if an animation is on its last frame
bool ai_on_last_frame(animinfo_t ai) __Anonnull;

#endif /* !ANIMINFO_FUNCS_H */
