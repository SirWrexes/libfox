/*
** EPITECH PROJECT, 2019
** Libfox
** File description:
** UT: copying a whole bunch of memory
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "tests/memcpy_dummy.h"

#include "fox_memory.h"

Test(memcpy, regular_usage)
{
    char dum_tststr[23] = {[0 ... 22] = '\0'};
    memcpy_dummy_t dum_tst = {
        .dummy_size = 0,
        .dummy_str = NULL,
        .dummy_arr = {[0 ... 5] = 0},
        .dummy_pad = {[0 ... 3] = '\0'}
    };

    cr_log_warn("Size of ulong_t: %zu", sizeof(unsigned long));
    cr_log_warn("Size of dummy  : %zu", sizeof(memcpy_dummy_t));
    cr_expect_eq(fox_memcpy(&dum_tst, &DUM_REF, sizeof(dum_tst)), &dum_tst);
    cr_expect_eq(dum_tst.dummy_size, DUM_REF.dummy_size);
    cr_expect_eq(dum_tst.dummy_str, DUM_REF.dummy_str);
    cr_expect_arr_eq(
        dum_tst.dummy_arr, DUM_REF.dummy_arr, sizeof(DUM_REF.dummy_arr));
    cr_expect_arr_eq(
        dum_tst.dummy_pad, DUM_REF.dummy_pad, sizeof(DUM_REF.dummy_pad));
    cr_expect_str_eq(
        fox_memcpy(dum_tststr, DUM_REFSTR, 23 * sizeof(char)), DUM_REFSTR);
}
