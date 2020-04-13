#---------------------------------------------------------------------------------#
# OS
#---------------------------------------------------------------------------------#
OS := $(shell uname)
ifeq ($(OS),Darwin)
SED := gsed
else
SED := sed
endif
ifeq ($(OS),MorphOS)
LHAFLAGS := -r u
else
LHAFLAGS := ao5
endif

#-----------------------------------------------------------------------------------#
# Configuration
#-----------------------------------------------------------------------------------#
DIR := aminet
BIN := ../build
EXE := Installer
CAT := Catalogs
NAME := InstallerLG
OS := $(shell uname -s | tr A-Z a-z)
ARCH := $(shell uname -m | tr -d ower)
ARC := $(DIR)/$(NAME).$(ARCH)-$(OS).lha
README := $(DIR)/$(NAME).$(ARCH)-$(OS).readme
FILES := $(EXE) $(CAT) 'InstallerLG installer' 'InstallerLG installer.info'
FILES += 'InstallerLG.guide' 'InstallerLG.guide.info'

#-----------------------------------------------------------------------------------#
# Targets
#-----------------------------------------------------------------------------------#
.PHONY: dist
dist: $(ARC) $(README)

.PHONY: clean
clean:
	$(MAKE) -C $(BIN) $@
	$(RM) $(EXE)
	$(RM) $(README)
	$(RM) $(DIR)/*.lha
	$(RM) -R $(NAME) Catalogs

$(ARC): $(EXE)
	lha $(LHAFLAGS) $@ $(FILES)

$(CAT):
	$(MAKE) -C $(BIN) cat && \
	mv $(BIN)/$(CAT) $@

$(EXE): $(CAT)
	$(MAKE) -C $(BIN) $(EXE)
	mv $(BIN)/$(EXE) $@

$(README): $(DIR)/$(NAME).readme
	cat $^ | $(SED) -e 's/__ARCH__/$(ARCH)-$(OS)/' > $@
