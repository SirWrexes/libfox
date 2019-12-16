/*
** EPITECH PROJECT, 2019
** csfml unit tests
** File description:
** test_ai_type.c -- No description
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

#include "fox_csfml.h"

static animType_init(test, ANIM_TYPE_COUNT)
{
    [ANIM_TYPE_NONE] = ANIM_TYPE_NONE,
    [ANIM_TYPE_ONCE] = ANIM_TYPE_ONCE,
    [ANIM_TYPE_LOOP] = ANIM_TYPE_LOOP,
    [ANIM_TYPE_PONG] = ANIM_TYPE_PONG
};

Test(ai_type, regular_usage)
{
    struct animation_info ai = {
        .current = 0,
        .type = animType(test)
    };

    for (animtype_t i = 0; i < ANIM_TYPE_COUNT; i += 1) {
        ai.current = i;
        cr_expect_eq(ai_type(&ai), animType(test)[ai.current]);
    }
}
