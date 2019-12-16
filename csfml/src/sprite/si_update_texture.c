/*
** EPITECH PROJECT, 2019
** csfml
** File description:
** si_update_texture.c -- No description
*/

#include "fox_csfml.h"

__Anonnull __AalwaysILext void si_update_texture(spinfo_t si)
{
    sfSprite_setTexture(si->sprite, si->texture[si->entid], false);
}
