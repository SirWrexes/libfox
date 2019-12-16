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
SRC := ./src/animation/ai_on_last_frame.c
SRC += ./src/animation/ai_scale_current.c
SRC += ./src/animation/ai_rect_current.c
SRC += ./src/animation/ai_rect_first.c
SRC += ./src/animation/ai_rect_next.c
SRC += ./src/animation/ai_rect_prev.c
SRC += ./src/animation/ai_type.c
# -- Sprite tools
SRC += ./src/sprite/si_update_scale.c
SRC += ./src/sprite/si_update_pos.c
SRC += ./src/sprite/si_update_pos_info.c
################################################


#
# Tests (set relative to master Makefile path)
################################################
# -- Animation tools
TST := ./tests/animation/test_ai_on_last_frame.c
TST += ./tests/animation/test_ai_scale_current.c
TST += ./tests/animation/test_ai_rect_current.c
TST += ./tests/animation/test_ai_rect_first.c
TST += ./tests/animation/test_ai_rect_next.c
TST += ./tests/animation/test_ai_rect_prev.c
TST += ./tests/animation/test_ai_type.c
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
LIBS := csfml-graphics
LIBS +=
################################################

endif
