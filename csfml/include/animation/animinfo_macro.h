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
** ANIMATION RECTANGLES
** ↓
****/

// Macro to acess generated arrays
#define animRect(entity, animation) \
/* → */ FOXANIMRECT_##entity_##animation

// Use this macro to declare an animation rectangle array for 1 animation
#define animRect_create(entity, animation) \
/* → */ static const sfIntRect animRect(entity, animation)[] =

// Safety macro to declare the last rectangle of an animation rect array
#define __animRect_sentinel__                                \
/* → */ {                                                    \
/* → */     .top = -1, .left = -1, .height = -1, .width = -1 \
/* → */ }

/*******************************************************************
**
** ANIMATION RECTANGLE TABLE
** ↓
****/

// Macro to access generated arrays
#define animRectTab(entity) \
/* → */ FOXRECTTAB_##entity

// Use this macro to make a rectangle array table
#define animRectTab_create(entity) \
/* → */ extern const sfIntRect *animRectTab(entity)[]

// Use this macro to init a rectangle array table
#define animRectTab_init(entity, size...) \
/* → */ const sfIntRect *animRectTab(entity)[size] =

/*******************************************************************
**
** FRAME SCALING
** ↓
****/

// Macro to acess generated arrays
#define animScale(entity, animation) \
/* → */ FOXANIMSCALE_##entity_##animation

// Use this macro to declare an animation scale table
#define animScale_create(entity, animation) \
/* → */ static const sfVector2f animScale(entity, animation)[] =

// Safety macro to declare the last rectangle of an animation rect array
#define __animScale_sentinel__ \
/* → */ { .top = -1, .left = -1, .height = -1, .width = -1 }

/*******************************************************************
**
** FRAME SCALING TABLE
** ↓
****/

// Macro to access generated arrays
#define animScaleTab(entity) \
/* → */ FOXRECTTAB_##entity

// Use this macro to make a rectangle array table
#define animScaleTab_create(entity) \
/* → */ extern const sfVector2f *animScaleTab(entity)[]

// Use this macro to init a rectangle array table
#define animScaleTab_init(entity, size...) \
/* → */ const sfVector2f *animScaleTab(entity)[size] =

/*******************************************************************
**
** ANIMATION TYPE ARRAY
** ↓
****/

// Macro to access generated arrays
#define animType(name) \
/* → */ FOXANIMTYPE_##name

// Use this macro to create an animation type array
// Size is optional but recommended for safety
#define animeType_create(name) \
/* → */ extern const animtype_t animType(name)[]

// Use this macro to assign values to an animation type array
// Size is optional but recommended for safety
#define animType_init(name, size...) \
/* → */ const animtype_t animType(name)[size] =

#endif /* !ANIMINFO_H */
