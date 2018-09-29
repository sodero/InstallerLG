#---------------------------------------------------------------------------------#
# OS
#---------------------------------------------------------------------------------#
ifeq ($(shell uname),Darwin)
SED := gsed
else
SED := sed
endif

#-----------------------------------------------------------------------------------#
# Configuration
#-----------------------------------------------------------------------------------#
FLT := aros
DIR := aminet
SRC := ../src
BIN := ../build
EXE := installer
NAME := InstallerLG
OS := $(shell uname -s | tr A-Z a-z)
ARCH := $(shell uname -m | tr -d ower)
LHA := $(DIR)/$(NAME).$(ARCH)-$(OS).lha
README := $(DIR)/$(NAME).$(ARCH)-$(OS).readme
FILES := $(EXE) 'InstallerLG installer' 'InstallerLG installer.info'
STEMS := $(sort $(basename $(notdir $(wildcard $(SRC)/*.c) $(wildcard $(BIN)/*.c))))

#-----------------------------------------------------------------------------------#
# Targets
#-----------------------------------------------------------------------------------#
.PHONY: dist
dist: $(LHA) $(README)

.PHONY: aros
aros:
	cp $(SRC)/*.c $(FLT)
	cp $(SRC)/*.h $(FLT)
	cp $(BIN)/*.c $(FLT)
	cp $(BIN)/*.h $(FLT)
	$(SED) -i 's/FILES :=.*$$/FILES := $(STEMS)/' $(FLT)/mmakefile.src

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
	cat $^ | $(SED) -e 's/__ARCH__/$(ARCH)-$(OS)/' > $@

$(EXE):
	$(MAKE) -C $(BIN)
	cp $(BIN)/$(EXE) .

