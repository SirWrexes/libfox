/*
** EPITECH PROJECT, 2019
** Libfox
** File description:
** Binary trees are cool
*/

/*
** TODO: Implement lazy allocation
** TODO: Implement index for lazy allocation
*/

#ifndef FOX_TREE_H
#define FOX_TREE_H

#include <stdbool.h>
#include "fox_define.h"

// Most of the times, nodes will be refered to as LEAVES or BRANCHES
/// A leaf is a node that has no branching (both left/right are NULL).
/// A branch is a node tha has another branch or a leaf attached to it.

/* ------------------------------------------------------------------------ */

// Remember: These are dynamically allocated pointers.
// You MUST use the corresponding destructor when you're done with them.
typedef struct foxtree_s *foxtree_t;
typedef struct foxtnode_s *foxtnode_t;

// ...unles you use this macro that creates a tree that auto-destructs when
// leaving the scope where you created it. 😏
// You may set the auto data destructor to the function of your choice like so
//     leafcutter = &destructor_function;
// Default autodestructor is NULL
#define autofoxtree_t __Acleanup(chainsaw) foxtree_t
#define leafcutter (*treedata_destructor())

// This is just regular sorcery. Skip to the next part.
typedef void (*leafcutter_t)();
void chainsaw(foxtree_t *treeptr) __Anonnull;
leafcutter_t *treedata_destructor(void) __Aconst;

/* ------------------------------------------------------------------------ */

struct foxtree_s
{
    count_t nodes; // Node count in the tree
    foxtnode_t trunk; // root of the tree
};

struct foxtnode_s
{
    foxtree_t root;   // Wherever you are, know which tree you're in.
    void *data;    // Node data
    foxtnode_t lnext; // Left branch/leaf
    foxtnode_t rnext; // Right branch/leaf
};

/* ------------------------------------------------------------------------ */

// Create a binary tree
// Returns true in case of error
bool tree_create(foxtree_t *treeptr)
__Anonnull;

// Destroy a tree and all its nodes
// See tnode_destroy below for details about destructor
void tree_destroy(foxtree_t *treeptr, void (*destructor)())
__a((nonnull(1)));

// Create a new tree node
// data and root can be NULL
// Returns true in case of error
bool tnode_create(foxtnode_t *leafptr, void *data, foxtree_t root)
__a((nonnull(1)));

// Recursively destroy a node and it left/right leaves
// ¤ Also destroy data with a function pointed by destructor
// ¤ destructor can be NULL, in this case, data is left untouched
// ¤ Destructor will be called with the adress of pointer's data (&node->data)
//   Thus, destructor should take a pointer to the data type you want to free.
//   This way you can also set it to NULL.
// ¤ In order to avoid crashes, be sure that every data field in your tree
//   is of the same type if you want to use a destructor on it.
void tnode_destroy(foxtnode_t *node, void (*destructor)())
__a((nonnull(1)));

#endif /* !FOX_TREE_H */
