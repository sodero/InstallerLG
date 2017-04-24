%{
#include <stdio.h>
#include "debug.h"
#include "native.h"
#include "eval.h"
#include "util.h"

int yylex(void);
int yyerror(char *err);
%}

%union 
{
    int n; 
    char *s; 
    entry_p e;
}

%token<s> SYM STR 
%token<n> INT HEX BIN 
%token SET AND OR XOR NOT BITAND BITOR BITXOR BITNOT SHIFTLEFT SHIFTRIGHT

%type<e> add set
%type<e> s p vp np ap v n a

%destructor { free($$); } SYM STR
%destructor { kill($$); } s p vp np ap v n a add set

%%
start:      s    
            { 
                eval_as_contxt ($1); 
                kill($1);
            } 

s:          s vp 
            { 
                push ($$, $2);                  
            } 
            |

            s ap 
            { 
                push ($$, $2);                  
            } 
            |

            vp   
            { 
                $$ = new_contxt();   
                push ($$, $1);    
            } 
            |

            ap   
            { 
                $$ = new_contxt();   
                push ($$, $1);    
            } 
            ;

p:          vp 
            |
            np
            ;

vp:         v  
            ;

np:         n     
            ;

ap:         a
            ;

v:          add
            ;

n:          INT  
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
                $$ = new_symref ($1); 
            }    
            ;

a:          set
            ;

add:        '(' '+' p p ')' 
            { 
                $$ = new_native (m_add, 2); 
                push ($$, $3);  
                push ($$, $4);  
            } 
            ;

set:        '(' SET SYM p ')' 
            { 
                $$ = new_symbol ($3, $4); 
            } 
            ;

%%

int main(int argc, char **argv)
{
    yyparse();
    LEAK_CHECK;
}

