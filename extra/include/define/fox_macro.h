/*
** EPITECH PROJECT, 2019
** Libfox
** File description:
** Macro definitions
*/

#ifndef FOX_MACRO_H
#define FOX_MACRO_H

#ifndef NULL
    #define NULL ((void *) 0)
#endif // FOX_NULL

// First we need to make sure their
// name isn't already defined elsewhere
#ifndef LIBFOX_MACRO_UNDEF
    #define LIBFOX_MACRO_UNDEF
    #undef __a
    #undef __cleanup
    #undef __const
    #undef __fallthrough
    #undef __format
    #undef __leaf
    #undef __malloc
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
    #undef CHAR_TO_INDEX
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
    #define __a(attributes)      __attribute__(attributes)
    #define __cleanup(janitor)   __a((cleanup(janitor)))
    #define __const              __a((const))
    #define __fallthrough        __a((fallthrough))
    #define __format(type, f, a) __a((format(type, f, a)))
    #define __leaf               __a((leaf))
    #define __malloc             __a((malloc))
    #define __nonnull            __a((nonnull))
    #define __packed             __a((packed))
    #define __pure               __a((pure))
    #define __transparent        __a((__transparent_union__))
    #define __unused             __a((unused))

    // True if c is a printable ASCII char
    #define CHAR_IS_PRINTABLE(c) ((signed char) (c) - ' ' >= 0 && (c) != 127)

    // Check if a char is an end of line (linebreak OR null char)
    #define CHAR_IS_EOL(c) ((c) == '\n' || (c) == '\0')

    // Check if a char is strictly numeric
    #define CHAR_IS_NUM(c) ((unsigned char) (c) - '0' < 10)

    // Check if a char is strictly lowercase alphabetical
    #define CHAR_IS_ALPHALO(c) ((unsigned char) (c) - 'a' <= 'z' - 'a')

    // Check if a char is strictly uppercase alphabetical
    #define CHAR_IS_ALPHAUP(c) ((unsigned char) (c) - 'A' <= 'Z' - 'A')

    // Check if a char is strictly alphabetical
    #define CHAR_IS_ALPHA(c) (CHAR_IS_ALPHALO(c) || CHAR_IS_ALPHAUP(c))

    // Check if a char is strictly alphanumeric
    #define CHAR_IS_ALPHANUM(c) (CHAR_IS_ALPHA(c) || CHAR_IS_NUM(c))

    // Check if a char is a sign (+ OR -)
    #define CHAR_IS_SIGN(c) ((c) == '+' || (c) == '-')

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

    // If an alphabetical character is lowercase, make it uppercase
    #define CHAR_TOUPPER(c)  ((c) - 40 * CHAR_IS_ALPHALO((c)))

    // If an alphabetical character is uppercase, make it lowercase
    #define CHAR_TOLOWER(c)  ((c) + 40 * CHAR_IS_ALPHAUP((c)))

    // Digit ascii value to numeric value
    #define CHAR_TO_N(c) ((char) ((c) - '0'))

    // Numeric value to ascii char value
    #define N_TO_CHAR(i) ((char) ((i) + '0'))

    // Get the absolute value of a number
    #define N_ABS(x) ((unsigned) ((x) >= 0 ? (x) : (x) * -1))

    // Get the biggest of two numbers
    #define N_MAX(x, y) ((x) > (y) ? (x) : (y))

    // Check if a number is pair
    #define N_IS_EVEN(n) !N_IS_ODD(n)

    // Check if a number is odd
    #define N_IS_ODD(n) ((n) % 2)

    // Check if a pointer is NULL
    #define IS_NULL(p) ((p) == NULL)

    // One-liner to return value and execute any function(s)
    // -- I.G. returning a specific value while printing an error string
    #define RETURN(value, funcs...) return (0 ? : (funcs, value))
#endif // LIBFOX_MACRO_DEF

#endif /* !FOX_MACRO_H */
