##
## EPITECH PROJECT, 2019
## Libfox
## File description:
## Make configuration for modules
##


ifndef MKCONF
MKCONF := 1

#
# Config
##########################################
BIN             := libfox_$(NAME).a
TESTBIN         := utest_$(NAME)
DEBUGBIN        := debug_$(NAME)
SHELL           := /bin/bash
MAKE            := make --no-print-directory -C
RM              := rm -f
CP              := cp -t
MV              := mv -t
GCOV            := gcovr
CC              := gcc
COMPILEDB       := compile_commands.json
.DEFAULT_GOAL   := all
COMPILEDBTARGET := all tests debug
##########################################

endif
