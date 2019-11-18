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
	@if [ -e $@ ];                                                                      \
	then                                                                                \
	  $(ECHO$(NAME)) $(CBOLD)$(CLIGHTBLUE)"Updating"$(CRESET) $(CLIGHTBLUE)$@$(CRESET); \
	  ar ru $(BIN) $^;                                                                  \
	else                                                                                \
	  $(ECHO$(NAME)) $(CBOLD)$(CLIGHTBLUE)"Creating"$(CRESET) $(CLIGHTBLUE)$@$(CRESET); \
	  ar rc $(BIN) $^;                                                                  \
	fi
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
