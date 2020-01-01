/*
** EPITECH PROJECT, 2019
** csfml unit tests
** File description:
** test_foxcsfml_ent_create.c -- No description
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

#include "fox_csfml.h"

#include "objects/objects.h"

static const struct constructor_data *EXMPLDEFS =
    &FOXCSFML_ENTITY_DEFAULTS[ENTID_EXAMPLE];

Test(ent_create, regular_usage)
{
    __smart entity_t e = NULL;

    cr_assert_not(foxcsfml_ent_create(ENTID_EXAMPLE, &e));
    cr_expect_eq(e->hp, EXMPLDEFS->entinfo->hp);
    cr_expect_eq(e->state, EXMPLDEFS->entinfo->state);
    cr_expect_eq(e->tick.microseconds, EXMPLDEFS->entinfo->tick.microseconds);
    cr_expect_arr_eq(e->on_event, EXMPLDEFS->entinfo->on_event,
        sizeof(entevt_t[sfEvtCount]));
    cr_expect_not(
        (ulong_t) e->prev + (ulong_t) e->next + e->elapsed.microseconds);
}
