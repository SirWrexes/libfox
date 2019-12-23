/*
** EPITECH PROJECT, 2019
** csfml
** File description:
** foxcsfml_scene.h -- No description
*/

#ifndef FOXCSFML_SCENE_H
#define FOXCSFML_SCENE_H

#include <SFML/Audio/Types.h>
#include <SFML/Graphics/Types.h>
#include <SFML/Window/Event.h>
#include <SFML/Window/VideoMode.h>

#include "foxcsfml_entity.h"

// Scene event function pointer type
typedef struct game_scene *scene_t; // Forward definition needed
typedef void (*scnevt_t)(scene_t *);

// Scene object
struct game_scene {
    struct {                     // Window data
        const char **title;      // Window titles
        const sfVideoMode *mode; // Window video modes
        unsigned style;          // Window style
        sfRenderWindow *ptr;     // Scene window
    } window;

    sfMusic *bgmusic;                 // Music for the scene
    sfEvent event;                    // Event container
    struct game_entity_list entities; // Scene entities

    const scnevt_t (*on_event)[sfEvtCount];

    struct sprite_info bgsprites[]; // Array of sprite info for background
};

#endif /* !FOXCSFML_SCENE_H */
