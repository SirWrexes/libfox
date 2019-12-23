/*
** EPITECH PROJECT, 2019
** csfml
** File description:
** foxcsfml_common.h -- No description
*/

#ifndef FOXCSFML_COMMON_H
#define FOXCSFML_COMMON_H

#define __expand(x)      x
#define __StaConst(type) static const type

#define FOXCSFML_NAME(name)       FOXCSFML_##name
#define FOXCSFML_ANIMINFO(entity) __expand(FOXCSFML_NAME(entity##_ANIMINFO))

#endif /* !FOXCSFML_COMMON_H */
