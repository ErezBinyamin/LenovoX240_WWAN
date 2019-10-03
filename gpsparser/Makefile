#Enviroment Variables
NAME_1=gpsparser

#Sources
SRC_1=$(NAME_1).c

#Compliler
CC_1=gcc -Wall -pedantic -std=c99 -O1 -g3

#Output programs
PRG_1=$(NAME_1)
PROGRAMS=$(PRG_1) $(PRG_2) $(PRG_3)

#Compile all executables if any source files change
.PHONY: all
all:$(PROGRAMS)

$(PRG_1):$(SRC_1) $(DEP_1)
	@echo "Compiling $(SRC_1)"
	$(CC_1) -o $(PRG_1) $(SRC_1) $(DEP_1)

#Print help menu
.PHONY: help
help:
	@echo "\nHelp Menu:"
	@echo "\tall    : builds $(PROGRAMS)"
	@echo "\thelp   : prints this help menu"
	@echo "\tclean  : removes all temporary, output,  and intermediate files\n"

#Delete all compiled programs and test output files
.PHONY: clean
clean:
	-rm -f ./$(PROGRAMS)
