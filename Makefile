##
## EPITECH PROJECT, 2019
## EvalExpr
## File description:
## Renaud sait pas faire un Makefile
##

#
# Config
################################################################
NAME    := libfox
SHELL   := $(shell which bash) # Yeah it looks dumb but you can never be too sure.
MAKE    := $(shell which make) --no-print-directory -C
RM      := $(shell which rm) -f
CP      := $(shell which cp) -t
MV      := $(shell which mv) -t
.DEFAULT_GOAL := all
################################################################

#
# Helper script to fetch module dirs and set rules for each one
################################################################
fetcher := .foxmodules.sh
define FOXMODULES_FETCHER
#!$(SHELL)
#
# $(fetcher)
# Copyright (C) 2019 renard <renard@voyager>
#
# Distributed under terms of the MIT license.
#

find . -maxdepth 1 -type d  					\
	| perl -pe 's/^\.\/?(\.\w*|extra)?//' \
	| perl -pe 's/^\n$$//' 						\
	| sort
endef
# ------------------------------------------------------------ #
$(call export FOXMODULES_FETCHER)
$(file >$(fetcher),$(FOXMODULES_FETCHER))
# ------------------------------------------------------------ #
MODULES = $(shell $(SHELL) $(fetcher))
################################################################

.PHONY: $(MODULES)
$(MODULES):
	@$(MAKE) $@ $(RULE)
	@echo

.PHONY: test-%
test-%:
	@$(MAKE) $(subst test-,,$@) tests
	@echo

.PHONY: compiledb
compiledb: RULE := compiledb
compiledb: $(MODULES)

.PHONY: all $(NAME)
all: $(NAME)
$(NAME): RULE := all
$(NAME): $(MODULES)

.PHONY: clean
clean: RULE := clean
clean: $(MODULES)
	-@rm $(fetcher)

.PHONY: fclean
fclean: RULE := fclean
fclean: $(MODULES)
	-@rm $(fetcher)

.PHONY: tests tests_run test_report
test_report: tests
tests_run: tests
tests: RULE := tests
tests: $(MODULES)

.PHONY: re
re: RULE := re
re: $(MODULES)
