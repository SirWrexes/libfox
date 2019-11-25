##
## EPITECH PROJECT, 2019
## Libfox
## File description:
## Wrapper sources
##


ifndef MKWRAPPERS
MKWRAPPERS := 1

# Malloc
#############################################################
WRAPSRC := ../extra/tests/wrappers/wrap_malloc.c
WRAPPED := malloc
#############################################################

# Wrap flags for compilation
#############################################################
WRAPFLAGS   := -Wl$(foreach wrap, $(WRAPPED),,--wrap=$(wrap))
#############################################################

endif
