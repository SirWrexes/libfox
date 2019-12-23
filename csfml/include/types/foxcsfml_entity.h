/*
** EPITECH PROJECT, 2019
** csfml
** File description:
** foxcsfml_entity.h -- No description
*/

#ifndef FOXCSFML_ENTITY_H
#define FOXCSFML_ENTITY_H

#include <stdbool.h>
#include <sys/types.h>

#include <SFML/Window/Event.h>

#include "foxcsfml_sprite.h"

// Entity event function pointer type
typedef struct game_entity *entity_t; // A forward declaration is needed here
typedef void (*entevt_t)(entity_t);

// Sometimes just a simple typedef makes things quite snappy
typedef ssize_t health_t;

// Game entity object
struct game_entity {
    struct game_entity *prev; // Previous entity in the list
    struct game_entity *next; // Next entity in the list

    enum {
        ALIVE,
        DEAD,
    } state;     // Entity's state
    health_t hp; // Entity helth

    const sfTime tick;   // Update time limit
    const sfTime **tock; // Time since last tick

    const entevt_t (*on_event)[sfEvtCount]; // Event handlers

    struct sprite_info spinfo; // Sprite info
};

// Entity list
typedef struct game_entity_list {
    size_t n;      // Number of entities in the list
    entity_t head; // First entity in the list
    entity_t last; // Last entity in the list
} * entlist_t;

#endif /* !FOXCSFML_ENTITY_H */
