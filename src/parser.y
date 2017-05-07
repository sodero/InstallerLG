%{
#include <stdio.h>
#include "debug.h"
#include "native.h"
#include "eval.h"
#include "util.h"

int yylex(void);
int yyerror(char *err);

extern int yylineno; 
%}

%union 
{
    int n; 
    char *s; 
    entry_p e;
}

%token<s> SYM STR 
%token<n> INT HEX BIN 

%token SET 
%token AND OR XOR NOT 
%token BITAND BITOR BITXOR BITNOT 
%token SHIFTLEFT SHIFTRIGHT

%type<e> start 
%type<e> s p vp np
%type<e> add set set_pp

%destructor { run($$); } start 
%destructor { free($$); } SYM STR
%destructor { kill($$); } s p vp np
%destructor { kill($$); } add set set_pp

%%
start:      s    
            ;

s:          s vp 
            { 
                push ($$, $2);                  
            } 
            |

            vp   
            { 
                $$ = new_contxt();   
                push ($$, $1);    
            } 
            ;

p:          vp 
            |
            np
            ;

vp:         add
            |
            set
            ;

np:         INT  
            { 
                $$ = new_number ($1); 
            } 
            |

            HEX  
            { 
                $$ = new_number ($1); 
            } 
            |

            BIN  
            { 
                $$ = new_number ($1); 
            }                        
            |

            STR  
            { 
                $$ = new_string ($1); 
            }                        
            |

            SYM  
            { 
                $$ = new_symref ($1, yylineno); 
            }    
            ;

add:        '(' '+' p p ')' 
            { 
                $$ = new_native (m_add, 2); 
                push ($$, $3);  
                push ($$, $4);  
            } 
            ;

set:        '(' SET set_pp ')' 
            { 
                $$ = $3; 
            } 
            ;

set_pp:     set_pp SYM p
            { 
                push ($$, new_symbol ($2, $3));  
            } 
            |
            SYM p
            { 
                $$ = new_native (m_set, 2); 
                push ($$, new_symbol ($1, $2));  
            } 
            ;
%%

int main(int argc, char **argv)
{
    yyparse();
    leak_check();
}

