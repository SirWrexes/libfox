/*
** (not) EPITECH PROJECT, 2021
** Libfox
** File description:
** A collection of pretty useful macros !
*/

#ifndef FOX_MACRO_H
#define FOX_MACRO_H

/************************************
** Useful standard macro definitions*
************************************/

// Null pointer
// (originally in stddef.h)
#ifndef NULL
    #define NULL ((void *) 0)
#endif // FOX_NULL

// Exit value when everthing went well
// (originally in stddef.h)
#ifndef EXIT_SUCCESS
    #define EXIT_SUCCESS (0)
#endif // FOX_EXIT_SUCCESS

// Number of bit in a char
// (originally in limits.h)
#ifndef CHAR_BIT
    #define CHAR_BIT (8)
#endif // CHAR_BIT

// Maximum length of any multibyte character in any locale
// (originally in limits.h)
#ifndef MB_LEN_MAX
    #define MB_LEN_MAX (16)
#endif // MB_LEN_MAX

// Maximum length of a human-readable string
// (originally in glibc's human.h)
/* clang-format off */
#ifndef LONGEST_HUMAN_READABLE
    #define LONGEST_HUMAN_READABLE  \
    (                               \
        (                           \
            2                       \
            * sizeof(uintmax_t)     \
            * CHAR_BIT              \
            * 146                   \
            / 485                   \
            + 1                     \
        ) * (MB_LEN_MAX + 1)        \
        - MB_LEN_MAX + 1 + 3        \
    )
#endif  // LONGEST_HUMAN_READABLE

// Unlikely for conditions that are rarely met
// (originally in glibc's sys/cdefs.h)
#ifndef __unlikely
    #if __GNUC__ >= 3
        #define __unlikely(cond)	__builtin_expect((!!(cond)), 0)
    #else
        #define __unlikely(cond)	(!!(cond))
    #endif
#endif

// Likely for conditions that are rarely not met
// (originally in glibc's sys/cdefs.h)
#ifndef __likely
    #if __GNUC__ >= 3
        #define __likely(cond)	__builtin_expect(!!(cond), 1)
    #else
        #define __likely(cond)	(!!(cond))
    #endif
#endif

/***********************************
**     Libfox macro collection     *
************************************/

// First we need to make sure Fox macros aren't already defined elsewhere
#ifndef LIBFOX_MACRO_UNDEF
    #define LIBFOX_MACRO_UNDEF
    #undef __a
    #undef __AalwaysIL
    #undef __AalwaysILext
    #undef __Acleanup
    #undef __Aconst
    #undef __Aconstructor
    #undef __Adestructor
    #undef __Afallthrough
    #undef __Aformat
    #undef __Ahidden
    #undef __Aleaf
    #undef __Amalloc
    #undef __Anonnull
    #undef __Apacked
    #undef __Apure
    #undef __Atransparent
    #undef __Aunused
    #undef __AweakAlias
    #undef ARRAY_SIZE
    #undef CHAR_IS_ALPHA
    #undef CHAR_IS_ALPHALO
    #undef CHAR_IS_ALPHANUM
    #undef CHAR_IS_ALPHAUP
    #undef CHAR_IS_EOL
    #undef CHAR_IS_NUM
    #undef CHAR_IS_OP
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
    #undef SUCCESS_IF_DIFF
    #undef EPITECH_ERROR
    #undef RETURN
#endif // LIBFOX_MACRO_UNDEF

// Then we can actually start defining them.
#ifndef LIBFOX_MACRO_DEF
    #define LIBFOX_MACRO_DEF

    // Shorter ways of writing attributes
    // For more information about these, check GNU GCC's docs
    // CAREFUL: These have RESTRICTED PORTABILITY
    #define __a(attributes)       __attribute__(attributes)
    #define __AallocSz(...)       __a((alloc_size(__VA_ARGS__)))
    #define __AalwaysIL           __a((always_inline))
    #define __AalwaysILext        __a((always_inline)) extern inline
    #define __Acleanup(janitor)   __a((cleanup(janitor)))
    #define __Aconst              __a((const))
    #define __Aconstructor        __a((constructor))
    #define __Adestructor         __a((destructor))
    #define __Afallthrough        __a((fallthrough))
    #define __Aformat(type, f, a) __a((format(type, f, a)))
    #define __Ahidden             __a((visibility("hidden")))
    #define __Aleaf               __a((leaf))
    #define __Amalloc             __a((malloc))
    #define __Anonnull            __a((nonnull))
    #define __Apacked             __a((packed))
    #define __Apure               __a((pure))
    #define __Atransparent        __a((__transparent_union__))
    #define __Aunused             __a((unused))
    #define __AweakAlias(f)       __a((weak, alias(#f)))

    // Get the number of elements in a non flexible array
    #define ARRAY_SIZE(array) (sizeof((array)) / sizeof((*array)))

    // Check if a char is an end of line (linebreak OR null char)
    #define CHAR_IS_EOL(c) ((c) == '\n' || (c) == '\0')

    // Check if a char is strictly numeric
    #define CHAR_IS_NUM(c) (((unsigned char) ((c) - '0')) < 10)

    // Check if a char is strictly lowercase alphabetical
    #define CHAR_IS_ALPHALO(c) ((unsigned char) ((c) - 'a') <= ('z' - 'a'))

    // Check if a char is strictly uppercase alphabetical
    #define CHAR_IS_ALPHAUP(c) ((unsigned char) ((c) - 'A') <= ('Z' - 'A'))

    // Check if a char is strictly alphabetical
    #define CHAR_IS_ALPHA(c) (CHAR_IS_ALPHALO(c) || CHAR_IS_ALPHAUP(c))

    // Check if a char is strictly alphanumeric
    #define CHAR_IS_ALPHANUM(c) (CHAR_IS_ALPHA(c) || CHAR_IS_NUM(c))

    // Check if a char is a sign (+ OR -)
    #define CHAR_IS_SIGN(c) ((c) == '+' || (c) == '-')

    // Check if a char is punctuation
    /* clang-format off */
    #define CHAR_IS_PUNCT(c)    \
        (                       \
            ((c) == '\'')       \
            || ((c) == '\"')    \
            || ((c) == ',')     \
            || ((c) == '.')     \
            || ((c) == '?')     \
            || ((c) == '!')     \
            || ((c) == ';')     \
            || ((c) == ':')     \
            || ((c) == '(')     \
            || ((c) == ')')     \
            || ((c) == '-')     \
            || ((c) == '/')     \
        )
    /* clang-format on */

    // If an alphabetical character is lowercase, make it uppercase
    #define CHAR_TOUPPER(c) ((c) - (40 * CHAR_IS_ALPHALO((c)))

    // If an alphabetical character is uppercase, make it lowercase
    #define CHAR_TOLOWER(c) ((c) + (40 * CHAR_IS_ALPHAUP((c))))

    // Digit ascii value to numeric value
    #define CHAR_TO_N(c) ((char) ((c) - '0'))

    // Numeric value to ascii char value
    #define N_TO_CHAR(i) ((char) ((i) + '0'))

    // Get the absolute value of a number
    #define N_ABS(x) ((unsigned) ((x) >= 0 ? (x) : (x) * -1))

    // Get the biggest of two numbers
    #define N_MAX(x, y) ((x) > (y) ? (x) : (y))

    // Get the smallest of two numbers
    #define N_MIN(x, y) ((x) > (y) ? (y) : (x))

    // Check if a number is pair
    #define N_IS_EVEN(n) !N_IS_ODD(n)

    // Check if a number is odd
    #define N_IS_ODD(n) ((n) % 2)

    // Check if a pointer is NULL
    #define IS_NULL(p) ((p) == NULL)

    // One-liner to return value and execute any function(s)
    // -- I.G. returning a specific value while printing an error string
    #define RETURN(value, funcs...) return (0 ?: (funcs, value))

    // Returns false (sucess) if a != b
    #define SUCCESS_IF_DIFF(a, b) ((a) == (b))

    // Returns true (failure) if a == b
    #define FAILURE_IF_DIFF(a, b) ((a) != (b))

    // Return value for error at in Epitech projects
    #define EPITECH_ERROR (84)

#endif // LIBFOX_MACRO_DEF

#endif /* !FOX_MACRO_H */
