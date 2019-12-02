##
## EPITECH PROJECT, 2019
## EvalExpr
## File description:
## Renaud sait pas faire un Makefile
##

## Config
NAME    := libfox
SHELL   := /bin/bash
MAKE    := make --no-print-directory -C
RM      := rm -f
CP      := cp -t
MV      := mv -t
.DEFAULT_GOAL := all

MODULES += datastruct
MODULES += io
MODULES += math
MODULES += memory
MODULES += std
MODULES += string

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

.PHONY: fclean
fclean: RULE := fclean
fclean: $(MODULES)

.PHONY: tests tests_run test_report
test_report: tests
tests_run: tests
tests: RULE := tests
tests: $(MODULES)

.PHONY: re
re: RULE := re
re: $(MODULES)
