/*
** EPITECH PROJECT, 2019
** Libfox
** File description:
** Printing a pointer as its hex value preceeded by 0x
*/

#include "args/farg_datastruct.h"
#include "printers.h"

__nonnull
extern inline scount_t print_pointer(fstruct_t *arg, va_list *va)
{
    arg->info.alt = true;
    arg->info.is_long = true;
    arg->info.prec = arg->info.prec == 'p' ? 'x' : 'X';
    return print_unsigned_base(arg, va);
}
