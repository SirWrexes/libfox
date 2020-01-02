/*
** EPITECH PROJECT, 2019
** Libfox
** File description:
** Noecho wrapper header
*/

#ifndef WRAP_NOECHO_H
#define WRAP_NOECHO_H

#include "fox_define.h"

// Posible values
//     ¤ -1  Disable breaking (noecho works normally)
//     ¤ 0   Break (return ERR)
//     ¤ n   When n > 0, noecho works n times then breaks.
short *__noecho_counter(void) __Aconst;
#define noecho_counter (*__noecho_counter())

// Set noecho_counter to 0 to provoke instant breaking in your test
// You can use it as a .init in your Test macros.
void break_noecho(void);

// Reset noecho_counter to 1
// Be sure to add .fini = fix_noecho in tests that use noecho_counter !
void fix_noecho(void);

#endif /* !WRAP_NOECHO_H */
