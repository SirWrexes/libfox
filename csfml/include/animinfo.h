/*
** EPITECH PROJECT, 2019
** csfml
** File description:
** animinfo.h -- No description
*/

#ifndef ANIMINFO_H
#define ANIMINFO_H

#include <stdbool.h>

#include "datastruct.h"
#include "fox_define.h"

/*******************************************************************
**
** ANIMATION RECTANGLES GENERATION
** ↓
****/

// Macro to acess generated arrays
#define __FOXRECT(name) FOXANIMRECT_##name

// Use this macro to declare an animation rectangle array for 1 animation
#define __FOXRECT_CREATE(name) static const sfIntRect __FOXRECT(name)[] =

// Safety macro to declare the last rectangle of an animation rect array
#define __FOXRECT_SENTINEL {.top = -1, .left = -1, .height = -1, .width = -1}

// Macro to access generated arrays
#define __FOXRECTTAB(name) FOXRECTTAB_##name

// Use this macro to make arrays containing animrects arrays for each animation
#define __FOXRECTTAB_CREATE(name) extern const sfIntRect *__FOXRECTTAB(name)

// Use this macro to assign anim rect arrays to animations

/*******************************************************************
**
** ANIMATION TYPE ARRAY
** ↓
****/
#define __FOXANIMTAB(name)

// Use this macro to create an animation type array
#define __FOXRECTTAB_INIT(name) const *__FOXANIMTAB(name)[] =

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

#endif /* !ANIMINFO_H */
