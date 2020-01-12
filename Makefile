##
## EPITECH PROJECT, 2019
## EvalExpr
## File description:
## Renaud sait pas faire un Makefile
##

#
# Config
###################################################################
NAME    := libfox
SHELL   := $(shell which bash) # Yeah it looks dumb but you can never be too sure.
MAKE    := $(shell which make) --no-print-directory -C
RM      := $(shell which rm) -f
CP      := $(shell which cp) -t
MV      := $(shell which mv) -t
ECHO    := $(shell which echo)
define echo
 	$(ECHO)
endef
.DEFAULT_GOAL := all
###################################################################

#
# Module directories
###################################################################
MODULES += datastruct
MODULES += io
MODULES += math
MODULES += memory
MODULES += std
MODULES += string
MODULES += wrap_libc
MODULES += wrap_ncurses
###################################################################

#
# Modules
###################################################################
# This genertes a receipe for each module directory.
# Just use `make MODULEDIR` were MODULEDIR is a module directory
# name and you're good to go !
# --------------------------------------------------------------- #
.PHONY: $(MODULES)
$(MODULES):
	@$(MAKE) $@ $(RULE)
	@echo
###################################################################

#
# Wrappers
###################################################################
# If you want to build every wrapper at once, use this receipe
# --------------------------------------------------------------- #
.PHONY: wrap wrappers
wrappers: wrap
wrap: $(filter wrap_%,$(MODULES))
###################################################################

#
# Tests
###################################################################
# Use make `test-MODULEDIR` to test a specific module.
# Each following recepe following this pattern will work the same
# --------------------------------------------------------------- #
.PHONY: test-%
test-%:
	@$(MAKE) $(subst test-,,$@) tests
	@echo
# --------------------------------------------------------------- #
.PHONY: tests tests_run test_report
test_report: tests
tests_run: tests
tests: RULE := tests
tests: $(MODULES)
###################################################################

#
# Completion tools
###################################################################
.PHONY: completion-tools tags ctags compiledb
# --------------------------------------------------------------- #
completion-tools: RULE := completion-tools
completion-tools: $(MODULES)
# --------------------------------------------------------------- #
ctags: RULE := ctags
ctags: $(MODULES)
# --------------------------------------------------------------- #
compiledb: RULE := compiledb
compiledb: $(MODULES)
###################################################################

#
# Make ever module and its tests
###################################################################
.PHONY: all $(NAME)
all: $(NAME)
$(NAME): RULE := all
$(NAME): $(MODULES)
###################################################################

#
# Cleanup
###################################################################
.PHONY: clean
clean: RULE := clean
clean: $(MODULES)
# --------------------------------------------------------------- #
.PHONY: fclean
fclean: RULE := fclean
fclean: $(MODULES)
###################################################################

#
# Scrap everything, build it again
###################################################################
.PHONY: re
re: RULE := re
re: $(MODULES)
###################################################################
