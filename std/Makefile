##
## EPITECH PROJECT, 2019
## Libfox
## File description:
## Standard module
##

#
# Config
##########################################
NAME    :=  std
BIN     :=  libfox_$(NAME).a
TESTBIN :=  utests_$(NAME)
SHELL   :=  /bin/bash
ECHO     =  echo -e "$(CORANGE)[Libfox: $(NAME)]$(CRESET)"
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
SRC := ./src/fox_strtol.c
SRC +=
##########################################

#
# External source dependancy + tests
##########################################
DEPSRC := ../string/src/fox_strspn.c
DEPSRC += ../string/src/fox_strcspn.c
DEPSRC += ../string/src/fox_isinstr.c
##########################################


#
# Tests
##########################################
TST := ./tests/test_fox_strtol.c
TST +=
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
OBJ         := $(SRC:.c=.o) $(DEPSRC:.c=.o)
DEP         := $(OBJ:.o=.d) $(DEPSRC:.c=.d)
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
	@if [ -e $@ ];                                  								\
	then                                            								\
	  $(ECHO) "$(CBOLD)$(CLIGHTBLUE)Updating$(CRESET) $(CLIGHTBLUE)$@$(CRESET)";	\
	  ar ru $(BIN) $^;                              								\
	else                                            								\
	  $(ECHO) "$(CBOLD)$(CLIGHTGREEN)Creating$(CRESET) $(CLIGHTBLUE)$@$(CRESET)"; 	\
	  ar rc $(BIN) $^;                              								\
	fi

%.o: CFLAGS += -MT $@ -MMD
%.o: %.c
	@$(CC) $(CFLAGS) -c -o $@ $<
	@$(ECHO) "$(CLIGHTGREEN)$(CBOLD)Compile OK ✓$(CRESET) $@"
##########################################



.PHONY: compiledb
compiledb:
	@[[ "$(shell which compiledb)" == "" ]] || compiledb -n make -ki $(COMPILEDBTARGET)

.PHONY: all module $(NAME)
all: $(NAME)
module: $(NAME)
$(NAME): compiledb $(BIN) tests
$(BIN): $(OBJ)

$(TESTBIN): CFLAGS  += --coverage
$(TESTBIN): LDFLAGS := -lcriterion
$(TESTBIN): SRC += $(DEPSRC) $(TST) $(WRAPSRC)
$(TESTBIN): compiledb
	@$(RM) *.gc*
	@$(CC) -o $@ $(CFLAGS) $(SRC) $(LDFLAGS)

.PHONY: tests test_report
tests: test_report
test_report: $(TESTBIN)
	@$(ECHO) "$(CUNDERLN)$(CGREEN)TEST REPORT$(CRESET)"
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
