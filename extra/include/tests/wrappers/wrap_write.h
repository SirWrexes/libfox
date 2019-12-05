/*
** EPITECH PROJECT, 2019
** Libfox
** File description:
** Write wrapper header
*/

#ifndef WRAP_WRITE_H
#define WRAP_WRITE_H

#include "fox_define.h"

// Posible values
//     ¤ -1  Disable breaking (write works normally)
//     ¤ 0   Break (return -1 and set errno to EBADF)
//     ¤ n   When n > 0, write works n times then breaks.
short *__write_counter(void) __Aconst;
#define write_counter (*__write_counter())

// Set write_counter to 0 to provoke instant breaking in your test
// You can use it as a .init in your Test macros.
void break_write(void);

// Reset write_counter to 1
// Be sure to add .fini = fix_write in tests that use read_counter !
void fix_write(void);

#endif /* !WRAP_WRITE_H */
