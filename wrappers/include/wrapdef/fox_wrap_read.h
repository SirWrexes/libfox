/*
** EPITECH PROJECT, 2019
** Libfox
** File description:
** Read wrapper header
*/

#ifndef WRAP_READ_H
#define WRAP_READ_H

#include "fox_define.h"

// Posible values
//     ¤ -1  Disable breaking (read works normally)
//     ¤ 0   Break (return -1 and set errno to EBADF)
//     ¤ n   When n > 0, read works n times then breaks.
short *__read_counter(void) __Aconst;
#define read_counter (*__read_counter())

// Set read_counter to 0 to provoke instant breaking in your test
// You can use it as a .init in your Test macros.
void break_read(void);

// Reset read_counter to 1
// Be sure to add .fini = fix_read in tests that use read_counter !
void fix_read(void);

#endif /* !WRAP_READ_H */
