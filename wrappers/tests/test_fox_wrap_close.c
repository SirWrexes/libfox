/*
** EPITECH PROJECT, 2019
** Libfox
** File description:
** UT: Wrap close
*/

#include <unistd.h>
#include <fcntl.h>

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "tests/wrappers/wrap_close.h"

Test(wrap_close, regular_usage, .init = break_close)
{
    int fd = open("wrap_close.tmp", O_CREAT);

    cr_expect_eq(close(fd), -1);
    fix_close();
    cr_expect_neq(close(fd), -1);
}
