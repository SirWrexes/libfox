/*
** EPITECH PROJECT, 2019
** Libfox unit tests
** File description:
** test_fox_autoclose.c -- No description
*/

#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

#include <criterion/criterion.h>
#include <criterion/redirect.h>

#include "fox_memory.h"

static int proc_autoclose(void)
{
    __close int fd = open("/dev/random", O_RDONLY);

    return fd;
}

Test(autoclose, regular_usage, .init = cr_redirect_stderr)
{
    int test = proc_autoclose();

    cr_expect_eq(close(test), -1);
    test = errno;
    cr_expect_eq(test, EBADF);
}

Test(autoclose, manual_call)
{
    int test = open("/dev/null", O_RDONLY);

    fox_autoclose(&test);
    cr_expect_eq(test, -1);
}

Test(autoclose, manual_call_bad_fd)
{
    int test = -1;

    fox_autoclose(&test);
    cr_assert(true);
}
