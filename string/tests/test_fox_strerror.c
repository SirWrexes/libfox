/*
** (not) EPITECH PROJECT, 2021
** Libfox
** File description:
** UT: Get a string corresponding to a given errnum
*/

#include <criterion/criterion.h>

#include "fox_string.h"
#include "foxi_errlist.h"

Test(for_strerror, all_values)
{
    for (uint i = 0; i < sizeof(fox_errlist) / sizeof(fox_errlist[0]); i+=1){
        if (!strncmp(strerror(i), "Unknown error", 13))
            continue;
        cr_expect_str_eq(fox_strerror(i), strerror(i));
    }
}
