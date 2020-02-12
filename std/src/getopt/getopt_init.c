/*
** EPITECH PROJECT, 2020
** Libfox
** File description:
** getopt(3) copycat
*/

#include "fox_define.h"
#include "fox_memory.h"

#include "internal/optdata.h"

__Anonnull str2c_t getopt_init(str2c_t optstr, godata_t d)
{
    d->optind = 1;
    d->first_nonopt = 1;
    d->last_nonopt = 1;
    d->nextchar = NULL;
    switch (*optstr++) {
        case '+': d->ordering = RETURN_IN_ORDER; break;
        case '-': d->ordering = REQUIRE_ORDER; break;
        default:
            d->ordering = PERMUTE;
            optstr -= 1;
            break;
    }
    d->initialized = true;
    return optstr;
}
