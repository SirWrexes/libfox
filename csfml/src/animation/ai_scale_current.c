/*
** EPITECH PROJECT, 2019
** csfml
** File description:
** ai_scale_current.c -- No description
*/

#include "fox_csfml.h"

__Anonnull __AalwaysILext const sfVector2f *ai_scale_current(animinfo_t ai)
{
    return &ai->scale[ai->current][ai->frame];
}
