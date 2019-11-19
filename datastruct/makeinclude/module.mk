##
## EPITECH PROJECT, 2019
## Libfox
## File description:
## Module name and sources
##

ifndef MKPROJECT
MKPROJECT := 1

# MODULE NAME
##########################################
NAME := datastruct
##########################################


#
# Sources
##########################################
DEBUGMAIN := ./src/debugmain.c
# --- TREE
SRC := ./src/tree/tree_autodestructor.c
SRC += ./src/tree/tree_create.c
SRC += ./src/tree/tree_destroy.c
SRC += ./src/tree/tnode_create.c
# --- STACK
SRC += ./src/tree/tnode_destroy.c
SRC += ./src/stack/stack_autodestructor.c
SRC += ./src/stack/stack_create.c
SRC += ./src/stack/stack_destroy.c
SRC += ./src/stack/stack_push.c
SRC += ./src/stack/stack_pop.c
# --- LIST
SRC += ./src/list/list_addnode.c
SRC += ./src/list/list_autodestructor.c
SRC += ./src/list/list_create.c
SRC += ./src/list/list_destroy.c
SRC += ./src/list/node_create.c
SRC += ./src/list/node_destroy.c
##########################################


#
# Tests
##########################################
# --- TREE
TST := ./tests/tree/test_tree_autodestructor.c
TST += ./tests/tree/test_tree_create.c
TST += ./tests/tree/test_tree_destroy.c
TST += ./tests/tree/test_tnode_create.c
TST += ./tests/tree/test_tnode_destroy.c
# --- STACK
TST += ./tests/stack/test_stack_autodestructor.c
TST += ./tests/stack/test_stack_create.c
TST += ./tests/stack/test_stack_destroy.c
TST += ./tests/stack/test_stack_push.c
TST += ./tests/stack/test_stack_pop.c
# --- LIST
TST += ./tests/list/test_list_addnode.c
TST += ./tests/list/test_list_autodestructor.c
TST += ./tests/list/test_list_create.c
TST += ./tests/list/test_list_destroy.c
TST += ./tests/list/test_node_create.c
TST += ./tests/list/test_node_destroy.c
##########################################

endif
