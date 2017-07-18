#---------------------------------------------------------------------------------#
# General 
#---------------------------------------------------------------------------------#
VPATH := ../src
CCCONF := -I . -I $(VPATH) -std=c99 
CFLAGS += $(CCCONF)
OBJ := $(subst .c,.o,$(notdir $(wildcard $(VPATH)/*.c)))

#---------------------------------------------------------------------------------#
# OS specifics
#---------------------------------------------------------------------------------#
OS := $(shell uname)
ifeq ($(OS),Linux)
CFLAGS += -D_BSD_SOURCE -D_POSIX_SOURCE -Wall
else
ifeq ($(OS),Darwin)
CFLAGS += -Weverything -Wno-format-nonliteral
endif
endif

#---------------------------------------------------------------------------------#
# Build targets
#---------------------------------------------------------------------------------#
installer: $(OBJ) parser.o lexer.o
	$(CC) $^ -o $@ 

parser.h: parser.o

parser.o: parser.y
	$(YACC) -d $< -o $(notdir $(basename $<)).c
	$(CC) $(CCCONF) -c $(notdir $(basename $<)).c

lexer.o: lexer.l parser.h
	$(LEX) $(LFLAGS) -t $< > $(notdir $(basename $<)).c
	$(CC) $(CCCONF) -c $(notdir $(basename $<)).c

#---------------------------------------------------------------------------------#
# Misc
#---------------------------------------------------------------------------------#
.PHONY: test
test: installer
	@sh ../test/run.sh $(PWD)/installer ../test

.PHONY: clean
clean: 
	$(RM) *.c *.h *.o installer lexer installer.tmp.* leak.*

