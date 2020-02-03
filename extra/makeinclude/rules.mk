##
## EPITECH PROJECT, 2019
## Libfox
## File description:
## Lib and object reciepes
##

ifndef MKRULES
MKRULES := 1

#
# Lib archive
##########################################
%.a:
	@if [ -e $@ ];                                                                   \
	then                                                                             \
	  $(ECHO$(BIN)) $(CBOLD)$(CLIGHTBLUE)"Update"$(CRESET) $(CLIGHTBLUE)$@$(CRESET); \
	  ar ru $(BIN) $^;                                                               \
	else                                                                             \
	  $(ECHO$(BIN)) $(CBOLD)$(CLIGHTBLUE)"Create"$(CRESET) $(CLIGHTBLUE)$@$(CRESET); \
	  ar rc $(BIN) $^;                                                               \
	fi
	@$(ECHO$(BIN)) $(CBOLD)$(CLIGHTBLUE)"Done."$(CRESET)
##########################################

#
# Object file
##########################################
%.o: CFLAGS += -MT $@ -MMD
%.o: %.c
	@$(CC) $(CFLAGS) -c -o $@ $< $(LDLIBS)
	@$(ECHO$(BIN)) $(CLIGHTGREEN)$(CBOLD)"Compile OK ✓"$(CRESET) $@
##########################################

endif
