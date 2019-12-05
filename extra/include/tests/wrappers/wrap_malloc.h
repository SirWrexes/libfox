/*
** EPITECH PROJECT, 2019
** Libfox
** File description:
** Malloc wrapper header
*/

#ifndef WRAP_MALLOC_H
#define WRAP_MALLOC_H

#include "fox_define.h"

// Posible values
//     ¤ -1  Disable breaking (malloc works normally)
//     ¤ 0   Break (return NULL and set errno to ENOMEM)
//     ¤ n   When n > 0, malloc works n times then breaks.
short *__malloc_counter(void) __Aconst;
#define malloc_counter (*__malloc_counter())

// Set malloc_counter to 0 to provoke instant breaking in your test
// You can use it as a .init in your Test macros.
void break_malloc(void);

// Reset malloc_counter to 1
// Be sure to add .fini = fix_malloc in tests that use malloc_counter !
void fix_malloc(void);

#endif /* !WRAP_MALLOC_H */
