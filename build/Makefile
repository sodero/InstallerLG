#---------------------------------------------------------------------------------#
# Universal
#---------------------------------------------------------------------------------#
VPATH := ../src
OBJ := $(subst .c,.o,$(notdir $(wildcard $(VPATH)/*.c)))
OS ?= $(shell uname)
DATE := $(shell date +%d.%m.%Y || echo Unknown)
APP := InstallerLG
EXE := Installer

INTERFACE := GUI
ifeq ($(INTERFACE),CLI)
OBJ := $(filter-out gui.o,$(OBJ))
else
OBJ := $(filter-out cli.o,$(OBJ))
endif

#---------------------------------------------------------------------------------#
# OS
#---------------------------------------------------------------------------------#
CWRN = -Wall -Wextra -Werror -pedantic -Wno-gnu-statement-expression
ifeq ($(OS),Linux)
CGEN = -g -std=c99
CDEF = -D_DEFAULT_SOURCE -D_GNU_SOURCE
else
ifeq ($(OS),Darwin)
CGEN = -g -std=c99
else
ifeq ($(OS),Windows_NT)
CC = x86_64-w64-mingw32-gcc.exe
CGEN = -g -std=c99
CDEF = -D_DEFAULT_SOURCE -D_GNU_SOURCE -D__USE_MINGW_ANSI_STDIO
else
CC ?= gcc
AMIGA = true
CWRN += -Wno-pointer-sign
CGEN = -Os -std=gnu99 -DAMIGA
LDLIBS = -ldebug
ifeq ($(OS),MorphOS)
CGEN += -noixemul
LDLIBS += -noixemul
endif
endif
endif
endif

ifneq ($(AMIGA),true)
DD = ..
endif

CINC += -I . -I $(VPATH)
CDEF += -D__AMIGADATE__="\"($(DATE))\"" $(CEXT)
CFLAGS += $(CINC) $(CGEN) $(CWRN) $(CDEF)
YACC = bison
LEX = flex

#---------------------------------------------------------------------------------#
# Targets
#---------------------------------------------------------------------------------#
$(EXE): $(OBJ) parser.o lexer.o
	$(CC) $^ -o $@ $(LDLIBS)

parser.o: parser.c
	$(CC) $(CFLAGS) -c $<

lexer.o: lexer.c
	$(CC) $(CINC) $(CDEF) $(CGEN) -c $<

parser.c: parser.y
ifneq ($(AMIGA),true)
	$(YACC) $(YFLAGS) -d $< -o $@
else
	@echo "[SKIPPED] $(YACC) $(YFLAGS) -d $< -o $@"
endif

parser.h: parser.c

lexer.c: lexer.l parser.h
ifneq ($(AMIGA),true)
	$(LEX) $(LFLAGS) -t $< > $@
else
	@echo "[SKIPPED] $(LEX) $(LFLAGS) -t $< > $@"
endif

gui.o: gui.c gui.h version.h
	$(CC) $(CFLAGS) -Wno-pedantic -Os -c $< -DLLVL=2

#---------------------------------------------------------------------------------#
# Catalogs
#---------------------------------------------------------------------------------#
.PHONY: cat
cat:
	for CAT in $(subst .ct,,$(notdir $(wildcard ../catalogs/*.ct))); do \
	mkdir -p Catalogs/$$CAT && \
	catcomp $(DD)/catalogs/$(APP).cd TRANSLATION $(DD)/catalogs/$$CAT.ct \
            CATALOG Catalogs/$$CAT/$(APP).catalog 2> /dev/null || \
	flexcat $(DD)/catalogs/$(APP).cd $(DD)/catalogs/$$CAT.ct \
            CATALOG Catalogs/$$CAT/$(APP).catalog || \
	rm -Rf Catalogs; done

#---------------------------------------------------------------------------------#
# Misc
#---------------------------------------------------------------------------------#
.PHONY: test
test: $(EXE)
	@chmod a+rwx _?* 2> /dev/null || true
	@$(RM) -R $(EXE).tmp.* leak.* err.* massif.* _?*
	@sh ../test/run.sh ./$(EXE) ../test

.PHONY: smoke
smoke:
	@LG_SMOKE=yes $(MAKE) test

.PHONY: quick
quick:
	@LG_QUICK=yes $(MAKE) test

.PHONY: fail
fail:
	@LG_FAIL=yes $(MAKE) test

.PHONY: debug
debug:
	@CFLAGS=-'DLG_DEBUG -Wno-unused-function' $(MAKE) $(EXE)

.PHONY: install
install: cat
	@cd ../dist && $(MAKE) && \
	./Installer "InstallerLG installer"

.PHONY: clean
clean:
	@chmod a+rwx _?* 2> /dev/null || true
	@$(RM) -R Catalogs *.o $(EXE) $(EXE).tmp.* leak.* err.* massif.* _?*
