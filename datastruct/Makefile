##
## EPITECH PROJECT, 2019
## Libfox
## File description:
## Datastruct module
##

#
# Config
##########################################
NAME    :=  datastruct
TESTBIN :=  utests_$(NAME)
SHELL   :=  /bin/bash
ECHO    :=  echo -e
MAKE    :=  make --silent -C
RM      :=  rm -f
CP      :=  cp -t
MV      :=  mv -t
GCOV    :=  gcovr
CC      :=  gcc
.DEFAULT_GOAL := all
##########################################


#
# Colours
##########################################
CRESET      :=	\033[0m

# \033[38;2;<R>;<G>;<B>m
CRED        :=	\033[38;2;255;0;0m
CGREEN      :=	\033[38;2;0;255;0m
CLIGHTGREEN :=  \033[38;2;190;255;200m
CBLUE       :=	\033[38;2;0;0;255m
CLIGHTBLUE  :=	\033[38;2;88;255;250m
CORANGE     :=	\033[38;2;255;167;4m

# Format
CBOLD       :=  \033[1m
CUNDERLN    :=  \033[4m
##########################################


#
# Sources
##########################################
SRC := ./src/tree/autodestructor.c
SRC += ./src/tree/tree_create.c
SRC += ./src/tree/tree_destroy.c
SRC += ./src/tree/treenode_create.c
SRC += ./src/tree/treenode_destroy.c
SRC += ./src/stack/stack_create.c
SRC += ./src/stack/stack_destroy.c
SRC += ./src/stack/stack_push.c
SRC += ./src/stack/stack_pop.c
##########################################


#
# Tests
##########################################
TST := ./tests/tree/test_tree_autodestroy.c
TST += ./tests/tree/test_tree_create.c
TST += ./tests/tree/test_tree_destroy.c
TST += ./tests/tree/test_treenode_create.c
TST += ./tests/tree/test_treenode_destroy.c
TST += ./tests/stack/test_stack_create.c
TST += ./tests/stack/test_stack_destroy.c
TST += ./tests/stack/test_stack_push.c
TST += ./tests/stack/test_stack_pop.c
##########################################
WRAPSRC := ./tests/wrappers/wrap_malloc.c
WRAPPED := malloc
##########################################


#
# Build settings
##########################################
INCDIRS     := ./include
CFLAGS      := -Wall -Wextra
CFLAGS      += -Werror
CFLAGS      += $(foreach dir, $(INCDIRS), -iquote $(dir))
CFLAGS      += -Wl$(foreach wrap, $(WRAPPED),,--wrap=$(wrap))
##########################################
OBJ         := $(SRC:.c=.o)
DEP         := $(OBJ:.o=.d)
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
##########################################


#
# Reciepes
##########################################
%.a:
	@if [ -e $@ ];                                  \
	then                                            \
	   $(ECHO) "Updating $(CLIGHTBLUE)$@$(CRESET)"; \
	   ar ru $@ $^;                                 \
	else                                            \
	   $(ECHO) "Creating $(CLIGHTBLUE)$@$(CRESET)"; \
	   ar rc $@ $^;                                 \
	fi

%.o: CFLAGS += -MT $@ -MMD
%.o: %.c
	@$(CC) $(CFLAGS) -c -o $@ $<
	@$(ECHO) "$(CLIGHTGREEN)Compile OK ✓$(CRESET) $@"
##########################################



.PHONY: compiledb
compiledb:
	@[[ "$(shell which compiledb)" == "" ]] || compiledb -n make -ki $(COMPILEDBTARGET)

.PHONY: all module tests $(NAME)
all: $(NAME)
module: $(NAME)
tests: test_report

$(NAME): COMPILEDBTARGET = $(NAME)
$(NAME): compiledb libfox_$(NAME).a tests
libfox_$(NAME).a: $(OBJ)

$(TESTBIN): COMPILEDBTARGET = $(TESTBIN)
$(TESTBIN): CFLAGS  += --coverage
$(TESTBIN): LDFLAGS := -lcriterion
$(TESTBIN): compiledb $(SRC) $(DEPSRC) $(TST) $(WRAPSRC)
	@$(RM) *.gc*
	@$(CC) -o $@ $(CFLAGS) $(SRC) $(DEPSRC) $(TST) $(WRAPSRC) $(LDFLAGS)
	@$(ECHO) "$(CLIGHTGREEN)Compile OK ✓$(CRESET) $@"

.PHONY: test_report
test_report: $(TESTBIN)
	@./$(TESTBIN) $(UTFLAGS)
	@$(RM) $(notdir $(DEPSRC:.c=.gc*))
	@$(GCOV) $(COVFLAGS)

.PHONY: clean
clean:
	$(RM) $(OBJ)
	$(RM) $(DEP)
	$(RM) *.gc*

.PHONY: fclean
fclean:
	$(RM) $(OBJ)
	$(RM) $(DEP)
	$(RM) *.gc*
	$(RM) libfox_$(NAME).a
	$(RM) $(TESTBIN)

.PHONY: re
re: fclean all
