/*
** EPITECH PROJECT, 2019
** Libfox
** File description:
** Format argument data structure
*/

#ifndef ARGS_H
#define ARGS_H

#include <stdbool.h>
#include <stdarg.h>
#include <sys/types.h>
#include "fox_define.h"

typedef struct format_struct fstruct_t;
#ifndef CONVERTER_TYPE_DEFINED
    #define CONVERTER_TYPE_DEFINED
    typedef scount_t (*converter_t)(fstruct_t *, va_list *);
#endif // CONVERTER_TYPE_DEFINED

typedef struct {
    unsigned prec;           // Precision
    unsigned width;          // Field width
    char padchar;            // Field fill char ('0'/' ' flags)

    char spec;               // Format letter

    bool is_char : 1;        // hh length modifier
    bool is_short : 1;       // h length modifier
    bool is_long : 1;        // l length modifier
    bool is_long_long : 1;   // ll length modifier
    bool is_long_double : 1; // L length modifier

    bool alt : 1;            // # flag
    bool group : 1;          // ' flag
    bool left : 1;           // - flag
    bool showsign : 1;       // + flag
    bool space : 1;          // Space flag

    bool is_valid : 1;       // For invalid formats

    const int bfpad : 5;     // Bit field padding

    ushort_t infomask;       // Mask containgin all the previous info
} finfo_t; // Flags, field width, conversion specifier etc.

typedef union {
    char av_char;       // hhi, hhd
    short av_short;     // hi, hd
    ushort_t av_ushort; // hu
    int av_int;         // d, i
    wchar_t av_wchar;   // lc
    long av_long;       // ld, li
    size_t av_size;     // zu
    ssize_t av_ssize;   // zi, zd
    llong_t av_llong;   // lli, lld
    uchar_t av_uchar;   // hhu, c
    unsigned av_uint;   // u
    ulong_t av_ulong;   // lu, lb, lo, lx, lX
    ullong_t av_ullong; // llu, llb, llo, llx, llX
    str2c_t av_str;     // s, S
    void *av_ptr;       // p, P
} fargv_t; // Format argument value

struct format_struct {
    finfo_t info;      // Info from "%<...>"
    fargv_t value;     // Argument value
    scount_t chars;    // Number of chars written
    str_t fmt;         // Start of the format when parsing begins
    str_t buff;        // Buffer string containing the converted arg
    converter_t print; // Printer functtion
}; // Struct bundling everything needed to print format arguments

#endif /* !ARGS_H */
