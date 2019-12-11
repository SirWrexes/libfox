/*
** EPITECH PROJECT, 2019
** Libfox unit tests
** File description:
** test_fox_autofree.c -- No description
*/

#include <signal.h>

#include <criterion/criterion.h>
#include <criterion/redirect.h>

#include "fox_memory.h"

static void *proc_autofree(size_t n)
{
    __smart void *ptr = malloc(n);

    return ptr;
}

Test(autofree, regular_usage, .signal = SIGABRT, .init = cr_redirect_stderr)
{
    char *test = proc_autofree(42);

    free(test);
}

Test(autofree, manual_call)
{
    char *test = malloc(23);

    __fox_autofree(&test);
    cr_expect_null(test);
}

Test(autofree, manual_call_null_ptr)
{
    char *test = NULL;

    __fox_autofree(&test);
    cr_assert(true);
}
