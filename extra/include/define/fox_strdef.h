/*
** EPITECH PROJECT, 2019
** Libfox
** File description:
** Useful strings, mostly used for str module functions
*/

#ifndef FOX_STRDEF_H
#define FOX_STRDEF_H

#define STR_SPACE   " "
#define STR_TAB     "\t"
#define STR_NEWLINE "\n"
#define STR_WHITESPACE STR_TAB STR_SPACE STR_NEWLINE

#define STR_ALPHAUP  "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
#define STR_ALPHALO  "abcdefghijklmnopqrstuvwxyz"
#define STR_ALPHABET STR_ALPHALO STR_ALPHAUP

#define STR_NUMERICS "0123456789"
#define STR_OPERATOR "+-*/%"
#define STR_LOGICOPS "!|&^"

#define STR_ALPHANUM STR_ALPHABET STR_NUMERICS
#define STR_MATHEXPR STR_OPERATOR STR_ALPHANUM STR_WHIESTAPCE
#define STR_LOGIEXPR STR_LOGICOPS STR_MATHEXPR

#endif /* !FOX_STRDEF_H */
