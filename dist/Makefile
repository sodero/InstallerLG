#---------------------------------------------------------------------------------#
# OS
#---------------------------------------------------------------------------------#
LHA?=lha
CPU?=$(shell uname -m | tr A-Z a-z | tr -d ower)
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
EXE:=InstallerLG
VER:=$(shell grep _VER_ ../src/version.h | cut -d ' ' -f3)
ARC:=$(DST)/$(EXE).$(ANM).lha
README:=$(DST)/$(EXE).$(ANM).readme
FILES:=$(EXE) 'Install' 'Install.info'
FILES+='InstallerLG.guide' 'InstallerLG.guide.info'

#-----------------------------------------------------------------------------------#
# Targets
#-----------------------------------------------------------------------------------#
.PHONY: dis
dis:
	echo $(VER)

tmp:
	mkdir -p $@

.PHONY: tmp/$(CAT)
tmp/$(CAT): tmp
	$(RM) -r $@
	$(MAKE) -C $(BIN) cat
	mv $(BIN)/$(CAT) tmp

tmp/$(EXE).$(ANM).readme: aminet/$(EXE).readme | tmp
	cat $^ | $(SED) -e 's/__CPU__/$(ANM)/' \
		   | $(SED) -e 's/__VER__/$(VER)/' > $@

tmp/$(EXE).guide: docs/$(EXE).guide | tmp
	cat $^ | $(SED) -e 's/__NOW__/NOW/' \
		   | $(SED) -e 's/__VER__/$(VER)/' > $@

tmp/Install: install/Install | tmp
	cat $^ | $(SED) -e 's/__NOW__/NOW/' \
		   | $(SED) -e 's/__VER__/$(VER)/' > $@



.PHONY: dist
dist: tmp/$(CAT) tmp/Install tmp/$(EXE).guide tmp/$(EXE).$(ANM).readme

.PHONY: clean
clean:
	$(RM) -r tmp
	$(MAKE) -C $(BIN) $@
	$(RM) $(EXE)
	$(RM) $(README)
	$(RM) $(DST)/*.lha
	$(RM) $(DST)/*.bak
	$(RM) *.info
	$(RM) -R $(EXE) Catalogs

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

$(README): $(DST)/$(EXE).readme
	cat $^ | $(SED) -e 's/__CPU__/$(ANM)/' \
		   | $(SED) -e 's/__VER__/$(VER)/' > $@
