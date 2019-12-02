/*
** EPITECH PROJECT, 2019
** <project name> unit tests
** File description:
** test_fox_memset.c -- No description
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

#include "fox_memory.h"

Test(memset, regular_usage)
{
    char tst[12] = {[0 ... 11] = '0'};
    char ref[12] = {[0 ... 11] = '\0'};

    cr_expect_arr_eq(fox_memset(tst, '\0', sizeof(tst)), ref, sizeof(tst));
}

Test(memset, memory_larger_than_chunk)
{
    int tst[45] = {[0 ... 44] = '0'};
    int ref[45] = {[0 ... 44] = '\0'};

    cr_expect_arr_eq(fox_memset(tst, '\0', sizeof(tst)), ref, sizeof(tst));
}

Test(memset, null_dst)
{
    cr_expect_null(fox_memset(NULL, '\0', 23));
}
