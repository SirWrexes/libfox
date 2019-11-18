/*
** EPITECH PROJECT, 2019
** Libfox
** File description:
** va_list helper for fox_printf UT
*/

#ifndef UT_PRINTERS_H
#define UT_PRINTERS_H

#include <stdarg.h>
#include "fox_define.h"

static inline void setup_va_list(va_list *ap, ...)
{
    va_start(*ap, ap);
}

#endif /* !UT_PRINTERS_H */
