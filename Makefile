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
# Helper script to fetch module dirs and set rules for each one
###################################################################
fetcher := .foxmodules.sh
# --------------------------------------------------------------- #
define FOXMODULES_FETCHER
#!$(SHELL)
#
# $(fetcher)
# Copyright (C) 2019 renard <renard@voyager>
#
# Distributed under terms of the MIT license.
#

find . -maxdepth 1 -type d                \
	| perl -pe 's/^\.\/?(\.\w*|extra)?//' \
	| perl -pe 's/^\n$$//'                \
	| sort
endef
# --------------------------------------------------------------- #
$(call export FOXMODULES_FETCHER) # Create a multi-line variable
$(file >$(fetcher),$(FOXMODULES_FETCHER)) # Write the script
# --------------------------------------------------------------- #
MODULES = $(shell $(SHELL) $(fetcher)) # Set modules
# This seems redundant, but it allows for running the script even
# without x permissions set.
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
	-@rm $(fetcher)
# --------------------------------------------------------------- #
.PHONY: fclean
fclean: RULE := fclean
fclean: $(MODULES)
	-@rm $(fetcher)
###################################################################

#
# Scrap everything, build it again
###################################################################
.PHONY: re
re: RULE := re
re: $(MODULES)
###################################################################
