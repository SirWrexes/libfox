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

# Close
#############################################################
WRAPSRC += ../extra/tests/wrappers/wrap_close.c
WRAPPED += close
#############################################################

# Read
#############################################################
WRAPSRC += ../extra/tests/wrappers/wrap_read.c
WRAPPED += read
#############################################################

# Write
#############################################################
WRAPSRC += ../extra/tests/wrappers/wrap_write.c
WRAPPED += write
#############################################################

# Wrap flags for compilation
#############################################################
WRAPPREFIX := -Wl,--wrap=
WRAPFLAGS  := $(addprefix $(WRAPPREFIX),$(WRAPPED))
#############################################################

endif
