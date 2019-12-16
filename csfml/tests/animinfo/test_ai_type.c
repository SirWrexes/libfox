/*
** EPITECH PROJECT, 2019
** csfml unit tests
** File description:
** test_ai_type.c -- No description
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

#include "datastruct.h"

Test(ai_type, regular_usage)
{
    struct animation_info ai = {
        .current = ANIM_TYPE_LOOP,
    }
}
