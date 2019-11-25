##
## EPITECH PROJECT, 2019
## [PROJECT NAME]
## File description:
## [PROJECT DESCRIPTION]
##

ifndef MKRULES
MKRULES :=1

#
# Compile DB (recommended if you use vim with YouCompleteMe)
#########################################################################################
.PHONY: compiledb
ifneq "$(shell which compiledb 2>/dev/null)" ""
compiledb:
	@$(ECHO$(BIN)) $(CBOLD)$(CLIGHTBLUE)"Create"$(CRESET) $(CLIGHTBLUE)"$(COMPILEDB)"$(CRESET)
	@[[ "$(shell which compiledb)" == "" ]] || compiledb -no $(COMPILEDB) make -ki $(COMPILEDBTARGET)
	@$(ECHO$(BIN)) $(CBOLD)$(CLIGHTBLUE)"Done."$(CRESET)
else
compiledb:
	@$(ECHO$(BIN)) $(CRED)"compiledb "$(CBOLD)" is not installed"$(CRESET)$(CRED)", cannot create $(COMPILEDB)"
endif
#########################################################################################



#
# Main target
#########################################################################################
.PHONY: all module $(NAME)
all: $(NAME)
module: $(NAME)
$(NAME): compiledb $(BIN) tests
$(BIN): $(OBJ)
#########################################################################################



#
# Debug target
#########################################################################################
.PHONY: debug
debug: $(DEBUGBIN)
$(DEBUGBIN): CFLAGS += -ggdb3 -rdynamic
$(DEBUGBIN): SRC    += $(DEPSRC) $(DEBUGMAIN)
$(DEBUGBIN): $(SRC)
	$(CC) -o $@ $(CFLAGS) $(SRC)
#########################################################################################



#
# Test target
#########################################################################################
$(TESTBIN): CFLAGS += --coverage
$(TESTBIN): CFLAGS += $(WRAPFLAGS)
$(TESTBIN): CFLAGS += $(CMDCFLAGS)
$(TESTBIN): LDLIBS := -lcriterion
$(TESTBIN): SRC    += $(DEPSRC) $(TST) $(WRAPSRC)
$(TESTBIN): compiledb
	@$(RM) $(COV)
	@$(CC) -o $@ $(CFLAGS) $(SRC) $(LDLIBS)
# ------------------------------------------------------------------------------------- #
.PHONY: tests test_report
tests: test_report
test_report: $(TESTBIN)
	@$(ECHO$(BIN)) $(CUNDERLN)$(CGREEN)$(REPORTTXT)$(CRESET)
	@./$(TESTBIN) $(UTFLAGS)
	@$(RM) $(notdir $(DEPSRC:.c=.gc*) $(WRAPSRC:.c=.gc*))
	-@$(GCOV) $(COVFLAGS)
#########################################################################################



#
# Cleanup
#########################################################################################
.PHONY: clean
clean:
	@$(ECHO$(BIN)) $(CRED)"Delete"$(CRESET)" objects"
	@$(RM) $(OBJ)
	@$(ECHO$(BIN)) $(CRED)"Delete"$(CRESET)" dependency files"
	@$(RM) $(DEP)
	@$(ECHO$(BIN)) $(CRED)"Delete"$(CRESET)" coverage files"
	@$(RM) $(COV)
	@$(ECHO$(BIN)) $(CRED)"Delete"$(CRESET)" progress bar script ($(PROGSCRIPT))"
	@$(RM) $(PROGSCRIPT)
# ------------------------------------------------------------------------------------- #
.PHONY: fclean
fclean:
	@$(ECHO$(BIN)) $(CRED)"Delete"$(CRESET)" $(COMPILEDB)"
	@$(RM) $(COMPILEDB)
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
