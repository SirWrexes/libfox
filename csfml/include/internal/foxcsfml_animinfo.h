/*
** EPITECH PROJECT, 2019
** csfml
** File description:
** foxcsfml_animinfo.h -- No description
*/

#ifndef FOXCSFML_ANIMINFO_H
#define FOXCSFML_ANIMINFO_H

#include "internal/foxcsfml_common.h"

// Define @sprite's animinfo
#define foxAnimInfo(sprite) \
    __StaConst(struct animation_info) FOXCSFML_ANIMINFO(sprite)

#endif /* !FOXCSFML_ANIMINFO_H */
