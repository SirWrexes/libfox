/*
** EPITECH PROJECT, 2019
** csfml
** File description:
** ai_current_type.c -- No description
*/

#include "fox_define.h"
#include "datastruct.h"

__Anonnull __AalwaysILext unsigned ai_type(animinfo_t ai)
{
    return ai->type[ai->current];
}
