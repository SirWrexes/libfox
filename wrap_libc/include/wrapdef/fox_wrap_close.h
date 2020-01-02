/*
** EPITECH PROJECT, 2019
** Libfox
** File description:
** Close wrapper header
*/

#ifndef WRAP_CLOSE_H
#define WRAP_CLOSE_H

#include "fox_define.h"

// Posible values
//     ¤ -1  Disable breaking (close works normally)
//     ¤ 0   Break (return -1 and set errno to EBADF)
//     ¤ n   When n > 0, close works n times then breaks.
short *__close_counter(void) __Aconst;
#define close_counter (*__close_counter())

// Set close_counter to 0 to provoke instant breaking in your test
// You can use it as a .init in your Test macros.
void break_close(void);

// Reset close_counter to 1
// Be sure to add .fini = fix_close in tests that use close_counter !
void fix_close(void);

#endif /* !WRAP_CLOSE_H */
