#---------------------------------------------------------------------------------#
# Configuration
#---------------------------------------------------------------------------------#
FLT := aros
DIR := aminet
SRC := ../src
BIN := ../build
EXE := installer
NAME := InstallerLG
ARCH := $(shell uname -m)
OS := $(shell uname -s | tr A-Z a-z)
LHA := $(DIR)/$(NAME).$(ARCH)-$(OS).lha
README := $(DIR)/$(NAME).$(ARCH)-$(OS).readme
FILES := $(EXE) 'InstallerLG installer' 'InstallerLG installer.info'

#---------------------------------------------------------------------------------#
# Targets
#---------------------------------------------------------------------------------#
.PHONY: dist
dist: $(LHA) $(README)

.PHONY: aros
aros:
	cp $(SRC)/*.c $(FLT)
	cp $(SRC)/*.h $(FLT)
	cp $(BIN)/*.c $(FLT)
	cp $(BIN)/*.h $(FLT)

.PHONY: src
src: clean aros
	mkdir $(NAME)
	cp ../LICENSE $(NAME)
	cp ../README.md $(NAME)
	cp -R ../build $(NAME)
	cp -R ../src $(NAME)
	cp -R ../test $(NAME)
	cp -R aros $(NAME)
	lha a $(DIR)/$(NAME).src.lha $(NAME)

.PHONY: clean
clean:
	$(MAKE) -C $(BIN) $@
	$(RM) $(EXE)
	$(RM) $(README)
	$(RM) $(DIR)/*.lha
	$(RM) $(FLT)/*.c $(FLT)/*.h
	$(RM) -R $(NAME)

$(LHA): $(EXE)
	lha a $@ $(FILES)
	cp $(BIN)/$(EXE) .

$(README): $(DIR)/$(NAME).readme
	cat $^ | sed -e 's/__ARCH__/$(ARCH)-$(OS)/' > $@

$(EXE):
	$(MAKE) -C $(BIN)
	cp $(BIN)/$(EXE) .

