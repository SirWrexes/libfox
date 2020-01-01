/*
** EPITECH PROJECT, 2020
** csfml
** File description:
** entity.h -- No description
*/

#ifndef EXAMPLE_ENTITY_H
#define EXAMPLE_ENTITY_H

#include "../anims/animinfo.h"
#include "../sprite/sprite.h"

#include "events/example_mbp.c"

static const struct game_entity EXAMPLE_ENTITY = {
    .hp = 10,
    .state = ALIVE,
    .tick = {foxTick_milliseconds(2)},
    .on_event = {
        [sfEvtMouseButtonPressed] = &event_example_mbp,
    },
};

#endif /* !EXAMPLE_ENTITY_H */
