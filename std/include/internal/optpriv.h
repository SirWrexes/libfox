/*
** (not) EPITECH PROJECT, 2021
** Libfox
** File description:
** Private header for fox_getopt()
*/

#ifndef OPTPRIV_H
#define OPTPRIV_H

#include "fox_define.h"

#include "internal/optdata.h"
#include "internal/arginfo.h"

#define NONOPT(Arg) ((Arg)[0] != '-' || (Arg)[1] == '\0')

// Reorder arguments to separate options and nn options
void getopt_swap_args(str_t *av, godata_t d) __Anonnull;

// Advance to the next argv element
int getopt_advance(argscv_t a, godata_t d) __Anonnull;

// The actual getopt "engine"
int getopt_internal(argscv_t a, str2c_t optstr, godata_t d) __Anonnull;

#endif /* !OPTPRIV_H */
