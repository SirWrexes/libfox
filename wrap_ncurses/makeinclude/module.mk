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
NAME := wrap_ncurses
################################################


#
# Sources (set relative to master Makefile path)
################################################
DEBUGMAIN := ./src/debugmain.c
SRC := ./src/fox_wrap_cbreak.c
SRC += ./src/fox_wrap_initscr.c
SRC += ./src/fox_wrap_keypad.c
SRC += ./src/fox_wrap_noecho.c
################################################

#
# Tests (set relative to master Makefile path)
################################################
SKIP_TEST_REPORT := yup
TST := ./tests/test_fox_wrap_cbreak.c
TST += ./tests/test_fox_wrap_initscr.c
TST += ./tests/test_fox_wrap_keypad.c
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


#
# Fetch every wrapper and make corresponding flag
#############################################################
WRAPPED := $(subst .c,,$(subst fox_wrap_,,$(notdir $(SRC))))
# --------------------------------------------------------- #
WRAPPREFIX := -Wl,--wrap=
WRAPFLAGS  := $(addprefix $(WRAPPREFIX),$(WRAPPED))
#############################################################

#
# Custom CFLAGS
################################################
CUSTOM_CFLAGS := $(WRAPFLAGS)
################################################

endif
