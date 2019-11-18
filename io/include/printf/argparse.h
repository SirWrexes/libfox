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
typedef void (*flagparser_t)(finfo_t *, str_t *);
void parse_arg(fstruct_t *arg, str_t *format) __nonnull;
void get_flags(finfo_t *info, str_t *format) __nonnull;
void get_width(finfo_t *info, str_t *format) __nonnull;
void get_precision(finfo_t *info, str_t *format) __nonnull;
void get_lenmodif(finfo_t *info, str_t *format) __nonnull;
void get_convspec(finfo_t *info, str_t *format) __nonnull;

#endif /* !ARGPARSE_H */
