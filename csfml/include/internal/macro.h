/*
** EPITECH PROJECT, 2019
** csfml
** File description:
** macro.h -- No description
*/

#ifndef MACRO_H
#define MACRO_H

#include "fox_csfml.h"

#define __StaConst(type) static const type
#define __ExtConst(type) extern const type
#define __expand(x)      x

#define FOXCSFML_TARGET             spinfodest
#define FOXCSFML_MEMCPY(from, into) fox_memcpy((into), (from), sizeof(*(from)))

#define FOXCSFML_IDENTIFIER(sprite, part) FOXCSFML_##sprite##_##part
#define FOXCSFML_FUNC(sprite, part)       foxcsfml_##sprite##_##part##_init
#define FOXCSFML_PROTO(sprite, part) \
    __Anonnull void FOXCSFML_FUNC(sprite, part)

#define foxSprite(sprite)      FOXCSFML_IDENTIFIER(sprite, base)
#define foxSpriteID(sprite)    FOXCSFML_IDENTIFIER(sprite, id)
#define foxTexturePath(sprite) FOXCSFML_IDENTIFIER(sprite, textpath)
#define foxTextureRect(sprite) FOXCSFML_IDENTIFIER(sprite, textrect)
#define foxAnim(sprite)        FOXCSFML_IDENTIFIER(sprite, anim)

#define FOXCSFML_SPRITE_ADD(spname, id)                                  \
    __StaConst(unsigned) foxSpriteID(spname) = (id);                     \
    __ExtConst(struct sprite_info) foxSprite(spname);                    \
    __ExtConst(sfIntRect) foxTextureRect(spname);                        \
    __ExtConst(char *) foxTexturePath(spname);                           \
    __ExtConst(animinfo_t) foxAnim(spname);                              \
    static inline FOXCSFML_PROTO(spname, base)(spinfo_t FOXCSFML_TARGET) \
    {                                                                    \
        sfTexture *texture = NULL;                                       \
                                                                         \
        if (texture == NULL)                                             \
            texture = sfTexture_createFromFile(                          \
                foxTexturePath(spname), &foxTextureRect(spname));        \
        FOXCSFML_TARGET->entid = __expand(foxSpriteID(spname));          \
        FOXCSFML_TARGET->textptr = texture;                              \
        FOXCSFML_TARGET->sprite = NULL;                                  \
    }

#define FOXCSFML_TEXTURE_SET(sprite, path)       \
    const char *foxTexturePath(sprite) = (path); \
    const sfIntRect foxTextureRect(sprite) =

#define foxSprite_add(sprite, id)   __expand(FOXCSFML_SPRITE_ADD(sprite, id))
#define foxSprite_init(sprite, ptr) FOXCSFML_FUNC(sprite, base)((ptr))

#define foxTexture_set(sprite, path) \
    __expand(FOXCSFML_TEXTURE_SET(sprite, path))

#define foxAnim_set(sprite) __expand(FOXCSFML_ANIM_SET(sprite))

#endif /* !MACRO_H */
