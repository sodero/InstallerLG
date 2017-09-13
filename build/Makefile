#---------------------------------------------------------------------------------#
# General 
#---------------------------------------------------------------------------------#
VPATH := ../src
OBJ := $(subst .c,.o,$(notdir $(wildcard $(VPATH)/*.c)))
OS := $(shell uname)

#---------------------------------------------------------------------------------#
# OS specifics
#---------------------------------------------------------------------------------#
CCCONF := -I . -I $(VPATH) -std=c99 
ifeq ($(OS),Linux)
CCCONF += -D_BSD_SOURCE -D_POSIX_SOURCE
CFLAGS += -Wall -g -Wno-unused-variable
else
ifeq ($(OS),Darwin)
CFLAGS += -Weverything -Wno-format-nonliteral -Wno-switch-enum -Wno-unused-variable
endif
endif
CFLAGS += $(CCCONF)

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
	$(RM) -R *.c *.h *.o installer lexer installer.tmp.* leak.* err.* _??_ _???_


