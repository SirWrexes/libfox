/*
** EPITECH PROJECT, 2019
** Libfox
** File description:
** Pile up things it's fun
*/

/*
**TODO: Implement an item index system for lazy allocation
*/

#ifndef FOX_STACK_H
#define FOX_STACK_H

#include <stdbool.h>
#include "fox_define.h"

/* ------------------------------------------------------------------------ */

// Remember: These are dynamically allocated pointers.
// You MUST use the corresponding destructor when you're done with them.
typedef struct foxstack_s *foxstack_t;
typedef struct foxsitem_s *foxsitem_t;

// ...unles you use this macro that creates a stack that autodestroys itself
// after use.
// You can set a destructor for the data stored in stack items like so
//      pilebreaker = &destructor_function;
// Default autodestructor is NULL
#define autofoxstack_t __Acleanup(jenga) foxstack_t
#define pilebreaker (*stackdata_destructor())

// This is just regular sorcery. Skip to the next part.
typedef void (*pilebreaker_t)();
void jenga(foxstack_t *stackptr) __Anonnull;
pilebreaker_t *stackdata_destructor(void) __Aconst;

/* ------------------------------------------------------------------------ */

struct foxstack_s
{
    count_t items;      // Item count in the stack
    foxsitem_t faketop; // Top of the stack (including empty items)
    foxsitem_t realtop; // Actual top of the stack
};

struct foxsitem_s
{
    index_t i;       // Placement in the stack
    void *data;      // Item data
    foxsitem_t prev; // Right branch/leaf
};

/* ------------------------------------------------------------------------ */

// Create a stack
// Returns true in case of error
bool stack_create(foxstack_t *stackptr)
__Anonnull;

// Destroy a stack and all its items
// Destructor shall be a function pointer to the destructor
//   used to free data stored in the items.
//   Can be NULL
void stack_destroy(foxstack_t *stackptr, void (*destructor)())
__a((nonnull(1)));

// Push an item to the top of the stack.
// Returns true in case of error
bool stack_push(foxstack_t stack, void *data)
__Anonnull;

// Pop an item from the top of stack
// Returns it pointer or NULL in case of empty stack
void *stack_pop(foxstack_t stack)
__Anonnull;

#endif // FOX_STACK_H
