/*
** EPITECH PROJECT, 2019
** csfml
** File description:
** anim_current_rect.c -- No description
*/

#include "fox_define.h"
#include "datastruct.h"

__Anonnull __AalwaysILext const sfIntRect *ai_next_rect(animinfo_t ai)
{
    return &ai->rects[ai->current][ai->frame + 1];
}
