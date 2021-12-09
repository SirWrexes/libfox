/*
** (not) EPITECH PROJECT, 2021
** Libfox
** File description:
** getopt(3) copycat using the same global variables
*/

#include <getopt.h>

#include "fox_define.h"

#include "internal/optpriv.h"

int fox_getopt(int ac, str_t *av, str2c_t optstr)
{
    int r;
    struct argscv a = {.c = ac, .v = av};
    static struct getopt_data d = {0};

    d.optind = optind;
    d.opterr = opterr;
    d.c = 0;
    r = getopt_internal(&a, optstr, &d);
    optind = d.optind;
    opterr = d.opterr;
    optopt = d.optopt;
    return r;
}
