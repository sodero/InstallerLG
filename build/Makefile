#---------------------------------------------------------------------------------#
# Universal
#---------------------------------------------------------------------------------#
VPATH := ../src
OBJ := $(subst .c,.o,$(notdir $(wildcard $(VPATH)/*.c)))
OS := $(shell uname)
DATE := $(shell date +%d.%m.%Y || echo Unknown)
EXE := Installer

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
CWRN += -Werror -Weverything -Wno-format-nonliteral -Wno-date-time
else
CC := gcc
AMIGA = true
CWRN = -Wall -Wextra -Wno-pointer-sign
CGEN = -Os -std=gnu99 -DAMIGA
LDLIBS = -ldebug
ifeq ($(OS),MorphOS)
LDLIBS += -noixemul
endif
endif
endif

ifneq ($(AMIGA),true)
DD = ..
endif

CINC += -I . -I $(VPATH)
CDEF += -D__AMIGADATE__="\"($(DATE))\""
CFLAGS += $(CINC) $(CGEN) $(CWRN) $(CDEF)

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
	catcomp $(DD)/src/$(EXE).cd TRANSLATION $(DD)/src/$$CAT.ct \
            CATALOG Catalogs/$$CAT/$(EXE).catalog 2> /dev/null || \
	flexcat $(DD)/src/$(EXE).cd $(DD)/src/$$CAT.ct \
            CATALOG Catalogs/$$CAT/$(EXE).catalog || \
	rm -Rf Catalogs; done

#---------------------------------------------------------------------------------#
# Misc
#---------------------------------------------------------------------------------#
.PHONY: test
test: $(EXE)
ifneq ($(AMIGA),true)
	@$(RM) $(EXE).tmp.* leak.* err.* massif.*
	@sh ../test/run.sh ./$(EXE) ../test $(REXTRA)
else
	@echo "[SKIPPED] @sh ../test/run.sh ./$(EXE) ../test $(REXTRA)"
endif

.PHONY: clean
clean:
	$(RM) -R Catalogs *.o $(EXE) $(EXE).tmp.* leak.* err.* massif.* _??_ _???_
