/*
** EPITECH PROJECT, 2019
** csfml
** File description:
** si_update_pos.c -- No description
*/

#include "fox_csfml.h"

__Anonnull __AalwaysILext void si_update_pos(spinfo_t si)
{
    sfSprite_setPosition(si->sprite, si->position);
}
