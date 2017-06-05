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

%token SET DCL IF WHILE
%token AND OR XOR NOT 
%token BITAND BITOR BITXOR BITNOT 
%token SHIFTLEFT SHIFTRIGHT

%type<e> start 
%type<e> s p pp ps vp vps vpb np sp sps par cv cvv
%type<e> add set cus dcl if while

%destructor { run($$); } start 
%destructor { free($$); } SYM STR
%destructor { kill($$); } s p pp ps vp vps vpb np sp sps par cv cvv
%destructor { kill($$); } add set cus dcl if while

%%
start:      s    
            ;

s:          vps
            ;

p:          vp 
            |

            np
            ;

pp:         p p
            { 
                $$ = new_contxt();   
                push($$, $1);    
                push($$, $2);    
            } 
            ;

ps:         ps p
            { 
                push ($1, $2);    
                $$ = $1;   
            }    
            |

            p
            { 
                $$ = new_contxt();   
                push ($$, $1);    
            }    
            ;

vp:         add
            |

            set
            |

            cus 
            |

            dcl
            |

            if 
            |

            while 
            ;

vps:        vps vp 
            { 
                push($1, $2);                  
                $$ = $1;
            } 
            |

            vp   
            { 
                $$ = new_contxt();   
                push($$, $1);    
            } 
            ;

vpb:        '(' vps ')'
            { 
                $$ = $2;
            } 
            |

            vp
            ;

np:         INT  
            { 
                $$ = new_number($1); 
            } 
            |

            HEX  
            { 
                $$ = new_number($1); 
            } 
            |

            BIN  
            { 
                $$ = new_number($1); 
            }                        
            |

            STR  
            { 
                $$ = new_string($1); 
            }                        
            |

            SYM  
            { 
                $$ = new_symref($1, yylineno); 
            }    
            ;

sp:         SYM p
            { 
                $$ = new_symbol($1, $2);   
                $2->parent = $$;
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
                $$ = new_native("+", m_add, $3); 
            } 
            ;

set:        '(' SET sps ')' 
            { 
                $$ = new_native("set", m_set, $3); 
            } 
            ;

par:        par SYM
            { 
                push($1, new_symbol($2, new_dangle())); 
                $$ = $1;   
            }    
            |

            SYM
            { 
                $$ = new_contxt();   
                push($$, new_symbol($1, new_dangle())); 
            }    
            ;

dcl:        '(' DCL SYM par s ')' 
            { 
                $$ = new_custom($3, yylineno, $4, $5); 
            } 
            |

            '(' DCL SYM s ')' 
            { 
                $$ = new_custom($3, yylineno, NULL, $4); 
            } 
            ;

cus:        '(' SYM ps ')' 
            { 
                $$ = new_cusref($2, yylineno, $3); 
            } 
            |

            '(' SYM ')' 
            { 
                $$ = new_cusref($2, yylineno, NULL); 
            } 
            ;

cv:         p vpb 
            { 
                $$ = new_contxt();   
                push($$, $1);    
                push($$, $2);    
            } 
            ;

cvv:        p vpb vpb 
            { 
                $$ = new_contxt();   
                push($$, $1);    
                push($$, $2);    
                push($$, $3);    
            } 
            ;

if:         '(' IF cvv ')' 
            { 
                $$ = new_native("if", m_if, $3); 
            } 
            ;

while:      '(' WHILE cv ')' 
            { 
                $$ = new_native("while", m_while, $3); 
            } 
            ;
%%

int main(int argc, char **argv)
{
    yyparse();
    leak_check();
}

