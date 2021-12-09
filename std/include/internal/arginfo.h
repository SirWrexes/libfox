/*
** (not) EPITECH PROJECT, 2021
** Libfox
** File description:
** Argument info containers
*/

#ifndef ARGINFO_H
#define ARGINFO_H

#include "fox_define.h"

typedef struct {
    int top;
    int mid;
    int bot;
} argspos_t;

typedef struct argscv {
    int c;
    str_t *v;
} *argscv_t;

#endif /* !ARGINFO_H */
