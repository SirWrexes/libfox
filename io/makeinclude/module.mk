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
NAME := io
################################################


#
# Sources (set relative to master Makefile path)
################################################
DEBUGMAIN := ./src/debugmain.c
# -- String
SRC := ./src/fox_sputchar.c
SRC += ./src/fox_sputchar_oct.c
SRC += ./src/fox_sputnbr.c
SRC += ./src/fox_sputstr.c
SRC += ./src/fox_sputstr_np.c
SRC += ./src/fox_sputunbr.c
SRC += ./src/fox_sputunbr_base.c
# -- Allocated String
SRC += ./src/fox_asputchar.c
SRC += ./src/fox_asputchar_oct.c
SRC += ./src/fox_asputnbr.c
SRC += ./src/fox_asputstr.c
SRC += ./src/fox_asputstr_np.c
SRC += ./src/fox_asputunbr.c
SRC += ./src/fox_asputunbr_base.c
# -- Descriptor
SRC += ./src/fox_dputchar.c
SRC += ./src/fox_dputchar_oct.c
SRC += ./src/fox_dputnbr.c
SRC += ./src/fox_dputstr.c
SRC += ./src/fox_dputstr_np.c
SRC += ./src/fox_dputunbr.c
SRC += ./src/fox_dputunbr_base.c
################################################


#
# Tests (set relative to master Makefile path)
################################################
# -- String
TST := ./tests/test_fox_sputstr.c
# -- Allocated string
TST += ./tests/test_fox_asputchar.c
TST += ./tests/test_fox_asputchar_oct.c
TST += ./tests/test_fox_asputnbr.c
TST += ./tests/test_fox_asputstr.c
TST += ./tests/test_fox_asputstr_np.c
TST += ./tests/test_fox_asputunbr.c
TST += ./tests/test_fox_asputunbr_base.c
# -- Descriptor
TST += ./tests/test_fox_dputchar.c
TST += ./tests/test_fox_dputchar_oct.c
TST += ./tests/test_fox_dputnbr.c
TST += ./tests/test_fox_dputstr.c
TST += ./tests/test_fox_dputstr_np.c
TST += ./tests/test_fox_dputunbr.c
TST += ./tests/test_fox_dputunbr_base.c
################################################


#
# External dependency soucres
##########################################
DEPSRC := ../string/src/fox_strcpy.c
DEPSRC += ../string/src/fox_strdup.c
DEPSRC += ../string/src/fox_strlen.c
DEPSRC += ../string/src/fox_strncpy.c
DEPSRC += ../math/src/fox_numsize.c
DEPSRC += ../math/src/fox_unumsize.c
DEPSRC += ../math/src/fox_verifbase.c
##########################################

endif
