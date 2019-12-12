/*
** EPITECH PROJECT, 2019
** Libfox unit tests
** File description:
** UT: Printing an error logging message
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
    cr_expect_stdout_eq_str(sys_errlist[ENOMEM]);
}

Test(perror, empty_s, .init = cr_redirect_stdout)
{
    errno = ENOMEM;
    fox_perror("");
    cr_expect_stdout_eq_str(sys_errlist[ENOMEM]);
}

Test(perror, something, .init = cr_redirect_stdout)
{
    char buff[150] = "something: ";

    strcat(buff, sys_errlist[ENOMEM]);
    errno = ENOMEM;
    fox_perror("something");
    cr_expect_stdout_eq_str(buff);
}
