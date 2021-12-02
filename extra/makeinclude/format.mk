##
## EPITECH PROJECT, 2019
## Libfox
## File description:
## Text formatting variables
##

ifndef MKFORMAT
MKFORMAT := 1

ifneq "$(USER)" "bugs"
# The autograder doesn't support coloured output.
# Deactivate it when building from there.

# Format cleanup
##########################################
CRESET      :=	$$'\033[0m'
##########################################


#
# Colours
##########################################
# \033[38;2;<R>;<G>;<B>m
CRED        :=	$$'\033[38;2;255;0;0m'
CGREEN      :=	$$'\033[1;32;40m'
CLIGHTGREEN :=  $$'\033[38;2;190;255;200m'
CBLUE       :=	$$'\033[38;2;0;0;255m'
CLIGHTBLUE  :=	$$'\033[38;2;88;255;250m'
CORANGE     :=	$$'\033[38;2;255;167;4m'
##########################################


#
# Format
##########################################
CBOLD       :=  $$'\033[1m'
CUNDERLN    :=  $$'\033[4m'
##########################################


endif
endif
