#---------------------------------------------------------------------------------#
# Universal
#---------------------------------------------------------------------------------#
VPATH := ../src
OBJ := $(subst .c,.o,$(notdir $(wildcard $(VPATH)/*.c)))
OS := $(shell uname)
EXE := installer

#---------------------------------------------------------------------------------#
# OS
#---------------------------------------------------------------------------------#
ifeq ($(OS),Linux)
CWRN = -Wall -Wno-unused-but-set-variable
CGEN = -g -std=c99
CDEF = -D_POSIX_SOURCE -D_DEFAULT_SOURCE
else
ifeq ($(OS),Darwin)
CGEN = -g -std=c99
CWRN = -Weverything -Wno-format-nonliteral -Wno-switch-enum
CWRN += -Wno-format-security -Wno-vla -Werror
else
CC := gcc
AMIGA = true
CWRN = -Wall -Wno-pointer-sign
CGEN = -Os -std=gnu99 -DAMIGA
LDLIBS = -ldebug
ifeq ($(OS),MorphOS)
LDLIBS += -noixemul
endif
endif
endif

I18N = strings.h
CINC += -I . -I $(VPATH)
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

gui.o: gui.c gui.h $(I18N)
	$(CC) -Os -c $< -DLLVL=2 $(CWRN)

$(I18N): Installer.cd
	catcomp $< CFILE $@ NONUMBERS 2> /dev/null || flexcat $< $@=CatComp_h.sd

deutsch: Installer.cd deutsch.ct
	mkdir -p Catalogs/$@
	catcomp $< $(word 2,$^) CATALOG Catalogs/$@/Installer.catalog 2> /dev/null || \
    flexcat $< $(word 2,$^) CATALOG Catalogs/$@/Installer.catalog

svenska: Installer.cd svenska.ct
	mkdir -p Catalogs/$@
	catcomp $< $(word 2,$^) CATALOG Catalogs/$@/Installer.catalog 2> /dev/null || \
    flexcat $< $(word 2,$^) CATALOG Catalogs/$@/Installer.catalog

#---------------------------------------------------------------------------------#
# Misc
#---------------------------------------------------------------------------------#
.PHONY: test
test: installer
ifneq ($(AMIGA),true)
	@sh ../test/run.sh ./$(EXE) ../test $(REXTRA)
else
	@echo "[SKIPPED] @sh ../test/run.sh ./$(EXE) ../test $(REXTRA)"
endif

.PHONY: clean
clean:
	$(RM) -Rf *.o $(EXE) $(EXE).tmp.* leak.* err.* _??_ _???_ Catalogs
