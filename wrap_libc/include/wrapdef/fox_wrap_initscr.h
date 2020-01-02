/*
** EPITECH PROJECT, 2019
** Libfox
** File description:
** Initscr wrapper header
*/

#ifndef WRAP_INITSCR_H
#define WRAP_INITSCR_H

#include "fox_define.h"

// Posible values
//     ¤ -1  Disable breaking (initscr works normally)
//     ¤ 0   Break (return NULL)
//     ¤ n   When n > 0, initscr works n times then breaks.
short *__initscr_counter(void) __Aconst;
#define initscr_counter (*__initscr_counter())

// Set initscr_counter to 0 to provoke instant breaking in your test
// You can use it as a .init in your Test macros.
void break_initscr(void);

// Reset initscr_counter to 1
// Be sure to add .fini = fix_initscr in tests that use initscr_counter !
void fix_initscr(void);

#endif /* !WRAP_INITSCR_H */
