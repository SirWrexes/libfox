/*
** EPITECH PROJECT, 2019
** Libfox
** File description:
** CSFML helper data structure header
*/

#ifndef DATASTRUCT_H
#define DATASTRUCT_H

#include <stdbool.h>
#include <sys/types.h>

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Window.h>

/*******************************************************************
**
** TYPE DEFINITIONS
** ↓
****/

// Sound effect object
typedef struct sound_effect *sfx_t;

// Animation type
// [NONE, ONCE, LOOP, PING_PONG]
typedef enum animation_type animtype_t;

// Sprite animation info
typedef struct animation_info *animinfo_t;

// Sprinte info
typedef struct sprite_info *spinfo_t;

// Game entity
typedef struct game_entity *entity_t;

// Entity event function
typedef void (*entevt_t)(entity_t *);

// Entity list
typedef struct game_entity_list *entlist_t;

// Scene object
typedef struct game_scene *scene_t;

// Scene event function
typedef void (*scnevt_t)(scene_t *);

/*******************************************************************
**
** SOUND EFFECTS
** ↓
****/

// Sound effect object
struct sound_effect {
    const char *path;           // Path to the sound
    unsigned id;                // Unique sound id
    unsigned type;              // Index of SFX_DEULTS used create the object
    bool loop;                  // Loop the sound effect
    const sfSoundBuffer **buff; // Sound buffer pointer
    sfSound *sound;             // Sound entity
    sfx_t next;                 // Next sfx in the list
};

/*******************************************************************
**
** ANIMATIONS
** ↓
****/

// Animation types
enum animation_type {
    ANIM_TYPE_NONE, // No animation
    ANIM_TYPE_ONCE, // Stay on last frame after a cycle
    ANIM_TYPE_LOOP, // When last rect is reached, cycle in reverse order
    ANIM_TYPE_PONG, // Rects go back and forth

    ANIM_TYPE_COUNT
};

// Animation info object
struct animation_info {
    const unsigned total;     // Total count of animations
    const animtype_t *type;   // Anim types      // @type[total]
    const sfIntRect **rect;   // Anim rectangles // @rect[total][frame]
    const sfVector2f **scale; // Anim scales     // @scale[total][frame]

    unsigned current; // Current animation
    unsigned frame;   // Current frame

    enum {
        PP_FORWARD = 1,
        PP_BACKWARD = -1
    } pongstep; // If animation is a ping pong, this is the step incrementer
};

/*******************************************************************
**
** SPRITE INFO
** ↓
****/

// Sprite object
struct sprite_info {
    unsigned entid;            // Type of the entity the sprite is attached to
    const sfTexture **texture; // Textures            // @*texture[MAX{entid}]
    sfSprite *sprite;          // Sprite itself
    sfVector2f position;       // Sprite starting position
    sfVector2f origin;         // Sprite center

    struct animation_info animinfo; // Animation info
};

/*******************************************************************
**
** ENTITY INFO
** ↓
****/

// Game entity object
struct game_entity {
    struct game_entity *prev; // Previous entity in the list
    struct game_entity *next; // Next entity in the list

    struct sprite_info spinfo; // Sprite info

    bool alive;     // Entity's state
    ssize_t health; // Entity helth

    sfTime tick;         // Update time limit
    const sfTime **tock; // Time since last tick

    const entevt_t (*on_event)[sfEvtCount];
};

// Entity list
struct game_entity_list {
    size_t n;      // Number of entities in the list
    entity_t head; // First entity in the list
    entity_t last; // Last entity in the list
};

/*******************************************************************
**
** SCENE INFO
** ↓
****/

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

#endif /* !DATASTRUCT_H */
