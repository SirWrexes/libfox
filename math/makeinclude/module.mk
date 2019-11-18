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
NAME := math
################################################


#
# Sources (set relative to master Makefile path)
################################################
DEBUGMAIN := ./src/debugmain.c
# --- TREE
SRC := ./src/fox_numsize.c
SRC += ./src/fox_unumsize.c
SRC += ./src/fox_verifbase.c
################################################


#
# Tests (set relative to master Makefile path)
################################################
TST := tests/test_fox_numsize.c
TST += tests/test_fox_unumsize.c
TST += tests/test_fox_verifbase.c
################################################


#
# External dependency soucres
##########################################
DEPSRC :=
DEPSRC +=
##########################################

endif
