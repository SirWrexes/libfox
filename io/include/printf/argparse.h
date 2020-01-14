/*
** EPITECH PROJECT, 2019
** Libfox
** File description:
** Functions parsing format arguments
*/

#ifndef ARGPARSE_H
#define ARGPARSE_H

#include "printf/fstruct.h"

// Format argument parsers
typedef void (*flagparser_t)(finfo_t *, str2c_t *);
void parse_arg(fstruct_t *arg, str2c_t *format) __Anonnull;
void get_flags(finfo_t *info, str2c_t *format) __Anonnull;
void get_width(finfo_t *info, str2c_t *format) __Anonnull;
void get_precision(finfo_t *info, str2c_t *format) __Anonnull;
void get_lenmodif(finfo_t *info, str2c_t *format) __Anonnull;
void get_convspec(finfo_t *info, str2c_t *format) __Anonnull;

#endif /* !ARGPARSE_H */
