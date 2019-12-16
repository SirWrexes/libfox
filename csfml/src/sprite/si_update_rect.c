/*
** EPITECH PROJECT, 2019
** csfml
** File description:
** si_update_rect.c -- No description
*/

#include "fox_csfml.h"

__Anonnull __AalwaysILext void si_update_rect(spinfo_t si)
{
    sfSprite_setTextureRect(si->sprite, *ai_rect_current(&si->animinfo));
}
