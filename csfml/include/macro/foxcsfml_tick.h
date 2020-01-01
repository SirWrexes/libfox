/*
** EPITECH PROJECT, 2019
** csfml
** File description:
** foxcsfml_tick.h -- No description
*/

#ifndef FOXCSFML_TICK_H
#define FOXCSFML_TICK_H

#include <SFML/Config.h>

#define foxTick_seconds(n)      ((sfUint64) ((n) * 1000000))
#define foxTick_milliseconds(n) ((sfUint64) ((n) * 1000))
#define foxTick_microseconds(n) ((sfUint64) (n))

#endif /* !FOXCSFML_TICK_H */
