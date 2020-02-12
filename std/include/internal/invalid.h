/*
** EPITECH PROJECT, 2020
** Libfox
** File description:
** invalid.h -- No description
*/

#ifndef INVALID_H
#define INVALID_H

#include "fox_io.h"

__AalwaysIL static inline void invalid_opt(str2c_t prog, char c)
{
    fox_eputstr(prog);
    fox_eputstr(": invalid option -- '");
    fox_eputchar(c);
    fox_eputstr("'\n");
}

__AalwaysIL static inline void opt_requires_arg(str2c_t prog, char c)
{
    fox_eputstr(prog);
    fox_eputstr(": option requires an argument -- '");
    fox_eputchar(c);
    fox_eputstr("'\n");
}

#endif /* !INVALID_H */
