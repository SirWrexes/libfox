/*
** (not) EPITECH PROJECT, 2021
** Libfox unit tests
** File description:
** UT: Print an error message corresponding to given errnum
*/

#include <errno.h>
#include <string.h>
#include <criterion/criterion.h>
#include <criterion/redirect.h>

#include "fox_io.h"

Test(perror, null_s, .init = cr_redirect_stdout)
{
    errno = ENOMEM;
    fox_perror(NULL);
    cr_expect_stdout_eq_str(strerror(ENOMEM));
}

Test(perror, empty_s, .init = cr_redirect_stdout)
{
    errno = ENOMEM;
    fox_perror("");
    cr_expect_stdout_eq_str(strerror(ENOMEM));
}

Test(perror, something, .init = cr_redirect_stdout)
{
    char buff[150] = "something: ";

    strcat(buff, strerror(ENOMEM));
    errno = ENOMEM;
    fox_perror("something");
    cr_expect_stdout_eq_str(buff);
}
