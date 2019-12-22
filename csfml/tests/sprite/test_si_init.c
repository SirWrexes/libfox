/*
** EPITECH PROJECT, 2019
** csfml unit tests
** File description:
** test_sprite_init.c -- No description
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

#include "fox_csfml.h"

static const struct sprite_info FOXSPINFO_test = {
    .entid = 0,
    .textptr = &FOXTEXTURE_test,
    .sprite = NULL,
    .position = {.x = 2.3f, .y = 4.2f},
    .origin = {.x = 1.f, .y = 2.f},

}

Test(si_init, regular_usage)
{

}
