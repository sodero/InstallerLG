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
ifeq ($(OS),Linux)
CWRN = -Wall -Wextra -Werror
CGEN = -g -std=c99
CDEF = -D_DEFAULT_SOURCE -D_GNU_SOURCE
else
ifeq ($(OS),Darwin)
CGEN = -g -std=c99
CWRN += -Werror -Weverything -Wno-format-nonliteral -Wno-padded
else
ifeq ($(OS),Windows_NT)
CC = x86_64-w64-mingw32-gcc.exe
CWRN = -Wall -Wextra -Werror
CGEN = -g -std=c99
CDEF = -D_DEFAULT_SOURCE -D_GNU_SOURCE -D__USE_MINGW_ANSI_STDIO
else
CC ?= gcc
AMIGA = true
CWRN = -Wall -Wextra -Wno-pointer-sign
CGEN = -Os -std=gnu99 -DAMIGA
LDLIBS = -ldebug
ifeq ($(OS),MorphOS)
LDLIBS += -noixemul
endif
endif
endif
endif

ifneq ($(AMIGA),true)
DD = ..
endif

CINC += -I . -I $(VPATH)
CDEF += -D__AMIGADATE__="\"($(DATE))\""
CFLAGS += $(CINC) $(CGEN) $(CWRN) $(CDEF)
YACC = bison
LEX = flex

#---------------------------------------------------------------------------------#
# Targets
#---------------------------------------------------------------------------------#
$(EXE): $(OBJ) parser.o lexer.o
	$(CC) $^ -o $@ $(LDLIBS)

parser.o: parser.c
	$(CC) $(CINC) $(CDEF) $(CGEN) -c $< -DYYERROR_VERBOSE

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
	$(CC) -Os -c $< -DLLVL=2 $(CWRN) $(CDEF)

#---------------------------------------------------------------------------------#
# Catalogs
#---------------------------------------------------------------------------------#
.PHONY: cat
cat:
	for CAT in $(subst .ct,,$(notdir $(wildcard $(VPATH)/*.ct))); do \
	mkdir -p Catalogs/$$CAT && \
	catcomp $(DD)/src/$(APP).cd TRANSLATION $(DD)/src/$$CAT.ct \
            CATALOG Catalogs/$$CAT/$(APP).catalog 2> /dev/null || \
	flexcat $(DD)/src/$(APP).cd $(DD)/src/$$CAT.ct \
            CATALOG Catalogs/$$CAT/$(APP).catalog || \
	rm -Rf Catalogs; done

#---------------------------------------------------------------------------------#
# Misc
#---------------------------------------------------------------------------------#
.PHONY: test
test: $(EXE)
ifneq ($(AMIGA),true)
	@chmod a+rwx _?* 2> /dev/null || true
	@$(RM) -R $(EXE).tmp.* leak.* err.* massif.* _?*
	@sh ../test/run.sh ./$(EXE) ../test
else
	@echo "[SKIPPED] @sh ../test/run.sh ./$(EXE) ../test"
endif

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
