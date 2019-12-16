/*
** EPITECH PROJECT, 2019
** csfml
** File description:
** ai_on_last_frame.c -- No description
*/

#include "fox_define.h"
#include "fox_csfml.h"

__Anonnull __AalwaysILext bool ai_on_last_frame(animinfo_t ai)
{
    switch (ai->type[ai->current]) {
        case ANIM_TYPE_ONCE:
        case ANIM_TYPE_LOOP: return ai_rect_next(ai)->top == -1;
        case ANIM_TYPE_PONG:
            return (ai->pongstep == PP_BACKWARD && ai->frame == 0)
                || (ai->pongstep == PP_FORWARD && ai_rect_next(ai)->top == -1);
        case ANIM_TYPE_NONE:
        default: return true;
    }
}
