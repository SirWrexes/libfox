/*
** EPITECH PROJECT, 2019
** Libfox
** File description:
** UT: Wrap malloc
*/

#include <errno.h>
#include <fcntl.h>
#include <unistd.h>

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "tests/wrappers/wrap_malloc.h"

#include "fox_memory.h"

Test(wrap_malloc, regular_usage, .init = break_malloc)
{
    __smart void *tst = malloc(1);
    int err = errno;

    cr_expect_null(tst);
    cr_expect_eq(err, ENOMEM);
    fix_malloc();
    tst = malloc(1);
    err = errno;
    cr_expect_not_null(tst);
    cr_expect_neq(err, ENOMEM);
}
