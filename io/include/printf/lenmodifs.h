/*
** EPITECH PROJECT, 2019
** <project_name>
** File description:
** lenmodifs.h -- No description
*/

#ifndef LENMODIFS_H
#define LENMODIFS_H

#include "fox_define.h"
#include "printf/fstruct.h"

typedef void (*lmsetter_t)(finfo_t *, str_t *);

enum { CHAR, SHORT, LONG, SIZE, LONGLONG, LONGDOUBLE, LM_CNT };
static const str_t LM_CHARS = "hlzL";
static const str_t LM_STR[LM_CNT] = {"hh", "h", "l", "z", "ll", "L"};
static const hsize_t LM_SIZE[LM_CNT] = {2, 1, 1, 1, 2, 1};

__nonnull
static inline void set_is_char(finfo_t *info, str_t *format)
{
    info->is_char = 1;
    *format += LM_SIZE[CHAR];
}

__nonnull
static inline void set_is_short(finfo_t *info, str_t *format)
{
    info->is_short = 1;
    *format += LM_SIZE[SHORT];
}

__nonnull
static inline void set_is_long(finfo_t *info, str_t *format)
{
    info->is_long = 1;
    *format += LM_SIZE[LONG];
}

__nonnull
static inline void set_is_long_long(finfo_t *info, str_t *format)
{
    info->is_long_long = 1;
    *format += LM_SIZE[LONGLONG];
}

__nonnull
static inline void set_is_long_double(finfo_t *info, str_t *format)
{
    info->is_long_double = 1;
    *format += LM_SIZE[LONGDOUBLE];
}

static const lmsetter_t LM_SET[LM_CNT] = {
    &set_is_char,
    &set_is_short,
    &set_is_long,
    &set_is_long,
    &set_is_long_long,
    &set_is_long_double
};

#endif /* !LENMODIFS_H */
