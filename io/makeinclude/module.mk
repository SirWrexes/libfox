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
# -- Printf (arg parsing)
SRC := ./src/printftools/argparse/get_lenmodif.c
# -- String
SRC += ./src/sput/fox_sputchar.c
SRC += ./src/sput/fox_sputchar_oct.c
SRC += ./src/sput/fox_sputnbr.c
SRC += ./src/sput/fox_sputstr.c
SRC += ./src/sput/fox_sputstr_np.c
SRC += ./src/sput/fox_sputunbr.c
SRC += ./src/sput/fox_sputunbr_base.c
# -- Allocated String
SRC += ./src/asput/fox_asputchar.c
SRC += ./src/asput/fox_asputchar_oct.c
SRC += ./src/asput/fox_asputnbr.c
SRC += ./src/asput/fox_asputstr.c
SRC += ./src/asput/fox_asputstr_np.c
SRC += ./src/asput/fox_asputunbr.c
SRC += ./src/asput/fox_asputunbr_base.c
# -- Descriptor
SRC += ./src/dput/fox_diopadn.c
SRC += ./src/dput/fox_dputchar.c
SRC += ./src/dput/fox_dputchar_oct.c
SRC += ./src/dput/fox_dputnbr.c
SRC += ./src/dput/fox_dputstr.c
SRC += ./src/dput/fox_dputstr_np.c
SRC += ./src/dput/fox_dputunbr.c
SRC += ./src/dput/fox_dputunbr_base.c
################################################


#
# Tests (set relative to master Makefile path)
################################################
# -- Printf (arg parsing)
TST := ./tests/printftools/argparse/test_get_lenmodif.c
# -- String
TST += ./tests/sput/test_fox_sputstr.c
# -- Allocated string
TST += ./tests/asput/test_fox_asputchar.c
TST += ./tests/asput/test_fox_asputchar_oct.c
TST += ./tests/asput/test_fox_asputnbr.c
TST += ./tests/asput/test_fox_asputstr.c
TST += ./tests/asput/test_fox_asputstr_np.c
TST += ./tests/asput/test_fox_asputunbr.c
TST += ./tests/asput/test_fox_asputunbr_base.c
# -- Descriptor
TST += ./tests/dput/test_fox_diopadn.c
TST += ./tests/dput/test_fox_dputchar.c
TST += ./tests/dput/test_fox_dputchar_oct.c
TST += ./tests/dput/test_fox_dputnbr.c
TST += ./tests/dput/test_fox_dputstr.c
TST += ./tests/dput/test_fox_dputstr_np.c
TST += ./tests/dput/test_fox_dputunbr.c
TST += ./tests/dput/test_fox_dputunbr_base.c
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
