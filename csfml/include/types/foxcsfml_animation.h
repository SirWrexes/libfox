/*
** EPITECH PROJECT, 2019
** csfml
** File description:
** foxcsfml_animation.h -- No description
*/

#ifndef FOXCSFML_ANIMATION_H
#define FOXCSFML_ANIMATION_H

#include <SFML/Graphics/Rect.h>
#include <SFML/System/Time.h>
#include <SFML/System/Vector2.h>

// Animation types
typedef enum animation_type {
    ANIM_TYPE_NONE, // No animation
    ANIM_TYPE_ONCE, // Stay on last frame after a cycle
    ANIM_TYPE_LOOP, // When last rect is reached, cycle in reverse order
    ANIM_TYPE_PONG, // Rects go back and forth

    ANIM_TYPE_COUNT
} animtype_t;

// Animation info object
typedef struct animation_info {
    const animtype_t type;   // Type
    const sfIntRect *rect;   // Rectangles
    const sfVector2f *scale; // Scale for each frame

    const sfTime tick;  // Update time
    sfTime elapsed;     // Time since last update
    unsigned frame;     // Current frame
    unsigned maxframes; // Maximum number of frames

    enum {
        PP_FORWARD = 1,
        PP_BACKWARD = -1
    } pongstep; // If animation is a ping pong, this is the step incrementer
} * animinfo_t;

#endif /* !FOXCSFML_ANIMATION_H */
