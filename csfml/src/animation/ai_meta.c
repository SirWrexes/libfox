/*
** EPITECH PROJECT, 2019
** csfml
** File description:
** ai_meta.c -- No description
*/

#include "fox_csfml.h"

__Anonnull __AalwaysILext animmeta_t ai_meta(animinfo_t ai)
{
    return &ai->meta[ai->current];
}
