#---------------------------------------------------------------------------------#
# Configuration
#---------------------------------------------------------------------------------#
DIR := aminet
BIN := ../build
EXE := installer
NAME := InstallerLG
OS := $(shell uname)
ARCH := $(shell uname -a | awk '{print $$(NF)}')
LHA := $(DIR)/$(NAME).$(ARCH)-$(OS).lha
README := $(DIR)/$(NAME).$(ARCH)-$(OS).readme
FILES := $(EXE) 'InstallerLG installer' 'InstallerLG installer.info'

#---------------------------------------------------------------------------------#
# Targets
#---------------------------------------------------------------------------------#
.PHONY: dist
dist: $(LHA) $(README)

.PHONY: clean
clean:
	$(MAKE) -C $(BIN) $@
	$(RM) $(EXE)
	$(RM) $(LHA)
	$(RM) $(README)

$(LHA): $(EXE)
	lha a $@ $(FILES)
	cp $(BIN)/$(EXE) .

$(README): $(DIR)/$(NAME).readme
	cat $^ | sed -e 's/__ARCH__/$(ARCH)-$(OS)/' > $@

$(EXE):
	$(MAKE) -C $(BIN)
	cp $(BIN)/$(EXE) .

