#---------------------------------------------------------------------------------#
# OS
#---------------------------------------------------------------------------------#
LHA?=lha
CPU?=$(shell uname -m | tr -d ower)
UNM?=$(shell uname)
ANM:=$(CPU)-$(shell echo $(UNM) | tr A-Z a-z)
ifeq ($(UNM),AmigaOS)
LHAFLAGS?=-r a
SHELL:=sh
else ifeq ($(UNM),MorphOS)
LHAFLAGS?=-r a
else
LHAFLAGS?=ao5
endif
ifeq ($(UNM),Darwin)
SED?=gsed
else
SED?=sed
endif

#-----------------------------------------------------------------------------------#
# Configuration
#-----------------------------------------------------------------------------------#
DST:=aminet
BIN:=../build
EXE:=Installer
CAT:=Catalogs
NAME:=InstallerLG
ARC:=$(DST)/$(NAME).$(ANM).lha
README:=$(DST)/$(NAME).$(ANM).readme
FILES:=$(EXE) 'InstallerLG installer' 'InstallerLG installer.info'
FILES+='InstallerLG.guide' 'InstallerLG.guide.info'

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
	$(RM) $(DST)/*.lha
	$(RM) $(DST)/*.bak
	$(RM) *.info
	$(RM) -R $(NAME) Catalogs

$(ARC): $(EXE)
	cp $(UNM)/*.info . && \
	$(LHA) $(LHAFLAGS) $@ $(CAT) && \
	$(LHA) $(LHAFLAGS) $@ $(FILES)

$(CAT):
	$(MAKE) -C $(BIN) cat && \
	mv $(BIN)/$(CAT) $@

$(EXE): $(CAT)
	$(MAKE) -C $(BIN) $(EXE)
	mv $(BIN)/$(EXE) $@

$(README): $(DST)/$(NAME).readme
	cat $^ | $(SED) -e 's/__ARCH__/$(ANM)/' > $@
