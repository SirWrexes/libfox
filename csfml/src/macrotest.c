/*
** EPITECH PROJECT, 2019
** csfml
** File description:
** macrotest.c -- No description
*/

#include <stdio.h>
#include <stdlib.h>

#include "fox_csfml.h"
#include "test.h"

foxTexture_set(test, "./dontpush/momo.jpg")
{
    .left = 0,
    .top = 0,
    .width = 42,
    .height = 23
};

int main(void)
{
    spinfo_t si = calloc(1, sizeof(*si));

    foxSprite_init(test, si);
    return 0;
}
