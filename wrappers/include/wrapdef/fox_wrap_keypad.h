/*
** EPITECH PROJECT, 2019
** Libfox
** File description:
** Keypad wrapper header
*/

#ifndef WRAP_KEYPAD_H
#define WRAP_KEYPAD_H

#include "fox_define.h"

// Posible values
//     ¤ -1  Disable breaking (keypad works normally)
//     ¤ 0   Break (return ERR)
//     ¤ n   When n > 0, keypad works n times then breaks.
short *__keypad_counter(void) __Aconst;
#define keypad_counter (*__keypad_counter())

// Set keypad_counter to 0 to provoke instant breaking in your test
// You can use it as a .init in your Test macros.
void break_keypad(void);

// Reset keypad_counter to 1
// Be sure to add .fini = fix_keypad in tests that use keypad_counter !
void fix_keypad(void);

#endif /* !WRAP_KEYPAD_H */
