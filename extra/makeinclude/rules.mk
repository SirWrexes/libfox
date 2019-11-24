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
compiledb:
	@$(ECHO$(NAME)) $(CBOLD)$(CLIGHTBLUE)"Create"$(CRESET) $(CLIGHTBLUE)"$(COMPILEDB)"$(CRESET)
	@[[ "$(shell which compiledb)" == "" ]] || compiledb -no $(COMPILEDB) make -ki $(COMPILEDBTARGET)
	@$(ECHO$(NAME)) $(CBOLD)$(CLIGHTBLUE)"Done."$(CRESET)
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
	@$(ECHO$(NAME)) $(CUNDERLN)$(CGREEN)$(REPORTTXT)$(CRESET)
	@./$(TESTBIN) $(UTFLAGS)
	@$(RM) $(notdir $(DEPSRC:.c=.gc*) $(WRAPSRC:.c=.gc*))
	-@$(GCOV) $(COVFLAGS)
#########################################################################################



#
# Cleanup
#########################################################################################
.PHONY: clean
clean:
	@$(ECHO$(NAME)) $(CRED)"Delete"$(CRESET)" objects"
	@$(RM) $(OBJ)
	@$(ECHO$(NAME)) $(CRED)"Delete"$(CRESET)" dependency files"
	@$(RM) $(DEP)
	@$(ECHO$(NAME)) $(CRED)"Delete"$(CRESET)" coverage files"
	@$(RM) $(COV)
	@$(ECHO$(NAME)) $(CRED)"Delete"$(CRESET)" progress bar script ($(PROGSCRIPT))"
	@$(RM) $(PROGSCRIPT)
# ------------------------------------------------------------------------------------- #
.PHONY: fclean
fclean:
	@$(ECHO$(NAME)) $(CRED)"Delete"$(CRESET)" $(COMPILEDB)"
	@$(RM) $(COMPILEDB)
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
	@$(ECHO$(NAME)) $(CRED)"Delete"$(CRESET)" progress bar script ($(PROGSCRIPT))"
	@$(RM) $(PROGSCRIPT)
# ------------------------------------------------------------------------------------- #
.PHONY: re
re:
	@$(MAKE) . fclean
	@$(MAKE) . all
#########################################################################################

endif
