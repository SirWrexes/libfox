/*
** EPITECH PROJECT, 2019
** Libfox
** File description:
** Cbreak wrapper header
*/

#ifndef WRAP_CBREAK_H
#define WRAP_CBREAK_H

#include "fox_define.h"

// Posible values
//     ¤ -1  Disable breaking (cbreak works normally)
//     ¤ 0   Break (return ERR)
//     ¤ n   When n > 0, cbreak works n times then breaks.
short *__cbreak_counter(void) __Aconst;
#define cbreak_counter (*__cbreak_counter())

// Set cbreak_counter to 0 to provoke instant breaking in your test
// You can use it as a .init in your Test macros.
void break_cbreak(void);

// Reset cbreak_counter to 1
// Be sure to add .fini = fix_cbreak in tests that use cbreak_counter !
void fix_cbreak(void);

#endif /* !WRAP_CBREAK_H */
