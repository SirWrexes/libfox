/*
** EPITECH PROJECT, 2019
** csfml
** File description:
** si_sprite_update_scale.c -- No description
*/

#include "fox_csfml.h"

__Anonnull __AalwaysILext void si_update_scale(spinfo_t si)
{
    sfSprite_setScale(si->sprite, *ai_scale_current(&si->animinfo));
}
