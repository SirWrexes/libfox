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

#define CONVERTER_INDEX(c) ((c) - ' ')
static const converter_t CONVERTER[] = {
    NULL,                // ' '
    NULL,                // '!'
    NULL,                // '"'
    NULL,                // '#'
    NULL,                // '$'
    &conv_character,     // '%'
    NULL,                // '&'
    NULL,                // '''
    NULL,                // '('
    NULL,                // ')'
    NULL,                // '*'
    NULL,                // '+'
    NULL,                // ','
    NULL,                // '-'
    NULL,                // '.'
    NULL,                // '/'
    NULL,                // '0'
    NULL,                // '1'
    NULL,                // '2'
    NULL,                // '3'
    NULL,                // '4'
    NULL,                // '5'
    NULL,                // '6'
    NULL,                // '7'
    NULL,                // '8'
    NULL,                // '9'
    NULL,                // ':'
    NULL,                // ';'
    NULL,                // '<'
    NULL,                // '='
    NULL,                // '>'
    NULL,                // '?'
    NULL,                // '@'
    NULL,                // 'A'
    NULL,                // 'B'
    NULL,                // 'C'
    NULL,                // 'D'
    NULL,                // 'E'
    NULL,                // 'F'
    NULL,                // 'G'
    NULL,                // 'H'
    NULL,                // 'I'
    NULL,                // 'J'
    NULL,                // 'K'
    NULL,                // 'L'
    NULL,                // 'M'
    NULL,                // 'N'
    NULL,                // 'O'
    &conv_pointer,       // 'P'
    NULL,                // 'Q'
    NULL,                // 'R'
    &conv_string,        // 'S'
    NULL,                // 'T'
    NULL,                // 'U'
    NULL,                // 'V'
    NULL,                // 'W'
    &conv_unsigned_base, // 'X'
    NULL,                // 'Y'
    NULL,                // 'Z'
    NULL,                // '['
    NULL,                // '\'
    NULL,                // ']'
    NULL,                // '^'
    NULL,                // '_'
    NULL,                // '`'
    NULL,                // 'a'
    &conv_unsigned_base, // 'b'
    &conv_character,     // 'c'
    &conv_integer,       // 'd'
    NULL,                // 'e'
    NULL,                // 'f'
    NULL,                // 'g'
    NULL,                // 'h'
    &conv_integer,       // 'i'
    NULL,                // 'j'
    NULL,                // 'k'
    NULL,                // 'l'
    &conv_string,        // 'm'
    NULL,                // 'n'
    &conv_unsigned_base, // 'o'
    &conv_pointer,       // 'p'
    NULL,                // 'q'
    NULL,                // 'r'
    &conv_string,        // 's'
    NULL,                // 't'
    &conv_unsigned,      // 'u'
    NULL,                // 'v'
    NULL,                // 'w'
    &conv_unsigned_base, // 'x'
    NULL,                // 'y'
    NULL,                // 'z'
    NULL,                // '{'
    NULL,                // '|'
    NULL,                // '}'
    NULL,                // '~'
};

#endif /* !CONVERTERS_H */
