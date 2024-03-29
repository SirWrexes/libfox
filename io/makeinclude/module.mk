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
SRC := ./src/fox_dprintf.c
# -- Printf (arg parsing)
SRC += ./src/printftools/argparse/parse_arg.c
SRC += ./src/printftools/argparse/get_flags.c
SRC += ./src/printftools/argparse/get_lenmodif.c
SRC += ./src/printftools/argparse/get_precision.c
SRC += ./src/printftools/argparse/get_width.c
# -- Printf (arg conversion)
# SRC +=  ./src/printftools/argconv/
# -- Printf (printing)
SRC += ./src/printftools/printers/print_character.c
SRC += ./src/printftools/printers/print_integer.c
SRC += ./src/printftools/printers/print_percent.c
SRC += ./src/printftools/printers/print_pointer.c
SRC += ./src/printftools/printers/print_strerror.c
SRC += ./src/printftools/printers/print_string.c
SRC += ./src/printftools/printers/print_unsigned.c
SRC += ./src/printftools/printers/print_unsigned_base.c
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
# -- file Descriptor
SRC += ./src/dput/fox_diopadn.c
SRC += ./src/dput/fox_dperror.c
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
TST := ./tests/printftools/argparse/test_get_flags.c
TST += ./tests/printftools/argparse/test_get_lenmodif.c
TST += ./tests/printftools/argparse/test_get_precision.c
TST += ./tests/printftools/argparse/test_get_width.c
# -- Printf (arg parsing)
TST += ./tests/printftools/printers/test_print_character.c
TST += ./tests/printftools/printers/test_print_integer.c
TST += ./tests/printftools/printers/test_print_pointer.c
TST += ./tests/printftools/printers/test_print_string.c
TST += ./tests/printftools/printers/test_print_unsigned.c
TST += ./tests/printftools/printers/test_print_unsigned_base.c
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
TST += ./tests/dput/test_fox_dperror.c
TST += ./tests/dput/test_fox_dprintf.c
TST += ./tests/dput/test_fox_dputchar.c
TST += ./tests/dput/test_fox_dputchar_oct.c
TST += ./tests/dput/test_fox_dputnbr.c
TST += ./tests/dput/test_fox_dputstr.c
TST += ./tests/dput/test_fox_dputstr_np.c
TST += ./tests/dput/test_fox_dputunbr.c
TST += ./tests/dput/test_fox_dputunbr_base.c
# -------------------------------------------- #
## Wrappers
TST += ../wrap_libc/src/fox_wrap_malloc.c
WRAPFLAGS := -Wl,--wrap=malloc
# -------------------------------------------- #
## Custom compile flags
CUSTOM_UTCFLAGS := -Wno-format
################################################


#
# External dependency soucres
##########################################
DEPSRC := ../math/src/fox_numsize.c
DEPSRC += ../math/src/fox_unumsize.c
DEPSRC += ../math/src/fox_verifbase.c
DEPSRC += ../memory/src/fox_memcpy.c
DEPSRC += ../memory/src/fox_memset.c
DEPSRC += ../std/src/fox_isprintable.c
DEPSRC += ../std/src/fox_strtol.c
DEPSRC += ../string/src/fox_isinstr.c
DEPSRC += ../string/src/fox_strcpy.c
DEPSRC += ../string/src/fox_strcspn.c
DEPSRC += ../string/src/fox_strdup.c
DEPSRC += ../string/src/fox_strerror.c
DEPSRC += ../string/src/fox_strlen.c
DEPSRC += ../string/src/fox_strncpy.c
DEPSRC += ../string/src/fox_strnlen.c
DEPSRC += ../string/src/fox_strspn.c
##########################################

endif
