/*
** EPITECH PROJECT, 2019
** <project_name>
** File description:
** fox_stacck.h -- No description
*/

#ifndef FOX_STACK_H
#define FOX_STACK_H

#include <stdbool.h>
#include "fox_define.h"

/* ------------------------------------------------------------------------- */

// Remember: These are dynamically allocated pointers.
// You MUST use the corresponding destructor when you're done with them.
typedef struct stack_s *stack_t;
typedef struct sitem_s *sitem_t;

// ...unles you use this macro that creates a stack that autodestroys itself
// after use.
#define autostack_t __cleanup(jenga) autostack_t
void jenga(stack_t *stackptr) __nonnull;

/* ------------------------------------------------------------------------- */

struct stack_s
{
    count_t items;   // Item count in the stack
    sitem_t faketop; // Top of the stack (including empty items)
    // If you want to get the real top of the stack, use stack_top()
};

struct sitem_s
{
    index_t i;    // Placement in the stack
    void *data;   // Item data
    sitem_t prev; // Right branch/leaf
};

/* ------------------------------------------------------------------------- */

// Create a stack
// Returns true in case of error
bool stack_create(stack_t *stackptr)
__nonnull;

// Destroy a stack and all its items
// Destructor shall be a function pointer to the destructor
//   used to free data stored in the items.
//   Can be NULL
void stack_destroy(stack_t *stackptr, void (*destructor)())
__a((nonnull(1)));

// Push an item to the top of the stack.
// Returns true in case of error
bool stack_push(stack_t stack, void *data)
__nonnull;

// Pop an item from the top of stack
// Returns it pointer or NULL in case of empty stack
void *stack_pop(stack_t stack)
__nonnull;

#endif // FOX_STACK_H
