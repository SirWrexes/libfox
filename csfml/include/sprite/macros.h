/*
** EPITECH PROJECT, 2019
** csfml
** File description:
** macros.h -- No description
*/

#ifndef MACROS_H
#define MACROS_H

#include "datastruct.h"

#define siData(sprite) SIDATA_REF_##sprite

// Set an id for a sprite
// Every sprite must have its own unique ID starting from 0
// to max animation count.
// An enum is recommended, example:
//     enum sprites {
//         MYSPRITE_0,
//         MYSPRITE_1,
//         ...
//     };
//     siDef_id(sprite_1, MYSPRITE_1);
#define siDef_id(sprite, id) \
    __StaConst(unsigned) __siData_key(sprite, ID) = (id)

// Set a texture path and area to load
// siDef_texture(my_sprite, "path/to/texture.jpg") = {
//     .left = 23,
//     .top = 42,
//     .height = 24,
//     .width = 32
// };
#define siDef_texture(sprite, path)                                \
    __StaConst(char *) __siData_key(sprite, TEXTUREPATH) = (path); \
    __StaConst(sfIntRect) __siData_key(sprite, TEXTUREAREA)

// Set a default starting position for the sprite
// siDef_position(my_sprite) {.x = 1.2f, .y = 3.f};
#define siDef_position(sprite) \
    __StaConst(sfVector2f) __siData_key(sprite, POSITION)

// Set a default origin for the sprite
// siDef_origin(my_sprite) {.x = 23.f, .y = 42.f};
#define siDef_origin(sprite) \
    __StaConst(sfVector2f) __siData_key(sprite, ORIGIN)

// Define defaults for a sprite
#define siDef_spinfo(sprite)                                        \
    __StaConst(struct sprite_info) __siData_key(sprite, SPINFO) = { \
        .entid = __siData_key(sprite, ID),                          \
        .position = __siData_key(sprite, POSITION),                 \
        .origin = __siData_key(sprite, ORIGIN),                     \
        .animinfo = __aiData_meta_list(sprite),                     \
        .textptr = NULL,                                            \
        .sprite = NULL,                                             \
    };

#endif /* !MACROS_H */
