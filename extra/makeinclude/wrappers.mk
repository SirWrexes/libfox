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

# Open
#############################################################
WRAPSRC += ../extra/tests/wrappers/wrap_open.c
WRAPPED += open
#############################################################

# Read
#############################################################
WRAPSRC += ../extra/tests/wrappers/wrap_read.c
WRAPPED += read
#############################################################

# Wrap flags for compilation
#############################################################
WRAPFLAGS   := -Wl$(foreach wrap, $(WRAPPED),,--wrap=$(wrap))
#############################################################

endif
