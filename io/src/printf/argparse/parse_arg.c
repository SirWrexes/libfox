/*
** EPITECH PROJECT, 2019
** Libfox
** File description:
** Collect information from a format arg starting with %
*/

#include "fox_string.h"
#include "preprocessor/fox_macro.h"

#include "args/parsers.h"
#include "args/farg_datastruct.h"
#include "private/printer_table.h"

static const flagparser_t fp[] =
{
    &get_flags,
    &get_width,
    &get_precision,
    &get_lenmodif,
    NULL
};

__nonnull
extern inline void parse_arg(fstruct_t *arg, str_t *format)
{
    arg->info.is_valid = true;
    arg->fmt = *format + (**format == '%');
    for (hindex_t i = 0; arg->info.is_valid && fp[i] != NULL; i += 1)
        fp[i](&arg->info, &arg->fmt);
    arg->info.spec = *arg->fmt++;
    arg->print = PRINTER[PRINTER_INDEX(arg->info.spec)];
    arg->info.is_valid = (arg->print != NULL);
    if (arg->info.is_valid)
        *format = arg->fmt;
}
