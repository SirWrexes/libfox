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
NAME := memory
################################################


#
# Sources (set relative to master Makefile path)
################################################
DEBUGMAIN := ./src/debugmain.c
SRC := ./src/fox_autofree.c
SRC += ./src/fox_memcpy.c
SRC += ./src/fox_memset.c
SRC += ./src/fox_calloc.c
################################################


#
# Tests (set relative to master Makefile path)
################################################
TST += ./tests/test_fox_autofree.c
TST += ./tests/test_fox_memcpy.c
TST += ./tests/test_fox_memset.c
TST += ./tests/test_fox_calloc.c
################################################


#
# External dependency soucres
##########################################
DEPSRC :=
DEPSRC +=
##########################################

endif
