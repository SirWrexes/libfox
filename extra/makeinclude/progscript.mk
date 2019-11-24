##
## EPITECH PROJECT, 2019
## Libfox
## File description:
## Progress bar script generation
##

ifndef PROGBAR-CODE

define PROGBAR-CODE
#!$(shell which python)
import argparse
import math
import sys

def main():
  parser = argparse.ArgumentParser(description=__doc__)
  parser.add_argument("--stepno", type=int, required=True)
  parser.add_argument("--nsteps", type=int, required=True)
  parser.add_argument("remainder", nargs=argparse.REMAINDER)
  args = parser.parse_args()

  nchars = int(math.log(args.nsteps, 10)) + 1
  fmt_str = "\033[38;2;255;167;4m[Libfox: $(NAME) | {:Xd}/{:Xd} | {:6.2f}%]\033[0m".replace("X", str(nchars))
  progress = 100 * args.stepno / args.nsteps
  sys.stdout.write(fmt_str.format(args.stepno, args.nsteps, progress))
  for item in args.remainder:
    sys.stdout.write(" ")
    sys.stdout.write(item)
  sys.stdout.write("\n")

if __name__ == "__main__":
  main()
endef

PROGSCRIPT := .progbar
$(call export PROGBAR-CODE) $(file >$(PROGSCRIPT),$(PROGBAR-CODE))
endif

ifndef ECHO$(BIN)
  T := $(shell $(MAKE) . $(MAKECMDGOALS)	\
       -nrRf $(firstword $(MAKEFILE_LIST)) 	\
       ECHO$(BIN)="COUNT$(BIN)" | grep -c "COUNT$(BIN)")
  N := x
  C = $(words $N)$(eval N := x $N)
  ECHO$(BIN) = python ./$(PROGSCRIPT) --stepno=$C --nsteps=$T
endif
