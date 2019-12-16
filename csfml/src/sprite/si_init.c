/*
** EPITECH PROJECT, 2019
** csfml
** File description:
** si_sprite_init.c -- No description
*/

#include "fox_csfml.h"

__Anonnull __AalwaysILext bool si_sprite_init(spinfo_t si)
{
    si->sprite = sfSprite_create();
    if (si->sprite != NULL) {
        si_update_texture(si);
        si_update_rect(si);
        si_update_scale(si);
        si_update_pos(si);
    }
    return SUCCESS_IF_DIFF(si->sprite, NULL);
}
