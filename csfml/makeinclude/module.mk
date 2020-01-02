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
SRC := ./src/entity/foxcsfml_ent_create.c
SRC +=
################################################


#
# Tests (set relative to master Makefile path)
################################################
TST := ./objects/entdefaults.c
TST += ./tests/entity/test_foxcsfml_ent_create.c
################################################


#
# External dependency soucres
##########################################
DEPSRC := ../memory/src/fox_autofree.c
DEPSRC += ../memory/src/fox_calloc.c
DEPSRC += ../memory/src/fox_memcpy.c
DEPSRC += ../memory/src/fox_memset.c
##########################################

#
# External libs
##########################################
LIBS := csfml-graphics
##########################################

#
# Additional CFLAGS
##########################################
CUSTOM_CFLAGS := -iquote .
##########################################

endif
