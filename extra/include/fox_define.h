/*
** EPITECH PROJECT, 2018
** libfox
** File description:
** Libfox macros
*/

#ifndef FOX_MACRO
#define FOX_MACRO

#include <stddef.h>

/*
** Following macros are sorted in contextual order and follow this template :
**
**     // What purpose the macro serves
**     #define NAME (instruction)
*/

// First we need to make sure their
// name isn't already defined elsewhere
#ifndef LIBFOX_MACRO_UNDEF
    #define LIBFOX_MACRO_UNDEF
    #undef __a
    #undef __cleanup
    #undef __nonnull
    #undef __packed
    #undef __pure
    #undef __transparent
    #undef __unused
    #undef CHAR_IS_ALPHA
    #undef CHAR_IS_ALPHALO
    #undef CHAR_IS_ALPHANUM
    #undef CHAR_IS_ALPHAUP
    #undef CHAR_IS_EOL
    #undef CHAR_IS_NUM
    #undef CHAR_IS_OP
    #undef CHAR_IS_PRINTABLE
    #undef CHAR_IS_PUNCT
    #undef CHAR_IS_SIGN
    #undef CHAR_TOLOWER
    #undef CHAR_TOUPPER
    #undef CHAR_TO_N
    #undef IS_NULL
    #undef N_ABS
    #undef N_IS_ODD
    #undef N_IS_PAIR
    #undef N_MAX
    #undef N_TO_CHAR
    #undef STR_ALPHABET
    #undef STR_ALPHALO
    #undef STR_ALPHANUM
    #undef STR_ALPHAUP
    #undef STR_NUMERIC
    #undef RETURN
#endif // LIBFOX_MACRO_UNDEF

// Then we can actually start defining them.
#ifndef LIBFOX_MACRO_DEF
    #define LIBFOX_MACRO_DEF

    // Shorter ways of writing attributes
    // For more information about these, check GNU GCC's docs
    // CAREFUL: These have RESTRICTED PORTABILITY
    #define __a(attributes)    __attribute__(attributes)
    #define __const            __a((const))
    #define __cleanup(janitor) __a((cleanup(janitor)))
    #define __malloc           __a((malloc))
    #define __nonnull          __a((nonnull))
    #define __packed           __a((packed))
    #define __pure             __a((pure))
    #define __transparent      __a((__transparent_union__))
    #define __unused           __a((unused))

    // Digit ascii value to numeric value
    #define CHAR_TO_N(c) ((int) ((c) - '0'))

    // Numeric value to ascii char value
    #define N_TO_CHAR(i) ((char) ((i) + '0'))

    // True if c is a printable ASCII char
    #define CHAR_IS_PRINTABLE(c) ((c) >= 32 && (c) <= 126)

    // If an alphabetical character is lowercase, make it uppercase
    #define CHAR_TOUPPER(c)  ((c) >= 'a' && (c) <= 'z' ? (c) - 32 : (c))

    // If an alphabetical character is uppercase, make it lowercase
    #define CHAR_TOLOWER(c)  ((c) + 32 * ((c) >= 'A' && (c) <= 'Z'))

    // Check if a pointer is NULL
    #define IS_NULL(p) ((p) == NULL)

    // Check if a char is an end of line (linebreak OR null char)
    #define CHAR_IS_EOL(c) ((c) == '\n' || (c) == '\0')

    // Check if a char is strictly lowercase alphabetical
    #define CHAR_IS_ALPHALO(c) ((c) >= 'a' && (c) <= 'z')

    // Check if a char is strictly uppercase alphabetical
    #define CHAR_IS_ALPHAUP(c) ((c) >= 'A' && (c) <= 'Z')

    // Check if a char is strictly alphabetical
    #define CHAR_IS_ALPHA(c) (CHAR_IS_ALPHALO(c) || CHAR_IS_ALPHAUP(c))

    // Check if a char is strictly numeric
    #define CHAR_IS_NUM(c) ((c) >= '0' && (c) <= '9')

    // Check if a number is pair
    #define N_IS_PAIR(n) !((n) % 2)

    // Check if a number is odd
    #define N_IS_ODD(n) ((n) % 2)

    // Check if a char is strictly alphanumeric
    #define CHAR_IS_ALPHANUM(c) (CHAR_IS_ALPHA(c) || CHAR_IS_NUM(c))

    // Check if a char is punctuation
    #define CHAR_IS_PUNCT(c)    \
    (                           \
        ((c) == '\'')           \
        || ((c) == '\"')        \
        || ((c) == ',')         \
        || ((c) == '.')         \
        || ((c) == '?')         \
        || ((c) == '!')         \
        || ((c) == ';')         \
        || ((c) == ':')         \
        || ((c) == '(')         \
        || ((c) == ')')         \
        || ((c) == '-')         \
        || ((c) == '/')         \
    )                           \

    // Check if a char is a sign (+ OR -)
    #define CHAR_IS_SIGN(c) ((c) == '+' || (c) == '-')

    // Get the absolute value of a number
    #define N_ABS(x) ((unsigned) ((x) >= 0 ? (x) : (x) * -1))

    // Get the biggest of two numbers
    #define N_MAX(x, y) ((x) > (y) ? (x) : (y))

    // One-liner to return value and execute any function(s)
    // -- I.G. returning a specific value while printing an error string
    #define RETURN(value, funcs...) return (0 ? : (funcs, value))
#endif // LIBFOX_MACRO_DEF

#ifndef NULL
    #define NULL ((void *) 0)
#endif // FOX_NULL

#ifndef FOX_WHITESPACE_DEF
    #define FOX_WHITESPACE_DEF
    #define STR_WHITESPACE " \t\n"
#endif // FOX_WHITESAPCE_DEF

#ifndef FOX_STR_DEF
    #define FOX_ALPHANUM_DEF
    #define STR_ALPHAUP  "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    #define STR_ALPHALO  "abcdefghijklmnopqrstuvwxyz"
    #define STR_ALPHABET STR_ALPHALO STR_ALPHAUP
    #define STR_NUMERIC  "0123456789"
    #define STR_ALPHANUM STR_ALPHABET STR_NUMERIC
    #define STR_OPERATOR "+-*/%"
    #define STR_EXPR     STR_OPERATOR STR_NUMERIC STR_WHIESTAPCE
#endif // FOX_STR_DEF

#ifndef FOX_CCSTR_TYPE
    #define FOX_CCSTR_TYPE
    typedef char const * const * const  str4c_t;
    typedef char const * const          str3c_t;
    typedef char const *                str2c_t;
    typedef char *                      str_t;
#endif // FOX_CCSTR_TYPE

#ifndef FOX_USHORT_TYPE
    #define FOX_USHORT_TYPE
    typedef unsigned short sindex_t;
#endif // FOX_USHORT_TYPE

#ifndef FOX_ULONG_TYPE
    #define FOX_ULONG_TYPE
    typedef unsigned long ulong_t;
    typedef unsigned long count_t;
    typedef unsigned long index_t;
#endif

#ifndef FOX_LLONG_TYPE
    #define FOX_LLONG_TYPE
    typedef          long long llong_t;
    typedef unsigned long long ullong_t;
#endif // FOX_LLONG_TYPE

#ifndef FOX_WTAB_TYPE
    #define FOX_WTAB_TYPE
    typedef struct word_array_s {
        size_t size;
        str_t *word;
    } wtab_t;
#endif // FOX_WTAB_TYPE

#endif // FOX_MACRO
