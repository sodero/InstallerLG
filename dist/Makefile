#---------------------------------------------------------------------------------#
# Universal
#---------------------------------------------------------------------------------#
EXE := installer
LHA := aminet/InstallerLG.lha
BIN := ../build
OS := $(shell uname)
FILES := $(EXE) 'InstallerNG installer' 'InstallerNG installer.info'

#---------------------------------------------------------------------------------#
# OS
#---------------------------------------------------------------------------------#
ifeq ($(OS),AROS)
else
ifeq ($(OS),MorphOS)
else
ifeq ($(OS),Linux)
else
ifeq ($(OS),Darwin)
endif
endif
endif
endif

#---------------------------------------------------------------------------------#
# Targets
#---------------------------------------------------------------------------------#
.PHONY: dist
dist: $(LHA)

.PHONY: clean
clean:
	$(MAKE) -C $(BIN) $@
	$(RM) $(EXE)
	$(RM) $(LHA)

$(LHA): $(EXE)
	lha a $@ $(FILES)
	cp $(BIN)/$(EXE) .

$(EXE):
	$(MAKE) -C $(BIN)
	cp $(BIN)/$(EXE) .

