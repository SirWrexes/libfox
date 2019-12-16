/*
** EPITECH PROJECT, 2019
** Libfox
** File description:
** Get the address of current animation's first rectangle
*/

#include "fox_define.h"
#include "datastruct.h"

__Anonnull __AalwaysILext const sfIntRect *ai_rect_first(animinfo_t ai)
{
    return &ai->rect[ai->current][0];
}
