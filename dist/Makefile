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
LHAFLAGS?=mo5
endif
ifeq ($(UNM),Darwin)
SED?=gsed
else
SED?=sed
endif

#-----------------------------------------------------------------------------------#
# Configuration
#-----------------------------------------------------------------------------------#
BLD:=../build
BIN:=Installer
CAT:=Catalogs
PRJ:=InstallerLG
TMP:=tmp
VER?=$(shell grep 'define _VER_' ../src/version.h | cut -d ' ' -f3)
NOW:=$(shell date +%Y-%m-%d || echo 1985-07-23)

#-----------------------------------------------------------------------------------#
# Create LHa archive
#-----------------------------------------------------------------------------------#
$(TMP)/$(PRJ).$(ANM).lha: $(TMP)/$(BIN) $(TMP)/$(CAT) $(TMP)/Install \
						  $(TMP)/Install.info $(TMP)/$(PRJ).guide \
						  $(TMP)/$(PRJ).$(ANM).readme
	cd $(TMP) && $(LHA) $(LHAFLAGS) $(notdir $@) \
	$(filter-out %.lha,$(filter-out %.readme,$(notdir $(wildcard $(TMP)/*))))

#-----------------------------------------------------------------------------------#
# Create temp directory
#-----------------------------------------------------------------------------------#
$(TMP):
	mkdir -p $@

#-----------------------------------------------------------------------------------#
# Build catalogs
#-----------------------------------------------------------------------------------#
$(TMP)/$(CAT): | $(TMP)
	$(RM) -r $@
	$(MAKE) -C $(BLD) cat
	mv $(BLD)/$(CAT) $(TMP)

#-----------------------------------------------------------------------------------#
# Build executable
#-----------------------------------------------------------------------------------#
$(TMP)/$(BIN): | $(TMP)
	$(MAKE) -C $(BLD)
	mv $(BLD)/$(BIN) $@

#-----------------------------------------------------------------------------------#
# Function for template translation
#-----------------------------------------------------------------------------------#
define translate
	cat $(1) \
	| $(SED) -e 's/__CPU__/$(ANM)/' \
	| $(SED) -e 's/__VER__/$(VER)/' \
	| $(SED) -e 's/__NOW__/$(NOW)/' \
	> $(2)
endef

#-----------------------------------------------------------------------------------#
# Generate README and AmigaGuide from templates
#-----------------------------------------------------------------------------------#
$(TMP)/$(PRJ).$(ANM).readme: aminet/$(PRJ).readme | $(TMP)
	$(call translate,$^,$@)

$(TMP)/$(PRJ).guide: docs/$(PRJ).guide | $(TMP)
	$(call translate,$^,$@)

#-----------------------------------------------------------------------------------#
# Generate installer script from template
#-----------------------------------------------------------------------------------#
$(TMP)/Install: install/Install | $(TMP)
	$(call translate,$^,$@)

$(TMP)/Install.info: $(UNM)/Install.info | $(TMP)
	cp $(UNM)/Install.info $(TMP)

#-----------------------------------------------------------------------------------#
# Clean
#-----------------------------------------------------------------------------------#
.PHONY: clean
clean:
	$(MAKE) -C $(BLD) $@
	$(RM) -r $(TMP)
