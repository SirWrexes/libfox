/*
** EPITECH PROJECT, 2020
** io
** File description:
** printers.h -- No description
*/

#ifndef PRINTERS_H
#define PRINTERS_H

#include "fox_types.h"

#include "printf/fstruct.h"

#ifndef PRINTER_TYPE_DEFINED
    #define PRINTER_TYPE_DEFINED
    typedef scount_t (*printer_t)(fstruct_t *, va_list *);
#endif // PRINTER_TYPE_DEFINED

// Format argument printers
scount_t print_integer(fstruct_t *arg, va_list *va);
scount_t print_unsigned(fstruct_t *arg, va_list *va);
scount_t print_unsigned_base(fstruct_t *arg, va_list *va);
scount_t print_character(fstruct_t *arg, va_list *va);
scount_t print_string(fstruct_t *arg, va_list *va);
scount_t print_pointer(fstruct_t *arg, va_list *va);

#endif /* !PRINTERS_H */
