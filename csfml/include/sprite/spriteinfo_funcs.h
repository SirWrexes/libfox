/*
** EPITECH PROJECT, 2019
** csfml
** File description:
** spriteinfo_funcs.h -- No description
*/

#ifndef SPRITEINFO_FUNCS_H
#define SPRITEINFO_FUNCS_H

#include "fox_define.h"
#include "datastruct.h"

// Create and init a sprite to its default values
// Returns true in case of sprite creation failue
bool si_init(spinfo_t si) __Anonnull;

// Set a sprite to its current animation frame's scale
void si_update_scale(spinfo_t si) __Anonnull;

// Set a sprite to its current animation frame's rectangle
void si_update_rect(spinfo_t si) __Anonnull;

// Set a sprite to its current position according to @si->position
void si_update_pos(spinfo_t si) __Anonnull;

// Set @si->position to its sprite's current position
void si_update_pos_info(spinfo_t si) __Anonnull;

// Set a sprite's tecture from @si->texture[@si->entid]
void si_update_texture(spinfo_t si) __Anonnull;

#endif /* !SPRITEINFO_FUNCS_H */
