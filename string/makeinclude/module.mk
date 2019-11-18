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
NAME := string
################################################

#
# Sources (set relative to master Makefile path)
################################################
DEBUGMAIN := ./src/debugmain.c
SRC := ./src/fox_isinstr.c
SRC += ./src/fox_revstr.c
SRC += ./src/fox_strcmp.c
SRC += ./src/fox_strcpy.c
SRC += ./src/fox_strcspn.c
SRC += ./src/fox_strdup.c
SRC += ./src/fox_strlen.c
SRC += ./src/fox_strncmp.c
SRC += ./src/fox_strncpy.c
SRC += ./src/fox_strspn.c
################################################


#
# Tests (set relative to master Makefile path)
################################################
TST := ./tests/test_fox_isinstr.c
TST += ./tests/test_fox_revstr.c
TST += ./tests/test_fox_strcmp.c
TST += ./tests/test_fox_strcpy.c
TST += ./tests/test_fox_strcspn.c
TST += ./tests/test_fox_strdup.c
TST += ./tests/test_fox_strlen.c
TST += ./tests/test_fox_strncmp.c
TST += ./tests/test_fox_strncpy.c
TST += ./tests/test_fox_strspn.c
################################################


#
# External dependency soucres
################################################
DEPSRC :=
DEPSRC +=
################################################

endif
