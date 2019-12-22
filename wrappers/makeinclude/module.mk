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
NAME := wrappers
################################################


#
# Sources (set relative to master Makefile path)
################################################
DEBUGMAIN := ./src/macrotest.c
SRC := ./src/fox_wrap_cbreak.c
SRC += ./src/fox_wrap_close.c
SRC += ./src/fox_wrap_initscr.c
SRC += ./src/fox_wrap_keypad.c
SRC += ./src/fox_wrap_malloc.c
SRC += ./src/fox_wrap_noecho.c
SRC += ./src/fox_wrap_open.c
SRC += ./src/fox_wrap_read.c
SRC += ./src/fox_wrap_write.c
################################################


#
# Tests (set relative to master Makefile path)
################################################
TST := ./tests/test_fox_wrap_cbreak.c
TST += ./tests/test_fox_wrap_close.c
TST += ./tests/test_fox_wrap_initscr.c
TST += ./tests/test_fox_wrap_keypad.c
TST += ./tests/test_fox_wrap_malloc.c
TST += ./tests/test_fox_wrap_noecho.c
TST += ./tests/test_fox_wrap_open.c
TST += ./tests/test_fox_wrap_read.c
TST += ./tests/test_fox_wrap_write.c
################################################


#
# External dependency soucres
################################################
DEPSRC :=
DEPSRC +=
################################################


#
# Additional libs
################################################
LIBS := ncurses
LIBS +=
################################################

endif
