/*
** (not) EPITECH PROJECT, 2021
** Libfox
** File description:
** Assignation of printer functions to their corresponding character
*/

#ifndef PRINTERS_H
#define PRINTERS_H

#include "fox_types.h"

#include "printf/fstruct.h"

#ifndef PRINTER_TYPE_DEFINED
    #define PRINTER_TYPE_DEFINED
    typedef scount_t (*printer_t)(int fd, fstruct_t *, va_list *);
#endif // PRINTER_TYPE_DEFINED

// Format argument printers
scount_t print_character(int fd, fstruct_t *arg, va_list *va);
scount_t print_integer(int fd, fstruct_t *arg, va_list *va);
scount_t print_percent(int fd, fstruct_t *arg, va_list *__Aunused);
scount_t print_pointer(int fd, fstruct_t *arg, va_list *va);
scount_t print_strerror(int fd, fstruct_t *arg, va_list *__Aunused);
scount_t print_string(int fd, fstruct_t *arg, va_list *va);
scount_t print_unsigned(int fd, fstruct_t *arg, va_list *va);
scount_t print_unsigned_base(int fd, fstruct_t *arg, va_list *va);

#define PRINTER_INDEX(c) ((c) - ' ')
static const printer_t PRINTER[] = {
    NULL,                 // ' '
    NULL,                 // '!'
    NULL,                 // '"'
    NULL,                 // '#'
    NULL,                 // '$'
    &print_percent,       // '%'
    NULL,                 // '&'
    NULL,                 // '''
    NULL,                 // '('
    NULL,                 // ')'
    NULL,                 // '*'
    NULL,                 // '+'
    NULL,                 // ','
    NULL,                 // '-'
    NULL,                 // '.'
    NULL,                 // '/'
    NULL,                 // '0'
    NULL,                 // '1'
    NULL,                 // '2'
    NULL,                 // '3'
    NULL,                 // '4'
    NULL,                 // '5'
    NULL,                 // '6'
    NULL,                 // '7'
    NULL,                 // '8'
    NULL,                 // '9'
    NULL,                 // ':'
    NULL,                 // ';'
    NULL,                 // '<'
    NULL,                 // '='
    NULL,                 // '>'
    NULL,                 // '?'
    NULL,                 // '@'
    NULL,                 // 'A'
    NULL,                 // 'B'
    NULL,                 // 'C'
    NULL,                 // 'D'
    NULL,                 // 'E'
    NULL,                 // 'F'
    NULL,                 // 'G'
    NULL,                 // 'H'
    NULL,                 // 'I'
    NULL,                 // 'J'
    NULL,                 // 'K'
    NULL,                 // 'L'
    NULL,                 // 'M'
    NULL,                 // 'N'
    NULL,                 // 'O'
    &print_pointer,       // 'P'
    NULL,                 // 'Q'
    NULL,                 // 'R'
    &print_string,        // 'S'
    NULL,                 // 'T'
    NULL,                 // 'U'
    NULL,                 // 'V'
    NULL,                 // 'W'
    &print_unsigned_base, // 'X'
    NULL,                 // 'Y'
    NULL,                 // 'Z'
    NULL,                 // '['
    NULL,                 // '\'
    NULL,                 // ']'
    NULL,                 // '^'
    NULL,                 // '_'
    NULL,                 // '`'
    NULL,                 // 'a'
    &print_unsigned_base, // 'b'
    &print_character,     // 'c'
    &print_integer,       // 'd'
    NULL,                 // 'e'
    NULL,                 // 'f'
    NULL,                 // 'g'
    NULL,                 // 'h'
    &print_integer,       // 'i'
    NULL,                 // 'j'
    NULL,                 // 'k'
    NULL,                 // 'l'
    &print_strerror,      // 'm'
    NULL,                 // 'n'
    &print_unsigned_base, // 'o'
    &print_pointer,       // 'p'
    NULL,                 // 'q'
    NULL,                 // 'r'
    &print_string,        // 's'
    NULL,                 // 't'
    &print_unsigned,      // 'u'
    NULL,                 // 'v'
    NULL,                 // 'w'
    &print_unsigned_base, // 'x'
    NULL,                 // 'y'
    NULL,                 // 'z'
    NULL,                 // '{'
    NULL,                 // '|'
    NULL,                 // '}'
    NULL,                 // '~'
};

#endif /* !PRINTERS_H */
