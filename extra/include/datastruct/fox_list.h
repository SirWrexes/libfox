/*
** EPITECH PROJECT, 2019
** Libfox
** File description:
** Linked lists are useful !
*/

/*
** TODO: Implement lazy allocation
** TODO: Implement index system for lazy allocation
** TODO: Tests for delete_node
*/

#ifndef FOX_LIST_H
#define FOX_LIST_H

#include <stdbool.h>
#include "fox_define.h"

/* ------------------------------------------------------------------------ */

// Remember: These are dynamically allocated pointers.
// You MUST use the corresponding destructor when you're done with them.
typedef struct foxnode_s
{
    index_t i;              // Position in the list (DON'T EDIT IT MANUALLY)
    void *data;             // Data container
    struct foxnode_s *prev; // Previous node
    struct foxnode_s *next; // Next node
} * foxnode_t;

typedef struct
{
    count_t nodes;  // Node count in the list (DON'T EDIT THIS EITHER)
    foxnode_t head; // Top of the list
    foxnode_t tail; // Bottom of the list
} * foxlist_t;

// ...unles you use this macro that creates a list that autodestroys itself
// after use.
#define autofoxlist_t __cleanup(shredder) foxlist_t
#define paperblade    (*listdata_destructor())

/* ------------------------------------------------------------------------ */

// Create a list
// Returns true in case of error
bool list_create(foxlist_t *listptr)
__nonnull;

// Destroy a list and all of its nodes
// Destructor shall be a function pointer to the data destructor
//   used to free data stored in the nodes.
//   Can be NULL
void list_destroy(foxlist_t *listptr, void (*destructor)())
__a((nonnull(1)));

// Add a node to the list conatining data
// Returns true in case of error
bool list_addnode(foxlist_t list, void *data)
__nonnull;

// Remove a node from the list
// refptr can either be
//   ¤ A pointer to something contained in a node (will delete the first
//     node which has a matching refptr pointer, starting from list->head)
//   ¤ A pointer to a node from the list
// destructor can be a pointer to a a destructor that frees refptr
// Returns true if no match is found
bool list_deletenode(foxlist_t list, void *refptr, void (*destructor)())
__a((nonnull(1,2)));

// Create a node
// Returns true in case of error
bool node_create(foxnode_t *nodeptr, void *data)
__nonnull;

// Destroy a node
// Destructor shall be a pointer to the blablabla you know it by now
//   Can be NULL
void node_destroy(foxnode_t *nodeptr, void (*destructor)())
__a((nonnull(1)));

/* ------------------------------------------------------------------------ */

// This is just regular sorcery. Disregard it.
typedef void (*paperblade_t)(void *);
void shredder(foxlist_t *listptr) __nonnull;
paperblade_t *stackdata_destructor(void) __const;

#endif /* !FOX_LIST_H */
