#---------------------------------------------------------------------------------#
# Universal
#---------------------------------------------------------------------------------#
EXE := installer
BINDIR := ../build
OS := $(shell uname)

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
dist:
	$(MAKE) -C $(BINDIR)
	cp $(BINDIR)/$(EXE) .

.PHONY: clean
clean:
	$(MAKE) -C $(BINDIR) clean
	$(RM) $(EXE)