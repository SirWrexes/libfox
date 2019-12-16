/*
** EPITECH PROJECT, 2019
** csfml
** File description:
** fox_csfml.h -- No description
*/

#ifndef FOX_CSFML_H
#define FOX_CSFML_H

#include "fox_define.h"

// Object definitions
#include "datastruct.h"

// Animation info
#include "animation/animinfo_funcs.h"
#include "animation/animinfo_macro.h"

// Sprite info
#include "sprite/spriteinfo_funcs.h"

// Current scene pointer
// Set when creating a scene with scene_create()
extern struct game_scene *const *SCENEPTR;

// Global clock pointer
// Set at initialization
extern sfClock * const *CLOCKPTR;

#endif /* !FOX_CSFML_H */
