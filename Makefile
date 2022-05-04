################
### Settings ###
################
# Program settings
APPNAME = celestial-simulation
EXT = .cpp
DIRSRC = src
# Compiler
CC = g++
CFLAGS = --std=c++17 -lsfml-graphics -lsfml-window -lsfml-system
# Build settings
CLEAN = true
DIRINT = intermediate
DIROBJ = $(DIRINT)/obj
DIRDEP = $(DIRINT)/dep


#####################
### Seach sources ###
#####################
SRC = $(shell find $(DIRSRC) -name *$(EXT))
OBJ = $(SRC:$(DIRSRC)/%$(EXT)=$(DIROBJ)/%.o)
DEP = $(OBJ:$(DIROBJ)/%.o=$(DIRDEP)/%.d)




#############
### Build ###
#############
# Build the app
$(APPNAME): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

# Create dependency rules
DIRDEP/%.d: $(SRCDIR)/%$(EXT)
	mkdir -p "$(shell dirname $@)"
	@$(CC) $(CFLAGS) $< -MM -MT $(@:$(DIRDEP)/%.d=$(DIROBJ)/%.o) >$@
-include $(DEP)

# Build object files
$(DIROBJ)/%.o: $(DIRSRC)/%$(EXT)
	mkdir -p "$(shell dirname $@)"
	$(CC) $(CFLAGS) -o $@ -c $<




############################
### Clean previous build ###
############################
.PHONY: clean
clean:
	rm -rf $(APPNAME) $(DIRINT)


######################
### Clean terminal ###
######################
.PHONY: clearterm
clearterm:
	clear

###########
### Run ###
###########
./PHONY: run
run: $(APPNAME)
	./$(APPNAME)



#####################
### Fresh compile ###
#####################
.PHONY: fresh
fresh: clean clearterm $(APPNAME)


##################
### Everything ###
##################
.PHONY: all
all: fresh run
