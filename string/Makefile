##
## EPITECH PROJECT, 2019
## Libfox
## File description:
## String module
##

#
# Config
##########################################
NAME    :=  string
BIN     :=  libfox_$(NAME).a
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
COMPILEDBTARGET := all tests
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
SRC := ./src/fox_isinstr.c
SRC += ./src/fox_revstr.c
SRC += ./src/fox_strcspn.c
SRC += ./src/fox_strlen.c
SRC += ./src/fox_strncpy.c
SRC += ./src/fox_strspn.c
##########################################


#
# Tests
##########################################
TST := ./tests/test_fox_isinstr.c
TST += ./tests/test_fox_revstr.c
TST += ./tests/test_fox_strcspn.c
TST += ./tests/test_fox_strlen.c
TST += ./tests/test_fox_strncpy.c
TST += ./tests/test_fox_strspn.c
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
	  $(ECHO) "Updating $(CLIGHTBLUE)$@$(CRESET)"; 	\
	  ar ru $(BIN) $^;                              \
	else                                            \
	  $(ECHO) "Creating $(CLIGHTBLUE)$@$(CRESET)"; 	\
	  ar rc $(BIN) $^;                              \
	fi

%.o: CFLAGS += -MT $@ -MMD
%.o: %.c
	@$(CC) $(CFLAGS) -c -o $@ $<
	@$(ECHO) "$(CLIGHTGREEN)Compile OK ✓$(CRESET) $@"
##########################################



.PHONY: compiledb
compiledb:
	@[[ "$(shell which compiledb)" == "" ]] || compiledb -n make -ki $(COMPILEDBTARGET)

.PHONY: all module $(NAME)
all: $(NAME)
module: $(NAME)
$(NAME): compiledb $(BIN) tests
$(BIN): $(OBJ)

.PHONY: tests
tests: test_report
$(TESTBIN): CFLAGS  += --coverage
$(TESTBIN): LDFLAGS := -lcriterion
$(TESTBIN): compiledb $(SRC) $(TST) $(WRAPSRC)
	@$(RM) *.gc*
	@$(CC) -o $@ $(CFLAGS) $(SRC) $(TST) $(WRAPSRC) $(LDFLAGS)
	@$(ECHO) "$(CLIGHTGREEN)Compile OK ✓$(CRESET) $@"

.PHONY: test_report
test_report: $(TESTBIN)
	@./$(TESTBIN) $(UTFLAGS)
	@$(RM) $(notdir $(DEPSRC:.c=.gc*))
	@$(GCOV) $(COVFLAGS)

.PHONY: clean
clean:
	@$(ECHO) "$(CRED)Deleting$(CRESET) objects"
	@$(RM) $(OBJ)
	@$(ECHO) "$(CRED)Deleting$(CRESET) dependancy files"
	@$(RM) $(DEP)
	@$(ECHO) "$(CRED)Deleting$(CRESET) coverage files"
	@$(RM) *.gc*

.PHONY: fclean
fclean:
	@$(ECHO) "$(CRED)Deleting$(CRESET) objects"
	@$(RM) $(OBJ)
	@$(ECHO) "$(CRED)Deleting$(CRESET) dependancy files"
	@$(RM) $(DEP)
	@$(ECHO) "$(CRED)Deleting$(CRESET) coverage files"
	@$(RM) *.gc*
	@$(ECHO) "$(CRED)Deleting$(CRESET) $(BIN)"
	@$(RM) $(BIN)
	@$(ECHO) "$(CRED)Deleting$(CRESET) $(TESTBIN)"
	@$(RM) $(TESTBIN)

.PHONY: re
re: fclean all
