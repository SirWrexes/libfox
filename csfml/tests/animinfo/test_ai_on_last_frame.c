/*
** EPITECH PROJECT, 2019
** csfml unit tests
** File description:
** test_ai_on_last_frame.c -- No description
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

#include "fox_csfml.h"

animRect_create(test, test)
{
    {.top = 23, .left = 42, .height = 9000, .width = 1337},
    {.top = 23, .left = 42, .height = 9000, .width = 1337},
    __animRect_sentinel__
};

static animRectTab_init(test, ANIM_TYPE_COUNT)
{
    [ANIM_TYPE_NONE] = animRect(test, test),
    [ANIM_TYPE_ONCE] = animRect(test, test),
    [ANIM_TYPE_LOOP] = animRect(test, test),
    [ANIM_TYPE_PONG] = animRect(test, test),
};

static animType_init(test, ANIM_TYPE_COUNT)
{
    [ANIM_TYPE_NONE] = ANIM_TYPE_NONE,
    [ANIM_TYPE_ONCE] = ANIM_TYPE_ONCE,
    [ANIM_TYPE_LOOP] = ANIM_TYPE_LOOP,
    [ANIM_TYPE_PONG] = ANIM_TYPE_PONG
};

Test(on_last_frame, anim_none)
{
    struct animation_info ai = {
        .type = animType(test),
        .rect = animRectTab(test),
        .current = ANIM_TYPE_NONE,
        .frame = 0,
    };

    cr_expect(ai_on_last_frame(&ai));
}

Test(on_last_frame, anim_once)
{
    struct animation_info ai = {
        .type = animType(test),
        .rect = animRectTab(test),
        .current = ANIM_TYPE_ONCE,
        .frame = 0,
    };

    cr_expect_not(ai_on_last_frame(&ai));
    ai.frame = 1;
    cr_expect(ai_on_last_frame(&ai));
}

Test(on_last_frame, anim_loop)
{
    struct animation_info ai = {
        .type = animType(test),
        .rect = animRectTab(test),
        .current = ANIM_TYPE_LOOP,
        .frame = 0,
    };

    cr_expect_not(ai_on_last_frame(&ai));
    ai.frame = 1;
    cr_expect(ai_on_last_frame(&ai));
}

Test(on_last_frame, anim_pong)
{
    struct animation_info ai = {
        .type = animType(test),
        .rect = animRectTab(test),
        .current = ANIM_TYPE_PONG,
        .pongstep = PP_FORWARD,
        .frame = 0,
    };

    cr_expect_not(ai_on_last_frame(&ai));
    ai.frame = 1;
    cr_expect(ai_on_last_frame(&ai));
    ai.pongstep = PP_BACKWARD;
    cr_expect_not(ai_on_last_frame(&ai));
    ai.frame = 0;
    cr_expect(ai_on_last_frame(&ai));
}
