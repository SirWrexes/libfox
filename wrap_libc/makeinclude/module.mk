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
NAME := wrap_libc
################################################


#
# Sources (set relative to master Makefile path)
################################################
DEBUGMAIN := ./src/debugmain.c
SRC := ./src/fox_wrap_close.c
SRC += ./src/fox_wrap_malloc.c
SRC += ./src/fox_wrap_open.c
SRC += ./src/fox_wrap_read.c
SRC += ./src/fox_wrap_write.c
################################################


#
# Tests (set relative to master Makefile path)
################################################
TST := ./tests/test_fox_wrap_close.c
TST += ./tests/test_fox_wrap_malloc.c
################################################


#
# External dependency soucres
################################################
DEPSRC := ../memory/src/fox_autofree.c
DEPSRC +=
################################################


#
# Additional libs
################################################
LIBS :=
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
