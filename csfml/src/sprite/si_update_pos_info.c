/*
** EPITECH PROJECT, 2019
** csfml
** File description:
** si_update_pos_info.c -- No description
*/

#include "fox_csfml.h"

__Anonnull __AalwaysILext void si_update_pos_info(spinfo_t si)
{
    si->position = sfSprite_getPosition(si->sprite);
}
