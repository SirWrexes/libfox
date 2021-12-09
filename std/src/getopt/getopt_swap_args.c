/*
** (not) EPITECH PROJECT, 2021
** Libfox
** File description:
** The inner workings of fox_getopt()
*/

#include "fox_define.h"

#include "internal/optpriv.h"

static void swap_short_bottom(str_t *av, argspos_t *pos, int len)
{
    str_t tmp;

    for (int i = 0; i < len; i += 1) {
        tmp = av[pos->bot + i];
        av[pos->bot + i] = av[pos->top - (pos->mid - pos->bot) + i];
        av[pos->top - (pos->mid - pos->bot) + i] = tmp;
    }
}

static void swap_short_top(str_t *av, argspos_t *pos, int len)
{
    str_t tmp;

    for (int i = 0; i < len; i += 1) {
        tmp = av[pos->bot + i];
        av[pos->bot + i] = av[pos->mid + i];
        av[pos->mid + i] = tmp;
    }
}

__Anonnull void getopt_swap_args(str_t *av, godata_t d)
{
    int len;
    argspos_t pos = {
        .top = d->optind,
        .mid = d->last_nonopt,
        .bot = d->first_nonopt,
    };

    while (pos.top > pos.mid && pos.mid > pos.bot) {
        if (pos.top - pos.mid > pos.mid - pos.bot) {
            len = pos.mid - pos.bot;
            swap_short_bottom(av, &pos, len);
            pos.top -= len;
        } else {
            len = pos.top - pos.mid;
            swap_short_top(av, &pos, len);
            pos.bot += len;
        }
    }
    d->first_nonopt += (d->optind - d->last_nonopt);
    d->last_nonopt = d->optind;
}
