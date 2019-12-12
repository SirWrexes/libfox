##
## EPITECH PROJECT, 2019
## Libfox
## File description:
## Module name and sources
##

ifndef MKPROJECT
MKPROJECT := 1

# MODULE NAME
################################################
NAME := std
################################################


#
# Sources (set relative to master Makefile path)
################################################
DEBUGMAIN := ./src/debugmain.c
# --- TREE
SRC := ./src/fox_isprintable.c
SRC += ./src/fox_strtol.c
################################################


#
# Tests (set relative to master Makefile path)
################################################
TST := ./tests/test_fox_isprintable.c
TST += ./tests/test_fox_strtol.c
################################################


#
# External dependency soucres
################################################
DEPSRC := ../string/src/fox_strspn.c
DEPSRC += ../string/src/fox_strcspn.c
DEPSRC += ../string/src/fox_isinstr.c
################################################

endif
