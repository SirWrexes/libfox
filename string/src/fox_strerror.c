/*
** (not) EPITECH PROJECT, 2021
** Libfox
** File description:
** Get a string corresponding to given errno value
*/

#include "fox_define.h"
#include "fox_internal/foxi_errlist.h"

__AalwaysILext str2c_t fox_strerror(int errnum)
{
    return fox_errlist[errnum];
}
