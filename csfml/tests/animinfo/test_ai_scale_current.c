/*
** EPITECH PROJECT, 2019
** csfml unit tests
** File description:
** test_ai_scale_current.c -- No description
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

#include "fox_csfml.h"

animScale_create(test, 1)
{
    {.x = 1.f, .y = 2.f}
};

static animScaleTab_init(test)
{
    animScale(test, 1)
};

Test(ai_scale_current, regular_usage)
{
    struct animation_info ai = {
        .scale = animScaleTab(test),
        .current = 0,
        .frame = 0,
    };

    cr_expect_eq(ai_scale_current(&ai)->x, animScale(test, 1)[0].x);
    cr_expect_eq(ai_scale_current(&ai)->x, animScale(test, 1)[0].x);
}
