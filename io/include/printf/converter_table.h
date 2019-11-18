/*
** EPITECH PROJECT, 2019
** Libfox
** File description:
** Functions converting args to a new string
*/

#ifndef CONVERTERS_H
#define CONVERTERS_H

#include "printf/fstruct.h"

#ifndef CONVERTER_TYPE_DEFINED
    #define CONVERTER_TYPE_DEFINED
    typedef scount_t (*converter_t)(fstruct_t *, va_list *);
#endif // CONVERTER_TYPE_DEFINED

// Format argument converters
scount_t conv_integer(fstruct_t *arg, va_list *va);
scount_t conv_unsigned(fstruct_t *arg, va_list *va);
scount_t conv_unsigned_base(fstruct_t *arg, va_list *va);
scount_t conv_character(fstruct_t *arg, va_list *va);
scount_t conv_string(fstruct_t *arg, va_list *va);
scount_t conv_pointer(fstruct_t *arg, va_list *va);

#endif /* !CONVERTERS_H */
