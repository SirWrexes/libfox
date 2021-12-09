/*
** (not) EPITECH PROJECT, 2021
** Libfox
** File description:
** Advance to the next argv element
*/

#include "fox_define.h"
#include "fox_string.h"

#include "internal/optpriv.h"

__Anonnull static void advance_permute(godata_t d, argscv_t a)
{
    if (d->first_nonopt != d->last_nonopt && d->last_nonopt != d->optind)
        getopt_swap_args(a->v, d);
    else if (d->last_nonopt != d->optind)
        d->first_nonopt = d->optind;
    while (d->optind < a->c && NONOPT(a->v[d->optind]))
        d->optind += 1;
    d->last_nonopt = d->optind;
}

__Anonnull static void double_dash_stop(godata_t d, argscv_t a)
{
    d->optind += 1;
    if (d->first_nonopt != d->last_nonopt && d->last_nonopt != d->optind)
        getopt_swap_args(a->v, d);
    else if (d->first_nonopt == d->last_nonopt)
        d->first_nonopt = d->optind;
    d->last_nonopt = a->c;
    d->optind = a->c;
}

__Anonnull int getopt_advance(argscv_t a, godata_t d)
{
    if (d->ordering == PERMUTE)
        advance_permute(d, a);
    if (d->optind != a->c && !fox_strcmp(a->v[d->optind], "--"))
        double_dash_stop(d, a);
    if (d->optind == a->c) {
        if (d->first_nonopt != d->last_nonopt)
            d->optind = d->first_nonopt;
        return -1;
    }
    if (NONOPT(a->v[d->optind])) {
        if (d->ordering == REQUIRE_ORDER)
            return -1;
        d->optarg = a->v[d->optind++];
        return 1;
    }
    d->nextchar = a->v[d->optind] + 1;
    return 0;
}
