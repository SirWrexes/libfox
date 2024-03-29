/*
** (not) EPITECH PROJECT, 2021
** Libfox
** File description:
** Collect information from a format arg starting with %
*/

#include "fox_define.h"
#include "fox_memory.h"
#include "fox_string.h"

#include "printf/argparse.h"
#include "printf/fstruct.h"
#include "printf/printers.h"

static const flagparser_t FP[] = {
    &get_flags,
    &get_width,
    &get_precision,
    &get_lenmodif,
    NULL,
};

__Anonnull __AalwaysILext void parse_arg(fstruct_t *arg, str2c_t *format)
{
    fox_memset(arg, 0, sizeof(*arg));
    arg->info.is_valid = true;
    arg->info.padchar = ' ';
    arg->fmt = *format + 1;
    for (hindex_t i = 0; arg->info.is_valid && FP[i] != NULL; i += 1)
        FP[i](&arg->info, &arg->fmt);
    arg->info.spec = *arg->fmt++;
    arg->print = PRINTER[PRINTER_INDEX(arg->info.spec)];
    arg->info.is_valid = (arg->print != NULL);
    if (arg->info.is_valid)
        *format = arg->fmt;
}
