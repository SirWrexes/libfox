##
## EPITECH PROJECT, 2019
## Libfox
## File description:
## String module
##

#
# Config
##########################################
NAME     :=  string
BIN      :=  libfox_$(NAME).a
TESTBIN  :=  utests_$(NAME)
DEBUGBIN :=  debug_$(NAME)
SHELL    :=  /bin/bash
MAKE     :=  make --no-print-directory -C
RM       :=  rm -f
CP       :=  cp -t
MV       :=  mv -t
GCOV     :=  gcovr
CC       :=  gcc
.DEFAULT_GOAL := all
COMPILEDBTARGET := all tests debug
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

ifndef ECHO$(NAME)
  $(call export PROGBAR) $(file >progressbar.py,$(PROGBAR))
  T := $(shell $(MAKE) . $(MAKECMDGOALS)	\
       -nrRf $(firstword $(MAKEFILE_LIST)) 	\
       ECHO$(NAME)="COUNT$(NAME)" | grep -c "COUNT$(NAME)")
  N := x
  C = $(words $N)$(eval N := x $N)
  ECHO$(NAME) = python ./progressbar.py --stepno=$C --nsteps=$T
endif

# ----------------------- MAKEFILE STARTS FROM HERE -------------------------- #


#
# Sources
##########################################
DEBUGMAIN := ./src/debugmain.c
SRC := ./src/fox_isinstr.c
SRC += ./src/fox_revstr.c
SRC += ./src/fox_strcmp.c
SRC += ./src/fox_strcpy.c
SRC += ./src/fox_strcspn.c
SRC += ./src/fox_strdup.c
SRC += ./src/fox_strlen.c
SRC += ./src/fox_strncmp.c
SRC += ./src/fox_strncpy.c
SRC += ./src/fox_strspn.c
##########################################


#
# Tests
##########################################
TST := ./tests/test_fox_isinstr.c
TST += ./tests/test_fox_revstr.c
TST += ./tests/test_fox_strcmp.c
TST += ./tests/test_fox_strcpy.c
TST += ./tests/test_fox_strcspn.c
TST += ./tests/test_fox_strdup.c
TST += ./tests/test_fox_strlen.c
TST += ./tests/test_fox_strncmp.c
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


#
# Reciepes
##########################################
%.a:
	@if [ -e $@ ];                                  								\
	then                                            								\
	  $(ECHO$(NAME)) $(CBOLD)$(CLIGHTBLUE)"Updating"$(CRESET) $(CLIGHTBLUE)$@$(CRESET);		\
	  ar ru $(BIN) $^;                              								\
	else                                            								\
	  $(ECHO$(NAME)) $(CBOLD)$(CLIGHTBLUE)"Creating"$(CRESET) $(CLIGHTBLUE)$@$(CRESET);		\
	  ar rc $(BIN) $^;                              								\
	fi

%.o: CFLAGS += -MT $@ -MMD
%.o: %.c
	@$(CC) $(CFLAGS) -c -o $@ $<
	@$(ECHO$(NAME)) $(CLIGHTGREEN)$(CBOLD)"Compile OK ✓"$(CRESET) $@
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
$(TESTBIN): CFLAGS  += $(WRAPFLAGS)
$(TESTBIN): CFLAGS  += $(CMDCFLAGS)
$(TESTBIN): LDLIBS  := -lcriterion
$(TESTBIN): SRC += $(DEPSRC) $(TST) $(WRAPSRC)
$(TESTBIN): compiledb
	@$(RM) $(COV)
	@$(CC) -o $@ $(CFLAGS) $(SRC) $(LDLIBS)

.PHONY: debug
debug: $(DEBUGBIN)
$(DEBUGBIN): CFLAGS += -ggdb3 -rdynamic
$(DEBUGBIN): $(SRC) $(DEBUGMAIN)
	$(CC) -o $@ $(CFLAGS) $(DEBUGMAIN) $(SRC)

.PHONY: tests test_report
tests: test_report
test_report: $(TESTBIN)
	@$(ECHO$(NAME)) $(CUNDERLN)$(CGREEN)$(REPORTTXT)$(CRESET)
	@./$(TESTBIN) $(UTFLAGS)
	@$(RM) $(notdir $(DEPSRC:.c=.gc*))
	-@$(GCOV) $(COVFLAGS)

.PHONY: clean
clean:
	@$(ECHO$(NAME)) $(CRED)"Delete"$(CRESET)" objects"
	@$(RM) $(OBJ)
	@$(ECHO$(NAME)) $(CRED)"Delete"$(CRESET)" dependency files"
	@$(RM) $(DEP)
	@$(ECHO$(NAME)) $(CRED)"Delete"$(CRESET)" coverage files"
	@$(RM) $(COV)

.PHONY: fclean
fclean:
	@$(ECHO$(NAME)) $(CRED)"Delete"$(CRESET)" objects"
	@$(RM) $(OBJ)
	@$(ECHO$(NAME)) $(CRED)"Delete"$(CRESET)" dependency files"
	@$(RM) $(DEP)
	@$(ECHO$(NAME)) $(CRED)"Delete"$(CRESET)" coverage files"
	@$(RM) $(COV)
	@$(ECHO$(NAME)) $(CRED)"Delete"$(CRESET) $(BIN)
	@$(RM) $(BIN)
	@$(ECHO$(NAME)) $(CRED)"Delete"$(CRESET) $(TESTBIN)
	@$(RM) $(TESTBIN)
	@$(ECHO$(NAME)) $(CRED)"Delete"$(CRESET) $(DEBUGBIN)
	@$(RM) $(DEBUGBIN)

.PHONY: re
re:
	@$(MAKE) . fclean
	@$(MAKE) . all
