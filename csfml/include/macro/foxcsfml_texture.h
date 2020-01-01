/*
** EPITECH PROJECT, 2020
** csfml
** File description:
** foxcsfml_texture.h -- No description
*/

#ifndef FOXCSFML_TEXTURE_H
#define FOXCSFML_TEXTURE_H

#include <SFML/Graphics/Texture.h>

#include "types/foxcsfml_sprite.h"

// Name: the identifier you'll use when setting a sprite's default spinfo.
// Path: where the image will be loaded. Either bsolute or relative to binary.
// Area: an sfIntRect, if height + width = 0, the whole image will be loaded.
//  \_| Shall be of the form {.left = A, .top = B, .width = C, .height = D},
//    | If you don't want to use designated identifiers, be sure to leave the
//    | order unchanged.
#define foxTexture_add(Name, Path, Area)                                  \
    static const struct sfTexture *(Name);                                \
    /*                                                                    \
    ** The constructor attribute makes sure this                          \
    ** is initialized before starting your main.                          \
    */                                                                    \
    __attribute__((constructor)) static inline void init_##Name(void)     \
    {                                                                     \
        textureinfo_t tinfo = {.path = (Path), .area = Area};             \
                                                                          \
        (Name) = sfTexture_createFromFile(tinfo.path,                     \
            (tinfo.area.height + tinfo.area.width) ? &tinfo.area : NULL); \
    }

#endif /* !FOXCSFML_TEXTURE_H */
