/*
** EPITECH PROJECT, 2019
** csfml unit tests
** File description:
** test_ai_type.c -- No description
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

#include "fox_csfml.h"

static animType_init(test, 1)
{
    ANIM_TYPE_PING_PONG
};

Test(ai_type, regular_usage)
{
    struct animation_info ai = {
        .current = 0,
        .type = animType(test)
    };

    cr_expect_eq(ai_type(&ai), animType(test)[0]);
}
