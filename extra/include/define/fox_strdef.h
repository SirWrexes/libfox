/*
** EPITECH PROJECT, 2019
** Libfox
** File description:
** Useful strings, mostly used for str module functions
*/

#ifndef FOX_STRDEF_H
#define FOX_STRDEF_H

#define STR_WHITESPACE " \t\n"

#define STR_ALPHAUP  "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
#define STR_ALPHALO  "abcdefghijklmnopqrstuvwxyz"
#define STR_ALPHABET STR_ALPHALO STR_ALPHAUP

#define STR_NUMERIC  "0123456789"
#define STR_OPERATOR "+-*/%"

#define STR_ALPHANUM STR_ALPHABET STR_NUMERIC
#define STR_EXPR     STR_OPERATOR STR_NUMERIC STR_WHIESTAPCE

#endif /* !FOX_STRDEF_H */
