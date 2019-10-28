##
## EPITECH PROJECT, 2019
## Libfox
## File description:
## Datastruct module
##

#
# Config
##########################################
NAME    =  datastruct
BIN     :=  libfox_$(NAME).a
TESTBIN :=  utests_$(NAME)
SHELL   :=  /bin/bash
MAKE    :=  make --no-print-directory -C
RM      :=  rm -rf
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
CRESET      :=	$$'\033[0m'

# \033[38;2;<R>;<G>;<B>m
CRED        :=	$$'\033[38;2;255;0;0m'
CGREEN      :=	$$'\033[1;32;40m'
CLIGHTGREEN :=  $$'\033[38;2;190;255;200m'
CBLUE       :=	$$'\033[38;2;0;0;255m'
CLIGHTBLUE  :=	$$'\033[38;2;88;255;250m'
CORANGE     :=	$$'\033[38;2;255;167;4m'

# Format
CBOLD       :=  $$'\033[1m'
CUNDERLN    :=  $$'\033[4m'
##########################################


# ----------------------- PYTHON PROGRESS BAR SCRIPT ------------------------ #

define PROGBAR
import argparse
import math
import sys

def main():
  parser = argparse.ArgumentParser(description=__doc__)
  parser.add_argument("--stepno", type=int, required=True)
  parser.add_argument("--nsteps", type=int, required=True)
  parser.add_argument("remainder", nargs=argparse.REMAINDER)
  args = parser.parse_args()

  nchars = int(math.log(args.nsteps, 10)) + 1
  fmt_str = "\033[38;2;255;167;4m[Libfox: $(NAME) | {:Xd}/{:Xd} | {:6.2f}%]\033[0m".replace("X", str(nchars))
  progress = 100 * args.stepno / args.nsteps
  sys.stdout.write(fmt_str.format(args.stepno, args.nsteps, progress))
  for item in args.remainder:
    sys.stdout.write(" ")
    sys.stdout.write(item)
  sys.stdout.write("\n")

if __name__ == "__main__":
  main()
endef

ifndef ECHO
  $(call export PROGBAR) $(file >progressbar.py,$(PROGBAR))
  T := $(shell $(MAKE) . $(MAKECMDGOALS)	\
       -nrRf $(firstword $(MAKEFILE_LIST)) 	\
       ECHO="COUNT$(NAME)" | grep -c "COUNT$(NAME)")
  N := x
  C = $(words $N)$(eval N := x $N)
  ECHO = python ./progressbar.py --stepno=$C --nsteps=$T
endif

# ----------------------- MAKEFILE STARTS FROM HERE -------------------------- #


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
	  $(ECHO) $(CBOLD)$(CLIGHTBLUE)Updating$(CRESET) $(CLIGHTBLUE)$@$(CRESET);	\
	  ar ru $(BIN) $^;                              								\
	else                                            								\
	  $(ECHO) $(CBOLD)$(CLIGHTBLUE)Creating$(CRESET) $(CLIGHTBLUE)$@$(CRESET);	\
	  ar rc $(BIN) $^;                              								\
	fi

%.o: CFLAGS += -MT $@ -MMD
%.o: %.c
	@$(CC) $(CFLAGS) -c -o $@ $<
	@$(ECHO) $(CLIGHTGREEN)$(CBOLD)Compile OK ✓$(CRESET) $@
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
	@$(ECHO) $(CUNDERLN)$(CGREEN)TEST REPORT$(CRESET)
	@./$(TESTBIN) $(UTFLAGS)
	@$(RM) $(notdir $(DEPSRC:.c=.gc*))
	@$(GCOV) $(COVFLAGS)

.PHONY: clean
clean:
	@$(ECHO) $(CRED)Delete$(CRESET) objects
	@$(RM) $(OBJ)
	@$(ECHO) $(CRED)Delete$(CRESET) dependancy files
	@$(RM) $(DEP)
	@$(ECHO) $(CRED)Delete$(CRESET) coverage files
	@$(RM) *.gc*

.PHONY: fclean
fclean:
	@$(ECHO) $(CRED)Delete$(CRESET) objects
	@$(RM) $(OBJ)
	@$(ECHO) $(CRED)Delete$(CRESET) dependancy files
	@$(RM) $(DEP)
	@$(ECHO) $(CRED)Delete$(CRESET) coverage files
	@$(RM) *.gc*
	@$(ECHO) $(CRED)Delete$(CRESET) $(BIN)
	@$(RM) $(BIN)
	@$(ECHO) $(CRED)Delete$(CRESET) $(TESTBIN)
	@$(RM) $(TESTBIN)

.PHONY: re
re: fclean all
