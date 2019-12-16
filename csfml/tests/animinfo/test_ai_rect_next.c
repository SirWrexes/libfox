/*
** EPITECH PROJECT, 2019
** csfml unit tests
** File description:
** test_ai_current_rect.c -- No description
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

#include "fox_csfml.h"

__FOXRECT_CREATE(testai0)
{
    {.top = 23, .left = 42, .height = 32, .width = 24},
    {.top = 10, .left = 20, .height = 30, .width = 40},
    __FOXRECT_SENTINEL
};

__FOXRECT_CREATE(testai1)
{
    {.top = 10, .left = 20, .height = 30, .width = 40},
    {.top = 23, .left = 42, .height = 32, .width = 24},
    __FOXRECT_SENTINEL
};

static __FOXRECTTAB_INIT(testai)
{
    __FOXRECT(testai0),
    __FOXRECT(testai1)
};

Test(ai_rect_next, regular_usage)
{
    struct animation_info ai = {
        .current = 0,
        .frame = 0,
        .rects = __FOXRECTTAB(testai)
    };

    cr_expect_eq(ai_rect_next(&ai)->left, __FOXRECT(testai1)[0].left);
    cr_expect_eq(ai_rect_next(&ai)->top, __FOXRECT(testai1)[0].top);
    cr_expect_eq(ai_rect_next(&ai)->height, __FOXRECT(testai1)[0].height);
    cr_expect_eq(ai_rect_next(&ai)->width, __FOXRECT(testai1)[0].width);
    ai.current = 1;
    cr_expect_eq(ai_rect_next(&ai)->left, __FOXRECT(testai0)[0].left);
    cr_expect_eq(ai_rect_next(&ai)->top, __FOXRECT(testai0)[0].top);
    cr_expect_eq(ai_rect_next(&ai)->height, __FOXRECT(testai0)[0].height);
    cr_expect_eq(ai_rect_next(&ai)->width, __FOXRECT(testai0)[0].width);
}
