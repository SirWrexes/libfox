/*
** EPITECH PROJECT, 2019
** Libfox
** File description:
** Get the previous rectangle of current animation
*/

#include "fox_define.h"
#include "fox_csfml.h"

__Anonnull __AalwaysILext const sfIntRect *ai_rect_prev(animinfo_t ai)
{
    return &ai->rect[ai->current][ai->frame - 1];
}
