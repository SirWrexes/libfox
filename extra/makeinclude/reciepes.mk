##
## EPITECH PROJECT, 2019
## Libfox
## File description:
## Receipes for a good healthy lib meal
##

ifndef MKRECEIPES
MKRECEIPES :=1

#
# Compile DB and C tags (recommended if you use vim with YouCompleteMe)
#########################################################################################
.PHONY: completion-tools
completion-tools: ctags compiledb
# ------------------------------------------------------------------------------------- #
.PHONY: compiledb
ifneq "$(shell which compiledb 2>/dev/null)" ""
compiledb:
	@$(ECHO$(BIN)) $(CBOLD)$(CLIGHTBLUE)"Create"$(CRESET) $(CLIGHTBLUE)"$(COMPILEDB)"$(CRESET)
	@compiledb -no $(COMPILEDB) make -nrRki $(COMPILEDBTARGET) 2>/dev/null
	@$(ECHO$(BIN)) $(CBOLD)$(CLIGHTBLUE)"Done."$(CRESET)
else
compiledb:
	@$(ECHO$(BIN)) $(CRED)"compiledb "$(CBOLD)" is not installed"$(CRESET)$(CRED)", cannot create $(COMPILEDB)"
endif
# ------------------------------------------------------------------------------------- #
.PHONY: ctags
ifneq "$(shell which ctags 2>/dev/null)" ""
ctags: CURRDIR := $(shell pwd)
ctags:
	@$(ECHO$(BIN)) $(CBOLD)$(CLIGHTBLUE)"Create"$(CRESET) $(CLIGHTBLUE)"$(CTAGS)"$(CRESET)
	@ctags -Ro "$(CURRDIR)/tags" $(CURRDIR)
	@$(ECHO$(BIN)) $(CBOLD)$(CLIGHTBLUE)"Done."$(CRESET)
else
ctags:
	@$(ECHO$(BIN)) $(CRED)"ctags "$(CBOLD)" is not installed"$(CRESET)$(CRED)", cannot create $(ctags)"
endif
#########################################################################################



#
# Main target
#########################################################################################
.PHONY: all module $(NAME)
all: $(NAME)
module: $(NAME)
$(NAME): COMPILEDBTARGET := $(NAME)
$(NAME): completion-tools
$(NAME): $(BIN)
$(NAME): tests
$(BIN): $(OBJ)
#########################################################################################



#
# Debug target
#########################################################################################
.PHONY: debug
debug: $(DEBUGBIN)
$(DEBUGBIN): COMPILEDBTARGET := $(DEBUGBIN)
$(DEBUGBIN): CFLAGS += -ggdb3 -rdynamic
$(DEBUGBIN): SRC    += $(DEPSRC) $(DEBUGMAIN)
$(DEBUGBIN): completion-tools
$(DEBUGBIN): $(SRC) $(DEBUGMAIN)
	$(CC) -o $@ $(CFLAGS) $(SRC) $(LDLIBS) $(CMDOPTS)
#########################################################################################



#
# Test target
#########################################################################################
$(TESTBIN): COMPILEDBTARGET := $(TESTBIN)
$(TESTBIN): CFLAGS += --coverage
$(TESTBIN): CFLAGS += $(WRAPFLAGS)
$(TESTBIN): CFLAGS += $(CMDCFLAGS)
$(TESTBIN): CFLAGS += $(CUSTOM_UTCFLAGS)
$(TESTBIN): LDLIBS += -lcriterion
$(TESTBIN): SRC    += $(DEPSRC) $(TST) $(WRAPSRC)
$(TESTBIN): completion-tools
	@$(RM) $(COV)
	@$(CC) -o $@ $(CFLAGS) $(SRC) $(LDLIBS)
# ------------------------------------------------------------------------------------- #
.PHONY: tests test_report
tests: test_report
ifndef SKIP_TEST_REPORT
test_report: $(TESTBIN)
	@$(ECHO$(BIN)) $(CUNDERLN)$(CGREEN)$(REPORTTXT)$(CRESET)
	@./$(TESTBIN) $(UTFLAGS)
	@$(RM) $(notdir $(DEPSRC:.c=.gc*) $(WRAPSRC:.c=.gc*))
	@$(GCOV) $(COVFLAGS)
else
test_report: REPORTTXT := "Skip tests"
test_report: $(TESTBIN)
	@$(ECHO$(BIN)) $(CUNDERLN)$(CRED)$(REPORTTXT)$(CRESET)
endif
#########################################################################################


#
# Cleanup
#########################################################################################
.PHONY: rm_test_tmp
rm_test_tmp:
	@$(ECHO$(BIN)) $(CRED)"Delete"$(CRESET)" *.tmp"
	@$(RM) *.tmp
# ------------------------------------------------------------------------------------- #
.PHONY: clean
clean: rm_test_tmp
	@$(ECHO$(BIN)) $(CRED)"Delete"$(CRESET)" objects"
	@$(RM) $(OBJ)
	@$(ECHO$(BIN)) $(CRED)"Delete"$(CRESET)" dependency files"
	@$(RM) $(DEP)
	@$(ECHO$(BIN)) $(CRED)"Delete"$(CRESET)" following coverage files"
	@$(RM) $(COV)
	@$(ECHO$(BIN)) $(CRED)"Delete"$(CRESET)" progress bar script ($(PROGSCRIPT))"
	@$(RM) $(PROGSCRIPT)
# ------------------------------------------------------------------------------------- #
.PHONY: fclean
fclean: rm_test_tmp
	@$(ECHO$(BIN)) $(CRED)"Delete"$(CRESET)" $(COMPILEDB)"
	@$(RM) $(COMPILEDB)
	@$(ECHO$(BIN)) $(CRED)"Delete"$(CRESET)" $(CTAGS)"
	@$(RM) $(CTAGS)
	@$(ECHO$(BIN)) $(CRED)"Delete"$(CRESET)" objects"
	@$(RM) $(OBJ)
	@$(ECHO$(BIN)) $(CRED)"Delete"$(CRESET)" dependency files"
	@$(RM) $(DEP)
	@$(ECHO$(BIN)) $(CRED)"Delete"$(CRESET)" coverage files"
	@$(RM) $(COV)
	@$(ECHO$(BIN)) $(CRED)"Delete"$(CRESET) $(BIN)
	@$(RM) $(BIN)
	@$(ECHO$(BIN)) $(CRED)"Delete"$(CRESET) $(TESTBIN)
	@$(RM) $(TESTBIN)
	@$(ECHO$(BIN)) $(CRED)"Delete"$(CRESET) $(DEBUGBIN)
	@$(RM) $(DEBUGBIN)
	@$(ECHO$(BIN)) $(CRED)"Delete"$(CRESET)" progress bar script ($(PROGSCRIPT))"
	@$(RM) $(PROGSCRIPT)
# ------------------------------------------------------------------------------------- #
.PHONY: re
re:
	@$(MAKE) . fclean
	@$(MAKE) . all
#########################################################################################

endif
