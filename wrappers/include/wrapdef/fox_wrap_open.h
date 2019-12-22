/*
** EPITECH PROJECT, 2019
** Libfox
** File description:
** Open wrapper header
*/

#ifndef WRAP_OPEN_H
#define WRAP_OPEN_H

#include "fox_define.h"

// Posible values
//     ¤ -1  Disable breaking (open works normally)
//     ¤ 0   Break (return -1 set errno to ENOENT)
//     ¤ n   When n > 0, open works n times then breaks.
short *__open_counter(void) __Aconst;
#define open_counter (*__open_counter())

// Set open_counter to 0 to provoke instant breaking in your test
// You can use it as a .init in your Test macros.
void break_open(void);

// Reset open_counter to 1
// Be sure to add .fini = fix_open in tests that use open_counter !
void fix_open(void);

#endif /* !WRAP_OPEN_H */
