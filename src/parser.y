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
%type<e> s p pp vp np nps sp sps
%type<e> add set cus 

%destructor { run($$); } start 
%destructor { free($$); } SYM STR
%destructor { kill($$); } s p vp np nps sp sps
%destructor { kill($$); } add set 

%%
start:      s    
            ;

s:          s vp 
            { 
                push ($1, $2);                  
                $$ = $1;
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

pp:         p p
            { 
                $$ = new_contxt();   
                push ($$, $1);    
                push ($$, $2);    
            } 
            ;

vp:         add
            |
            set
            |
            cus 
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

nps:        nps np
            { 
                push ($1, $2);    
                $$ = $1;   
            }    
            |
            np
            { 
                $$ = new_contxt();   
                push ($$, $1);    
            }    
            ;

sp:         SYM p
            { 
                $$ = new_symbol ($1, $2);   
            } 
            ;

sps:        sps sp
            { 
                push ($1, $2);    
                $$ = $1;   
            }    
            |
            sp
            { 
                $$ = new_contxt();   
                push ($$, $1);    
            }    
            ;

add:        '(' '+' pp ')' 
            { 
                $$ = new_native (m_add, $3); 
            } 
            ;

set:        '(' SET sps ')' 
            { 
                $$ = new_native (m_set, $3); 
            } 
            ;

cus:        '(' SYM nps ')' 
            { 
                $$ = new_cusref ($2, $3); 
            } 
            ;
%%

int main(int argc, char **argv)
{
    yyparse();
    leak_check();
}

