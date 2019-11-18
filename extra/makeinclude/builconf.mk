##
## EPITECH PROJECT, 2019
## Libfox
## File description:
## Build and test config
##

ifndef MKBUILDCONF
MKBUILDCONF := 1

#
# Build settings
##########################################
INCDIRS     := ./include ../extra/include
CFLAGS      := -std=gnu99
CFLAGS      += -Wall -Wextra
CFLAGS      += -Werror
CFLAGS      += $(foreach dir, $(INCDIRS), -iquote $(dir))
##########################################
OBJ         := $(SRC:.c=.o) $(DEPSRC:.c=.o)
DEP         := $(OBJ:.o=.d) $(DEPSRC:.c=.d)
COV         := $(notdir $(OBJ:.o=.gc*)) $(notdir $(TST:.c=.gc*)) $(notdir $(WRAPSRC:.c=.gc*))
-include $(DEP)
.PRECIOUS   := $(DEP)
##########################################


#
# Test config
##########################################
UTFLAGS := --always-succeed --timeout 5
COVFLAGS := -s --exclude-unreachable-branches
COVFLAGS += $(foreach s, $(DEPSRC), -e $(notdir $(s)))
COVFLAGS += --exclude='.*test_.*'
COVFLAGS += --exclude='.*wrap_.*'
REPORTTXT := "TEST REPORT"
ifdef SHOW_BRANCHES
    COVFLAGS += -b
    REPORTTXT += "(branches)"
endif
##########################################

endif
