/*
** EPITECH PROJECT, 2019
** Libfox
** File description:
** open wrapper header
*/

#ifndef WRAP_OPEN_H
#define WRAP_OPEN_H

#include <criterion/criterion.h>
#include "fox_define.h"

// I don't want stupid false positives about naming convention errors
#define real_open __real_open
#define wrap_open __wrap_open

// Posible values
//     ¤ -1  Disable breaking (open works normally)
//     ¤ 0   Break (return NULL and set errno to ENOMEM)
//     ¤ n   When n > 0, open works n times then breaks.
short *__open_counter(void) __a((const));
#define open_counter (*__open_counter())

// Set open_counter to 0 to provoke instant breaking in your test
// You can use it as a .init in your Test macros.
void break_open(void);

// Reset open_counter to 1
// Be sure to add .fini = fix_open in tests that use open_counter !
void fix_open(void);

#endif /* !WRAP_OPEN_H */
