/*
** (not) EPITECH PROJECT, 2021
** Libfox
** File description:
** The inner working of fox_getopt()
*/

#include <getopt.h>
#include <stdbool.h>

#include "fox_define.h"
#include "fox_string.h"

#include "internal/invalid.h"
#include "internal/optpriv.h"

__Anonnull static char handle_argopt(
    argscv_t a, godata_t d, str2c_t optstr, str2c_t tmp)
{
    if (tmp[2] == ':') {
        if (*d->nextchar != '\0') {
            d->optarg = d->nextchar;
            d->optind += 1;
        } else
            d->optarg = NULL;
        d->nextchar = NULL;
        return 0;
    }
    if (*d->nextchar != '\0') {
        d->optarg = d->nextchar;
        d->optind += 1;
    } else if (d->optind == a->c) {
        if (d->opterr)
            opt_requires_arg(a->v[0], d->c);
        return (optstr[0] == ':') ? ':' : '?';
    } else
        d->optarg = a->v[d->optind++];
    d->nextchar = NULL;
    return 0;
}

__Anonnull static bool startup(argscv_t a, str2c_t *optstr, godata_t d)
{
    if (d->initialized == false)
        *optstr = getopt_init(*optstr, d);
    else if (**optstr == '-' || **optstr == '+')
        *optstr += 1;
    if (**optstr == ':')
        d->opterr = 0;
    if (d->nextchar == NULL || *d->nextchar == '\0')
        d->c = getopt_advance(a, d);
    return (d->c != 0);
}

__Anonnull int getopt_internal(argscv_t a, str2c_t optstr, godata_t d)
{
    str2c_t tmp;

    if (startup(a, &optstr, d))
        return d->c;
    d->c = *d->nextchar++;
    tmp = fox_strchr(optstr, d->c);
    d->optind += (*d->nextchar == '\0');
    if (tmp == NULL || d->c == ':' || d->c == ';') {
        if (d->opterr)
            invalid_opt(a->v[0], d->c);
        d->optopt = d->c;
        return '?';
    }
    if (tmp[1] == ':')
        return handle_argopt(a, d, optstr, tmp) ?: d->c;
    return d->c;
}
