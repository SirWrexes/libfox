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
** ↓ See datastruct.h's @ section in animation_info definition for
** ↓ more information (until I maybe someday write a real doc).
****/

// Macro to acess generated arrays
#define animRect(name) \
/* → */ FOXANIMRECT_##name

// Use this macro to declare an animation rectangle array for 1 animation
#define animRect_create(name) \
/* → */ static const sfIntRect animRect(name)[] =

// Safety macro to declare the last rectangle of an animation rect array
#define __animRect_sentinel__                                \
/* → */ {                                                    \
/* → */     .top = -1, .left = -1, .height = -1, .width = -1 \
/* → */ }

// Macro to access generated arrays
#define animRectTab(name) \
/* → */ FOXRECTTAB_##name

// Use this macro to make a rectangle array table
#define animRectTab_create(name) \
/* → */ extern const sfIntRect *animRectTab(name)[]

// Use this macro to init a rectangle array table
#define animRectTab_init(name, size...) \
/* → */ const sfIntRect *animRectTab(name)[size] =

/*******************************************************************
**
** ANIMATION TYPE ARRAY
** ↓
****/

// Macro to access generated arrays
#define __FOXANIMTYPE(name) \
/* → */ FOXANIMTYPE_##name

// Use this macro to create an animation type array
// Size is optional but recommended for safety
#define __FOXANIMTAB_CREATE(name) \
/* → */ extern const animtype_t *__FOXANIMTYPE(name)[]

// Use this macro to assign values to an animation type array
// Size is optional but recommended for safety
#define __FOXANIMTYPE_INIT(name, size...) \
/* → */ const animtype_t *__FOXANIMTYPE(name)[##size] =

#endif /* !ANIMINFO_H */
