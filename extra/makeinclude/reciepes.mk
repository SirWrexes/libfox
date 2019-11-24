##
## EPITECH PROJECT, 2019
## Libfox
## File description:
## Lib and object reciepes
##

ifndef MKRECIEPES
MKRECIEPES := 1

#
# Lib archive
##########################################
%.a:
	@if [ -e $@ ];                                                                    \
	then                                                                              \
	  $(ECHO$(NAME)) $(CBOLD)$(CLIGHTBLUE)"Update"$(CRESET) $(CLIGHTBLUE)$@$(CRESET); \
	  ar ru $(BIN) $^;                                                                \
	else                                                                              \
	  $(ECHO$(NAME)) $(CBOLD)$(CLIGHTBLUE)"Create"$(CRESET) $(CLIGHTBLUE)$@$(CRESET); \
	  ar rc $(BIN) $^;                                                                \
	fi
	@$(ECHO$(NAME)) $(CBOLD)$(CLIGHTBLUE)"Done."$(CRESET)
##########################################

#
# Object file
##########################################
%.o: CFLAGS += -MT $@ -MMD
%.o: %.c
	@$(CC) $(CFLAGS) -c -o $@ $<
	@$(ECHO$(NAME)) $(CLIGHTGREEN)$(CBOLD)"Compile OK ✓"$(CRESET) $@
##########################################

endif
