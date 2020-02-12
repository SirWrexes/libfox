/*
** EPITECH PROJECT, 2020
** Libfox
** File description:
** optdata.h -- No description
*/

#ifndef OPTDATA_H
#define OPTDATA_H

#include "fox_define.h"

typedef struct getopt_data {
    int optind;
    int opterr;
    int optopt;
    int c;
    char *optarg;

    int initialized;
    char *nextchar;

    enum {
        REQUIRE_ORDER,
        PERMUTE,
        RETURN_IN_ORDER,
    } ordering;

    int first_nonopt;
    int last_nonopt;
} * godata_t;

str2c_t getopt_init(str2c_t optstr, godata_t d);

#endif /* !OPTDATA_H */
