/*
** EPITECH PROJECT, 2019
** csfml
** File description:
** foxcsfml_sound.h -- No description
*/

#ifndef FOXCSFML_SOUND_H
#define FOXCSFML_SOUND_H

#include <stdbool.h>

#include <SFML/Audio/Types.h>

// Sound effect object
typedef struct sound_effect {
    const char *path;           // Path to the sound
    unsigned id;                // Unique sound id
    unsigned type;              // Index of SFX_DEULTS used create the object
    bool loop;                  // Loop the sound effect
    const sfSoundBuffer **buff; // Sound buffer pointer
    sfSound *sound;             // Sound entity
    struct sound_effect *next;  // Next sfx in the list
} * sfx_t;

#endif /* !FOXCSFML_SOUND_H */
