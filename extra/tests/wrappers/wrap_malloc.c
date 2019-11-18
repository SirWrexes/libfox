/*
** EPITECH PROJECT, 2019
** Libfox
** File description:
** Wrap malloc to break it on demand
*/

#include <errno.h>
#include <criterion/criterion.h>
#include "tests/wrap_malloc.h"
#include "fox_define.h"

void *real_malloc(size_t size);
void *wrap_malloc(size_t size)
{
    if (malloc_counter == 0) {
        errno = ENOMEM;
        return NULL;
    }
    malloc_counter -= (malloc_counter != -1);
    return real_malloc(size);
}

__a((const))
short *__malloc_counter(void)
{
    static short n = -1;

    return &n;
}

void fix_malloc(void)
{
    malloc_counter = -1;
    errno = 0;
}

void break_malloc(void)
{
    malloc_counter = 0;
}

Test(wrap_malloc, no_break)
{
    char *s = NULL;

    fix_malloc();
    s = malloc(1);
    cr_expect_not_null(s);
    free(s);
}

Test(wrap_malloc, break_instantly, .fini = fix_malloc)
{
    char *s = NULL;

    malloc_counter = 0;
    s = malloc(1);
    cr_expect_null(s);
}

Test(wrap_malloc, break_on_4th_call, .fini = fix_malloc)
{
    char *s = NULL;

    malloc_counter = 3;
    s = malloc(1);
    cr_assert_not_null(s);
    free(s);
    s = malloc(1);
    cr_assert_not_null(s);
    free(s);
    s = malloc(1);
    cr_assert_not_null(s);
    free(s);
    s = malloc(1);
    cr_expect_eq(errno, ENOMEM);
    cr_expect_null(s);
}
