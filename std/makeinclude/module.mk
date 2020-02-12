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
# --- Main
SRC := ./src/fox_isprintable.c
SRC += ./src/fox_strtol.c
SRC += ./src/fox_getopt.c
# --- Getopt tools
SRC += ./src/getopt/getopt_advance.c
SRC += ./src/getopt/getopt_init.c
SRC += ./src/getopt/getopt_internal.c
SRC += ./src/getopt/getopt_swap_args.c
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
DEPSRC := ../io/src/dput/fox_dputchar.c
DEPSRC += ../io/src/dput/fox_dputstr.c
DEPSRC += ../memory/src/fox_memcpy.c
DEPSRC += ../string/src/fox_isinstr.c
DEPSRC += ../string/src/fox_strchr.c
DEPSRC += ../string/src/fox_strlen.c
DEPSRC += ../string/src/fox_strcmp.c
DEPSRC += ../string/src/fox_strcspn.c
DEPSRC += ../string/src/fox_strspn.c
################################################

endif
