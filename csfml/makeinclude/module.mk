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
NAME := csfml
################################################


#
# Sources (set relative to master Makefile path)
################################################
DEBUGMAIN := ./src/debugmain.c
# -- Animation tools
SRC := ./src/animinfo/ai_on_last_frame.c
SRC += ./src/animinfo/ai_rect_current.c
SRC += ./src/animinfo/ai_rect_first.c
SRC += ./src/animinfo/ai_rect_next.c
SRC += ./src/animinfo/ai_rect_prev.c
SRC += ./src/animinfo/ai_type.c
################################################


#
# Tests (set relative to master Makefile path)
################################################
# -- Animation tools
TST := ./tests/animinfo/test_ai_on_last_frame.c
TST += ./tests/animinfo/test_ai_rect_current.c
TST += ./tests/animinfo/test_ai_rect_first.c
TST += ./tests/animinfo/test_ai_rect_next.c
TST += ./tests/animinfo/test_ai_rect_prev.c
TST += ./tests/animinfo/test_ai_type.c
################################################


#
# External dependency soucres
################################################
DEPSRC :=
DEPSRC +=
################################################

endif
