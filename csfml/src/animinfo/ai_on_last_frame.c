/*
** EPITECH PROJECT, 2019
** csfml
** File description:
** ai_on_last_frame.c -- No description
*/

#include "fox_define.h"

#include "animinfo.h"
#include "datastruct.h"

__Anonnull __AalwaysILext bool ai_on_last_frame(animinfo_t ai)
{
    switch (ai->types[ai->current]) {
        case ANIM_TYPE_ONCE:
        case ANIM_TYPE_LOOP: return ai_next_rect(ai)->top == -1;
        case ANIM_TYPE_PING_PONG:
            return (ai->pongstep == PP_BACKWARD && ai->frame == 0)
                || (ai->pongstep == PP_FORWARD && ai_next_rect(ai)->top == 0);
        case ANIM_TYPE_NONE:
        default: return true;
    }
}
