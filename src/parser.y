%{
#include <stdio.h>
#include <string.h>
#include "debug.h"
#include "native.h"
#include "eval.h"
#include "util.h"
#include "sysenv.h"

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

%token                      SET DCL IF WHILE UNTIL
%token                      AND OR XOR NOT LTE GTE
%token                      BITAND BITOR BITXOR BITNOT 
%token                      SHIFTLEFT SHIFTRIGHT IN
%token                      STRLEN SUBSTR ASKDIR ASKFILE ASKSTRING ASKNUMBER ASKCHOICE ASKOPTIONS ASKBOOL ASKDISK CAT EXISTS EXPANDPATH EARLIER FILEONLY GETASSIGN GETDEVICE GETDISKSPACE GETENV GETSIZE GETSUM GETVERSION ICONINFO PATHONLY PATMATCH SELECT SYMBOLSET SYMBOLVAL TACKON TRANSCRIPT
%token<s>                   SYM STR 
%destructor { free($$); }   SYM STR
%token<n>                   INT HEX BIN 

%type<e>                    start 
%destructor { run($$);  }   start 
%type<e>                    s p pp ps vp vps vpb np sp sps par cv cvv
%destructor { kill($$); }   s p pp ps vp vps vpb np sp sps par cv cvv
%type<e>                    add sub div mul lt lte gt gte eq set cus dcl fmt if while until
%destructor { kill($$); }   add sub div mul lt lte gt gte eq set cus dcl fmt if while until
%type<e>                    and or xor not bitand bitor bitxor bitnot shiftleft shiftright in
%destructor { kill($$); }   and or xor not bitand bitor bitxor bitnot shiftleft shiftright in
%type<e>                    strlen substr askdir askfile askstring asknumber askchoice askoptions askbool askdisk cat exists expandpath earlier fileonly getassign getdevice getdiskspace getenv getsize getsum getversion iconinfo pathonly patmatch select symbolset symbolval tackon transcript
%destructor { kill($$); }   strlen substr askdir askfile askstring asknumber askchoice askoptions askbool askdisk cat exists expandpath earlier fileonly getassign getdevice getdiskspace getenv getsize getsum getversion iconinfo pathonly patmatch select symbolset symbolval tackon transcript

%%
start:         s                       { $$ = init($1); };
s:             vps                     ;
p:             vp                      |
               np                      ;
pp:            p p                     { $$ = push(push(new_contxt(), $1), $2); };
ps:            ps p                    { $$ = push($1, $2); } |
               p                       { $$ = push(new_contxt(), $1); };
vps:           vps vp                  { $$ = push($1, $2); } |
               vp                      { $$ = push(new_contxt(), $1); };
vpb:           '(' vps ')'             { $$ = $2; } |
               vp                      ;
np:            INT                     { $$ = new_number($1); } |
               HEX                     { $$ = new_number($1); } |
               BIN                     { $$ = new_number($1); } |
               STR                     { $$ = new_string($1); } |
               SYM                     { $$ = new_symref($1, yylineno); };
sp:            SYM p                   { $$ = new_symbol($1, $2); };
sps:           sps sp                  { $$ = push($1, $2); } |
               sp                      { $$ = push(new_contxt(), $1); };
par:           par SYM                 { $$ = push($1, new_symbol($2, new_dangle())); } |
               SYM                     { $$ = push(new_contxt(), new_symbol($1, new_dangle())); };
cv:            p vpb                   { $$ = push(push(new_contxt(), $1), $2); };
cvv:           p vpb vpb               { $$ = push(push(push(new_contxt(), $1), $2), $3); };
vp:            add                     |
               sub                     |
               div                     |
               mul                     |
               lt                      |
               lte                     |
               gt                      |
               gte                     |
               eq                      |
               set                     |
               cus                     |
               dcl                     |
               fmt                     |
               if                      |
               while                   |
               until                   |
               and                     |
               or                      |
               xor                     |
               not                     |
               bitand                  |
               bitor                   |
               bitxor                  |
               bitnot                  |
               shiftleft               | 
               shiftright              |
               in                      | 
               strlen                  | 
               substr                  | 
               askdir                  |
               askfile                 |
               askstring               |
               asknumber               |
               askchoice               |
               askoptions              |
               askbool                 |
               askdisk                 |
               cat                     |
               exists                  |
               expandpath              |
               earlier                 |
               fileonly                |
               getassign               |
               getdevice               |
               getdiskspace            |
               getenv                  |
               getsize                 |
               getsum                  |
               getversion              |
               iconinfo                |
               pathonly                |
               patmatch                |
               select                  |
               symbolset               |
               symbolval               |
               tackon                  |
               transcript              ;
fmt:           '(' STR ps ')'          { $$ = new_native($2, yylineno, m_fmt, $3); } |
               '(' STR ')'             { $$ = new_native($2, yylineno, m_fmt, NULL); };
dcl:           '(' DCL SYM par s ')'   { $$ = new_custom($3, yylineno, $4, $5); } |
               '(' DCL SYM s ')'       { $$ = new_custom($3, yylineno, NULL, $4); };
cus:           '(' SYM ps ')'          { $$ = new_cusref($2, yylineno, $3); } |
               '(' SYM ')'             { $$ = new_cusref($2, yylineno, NULL); };
add:           '(' '+' ps ')'          { $$ = new_native(strdup("+"), yylineno, m_add, $3); };
mul:           '(' '*' ps ')'          { $$ = new_native(strdup("*"), yylineno, m_mul, $3); };
sub:           '(' '-' pp ')'          { $$ = new_native(strdup("-"), yylineno, m_sub, $3); };
div:           '(' '/' pp ')'          { $$ = new_native(strdup("/"), yylineno, m_div, $3); };
lt:            '(' '<' pp ')'          { $$ = new_native(strdup("<"), yylineno, m_lt, $3); };
lte:           '(' LTE pp ')'          { $$ = new_native(strdup("<="), yylineno, m_lte, $3); };
gt:            '(' '>' pp ')'          { $$ = new_native(strdup(">"), yylineno, m_gt, $3); };
gte:           '(' GTE pp ')'          { $$ = new_native(strdup(">="), yylineno, m_gte, $3); };
eq:            '(' '=' pp ')'          { $$ = new_native(strdup("="), yylineno, m_eq, $3); };
set:           '(' SET sps ')'         { $$ = new_native(strdup("set"), yylineno, m_set, $3); };
if:            '(' IF cvv ')'          { $$ = new_native(strdup("if"), yylineno, m_if, $3); };
while:         '(' WHILE cv ')'        { $$ = new_native(strdup("while"), yylineno, m_while, $3); };
until:         '(' UNTIL cv ')'        { $$ = new_native(strdup("until"), yylineno, m_until, $3); };
and:           '(' AND pp ')'          { $$ = new_native(strdup("AND"), yylineno, m_and, $3); }; 
or:            '(' OR pp ')'           { $$ = new_native(strdup("OR"), yylineno, m_or, $3); }; 
xor:           '(' XOR pp ')'          { $$ = new_native(strdup("XOR"), yylineno, m_xor, $3); }; 
not:           '(' NOT p ')'           { $$ = new_native(strdup("NOT"), yylineno, m_not, push(new_contxt(), $3)); }; 
bitand:        '(' BITAND pp ')'       { $$ = new_native(strdup("BITAND"), yylineno, m_bitand, $3); }; 
bitor:         '(' BITOR pp ')'        { $$ = new_native(strdup("BITOR"), yylineno, m_bitor, $3); }; 
bitxor:        '(' BITXOR pp ')'       { $$ = new_native(strdup("BITXOR"), yylineno, m_bitxor, $3); }; 
bitnot:        '(' BITNOT p ')'        { $$ = new_native(strdup("BITNOT"), yylineno, m_bitnot, push(new_contxt(), $3)); }; 
shiftleft:     '(' SHIFTLEFT pp ')'    { $$ = new_native(strdup("shiftleft"), yylineno, m_shiftleft, $3); }; 
shiftright:    '(' SHIFTRIGHT pp ')'   { $$ = new_native(strdup("shiftright"), yylineno, m_shiftright, $3); }; 
in:            '(' IN p ps ')'         { $$ = new_native(strdup("IN"), yylineno, m_in, push(push(new_contxt(), $3), $4)); }; 
strlen:        '(' STRLEN p ')'        { $$ = new_native(strdup("strlen"), yylineno, m_strlen, push(new_contxt(), $3)); }; 
substr:        '(' SUBSTR p ps ')'     { $$ = new_native(strdup("substr"), yylineno, m_substr, push(push(new_contxt(), $3), $4)); }; 
askdir:        '(' ASKDIR ')'          { $$ = new_native(strdup("askdir"), yylineno, m_askdir, NULL); };
askfile:       '(' ASKFILE ')'         { $$ = new_native(strdup("askfile"), yylineno, m_askfile, NULL); };
askstring:     '(' ASKSTRING ')'       { $$ = new_native(strdup("askstring"), yylineno, m_askstring, NULL); };
asknumber:     '(' ASKNUMBER ')'       { $$ = new_native(strdup("asknumber"), yylineno, m_asknumber, NULL); };
askchoice:     '(' ASKCHOICE ')'       { $$ = new_native(strdup("askchoice"), yylineno, m_askchoice, NULL); };
askoptions:    '(' ASKOPTIONS ')'      { $$ = new_native(strdup("askoptions"), yylineno, m_askoptions, NULL); };
askbool:       '(' ASKBOOL ')'         { $$ = new_native(strdup("askbool"), yylineno, m_askbool, NULL); };
askdisk:       '(' ASKDISK ')'         { $$ = new_native(strdup("askdisk"), yylineno, m_askdisk, NULL); };
cat:           '(' CAT ps ')'          { $$ = new_native(strdup("cat"), yylineno, m_cat, $3); };
exists:        '(' EXISTS p ')'        { $$ = new_native(strdup("exists"), yylineno, m_exists, push(new_contxt(), $3)); }; 
expandpath:    '(' EXPANDPATH p ')'    { $$ = new_native(strdup("expandpath"), yylineno, m_expandpath, push(new_contxt(), $3)); }; 
earlier:       '(' EARLIER pp ')'      { $$ = new_native(strdup("earlier"), yylineno, m_earlier, $3); }; 
fileonly:      '(' FILEONLY p ')'      { $$ = new_native(strdup("fileonly"), yylineno, m_fileonly, push(new_contxt(), $3)); }; 
getassign:     '(' GETASSIGN pp ')'    { $$ = new_native(strdup("getassign"), yylineno, m_getassign, $3); }; 
getdevice:     '(' GETDEVICE p ')'     { $$ = new_native(strdup("getdevice"), yylineno, m_getdevice, push(new_contxt(), $3)); }; 
getdiskspace:  '(' GETDISKSPACE p ')'  { $$ = new_native(strdup("getdiskspace"), yylineno, m_getdiskspace, push(new_contxt(), $3)); }; 
getenv:        '(' GETENV p ')'        { $$ = new_native(strdup("getenv"), yylineno, m_getenv, push(new_contxt(), $3)); }; 
getsize:       '(' GETSIZE p ')'       { $$ = new_native(strdup("getsize"), yylineno, m_getsize, push(new_contxt(), $3)); }; 
getsum:        '(' GETSUM p ')'        { $$ = new_native(strdup("getsum"), yylineno, m_getsum, push(new_contxt(), $3)); }; 
getversion:    '(' GETVERSION p ')'    { $$ = new_native(strdup("getversion"), yylineno, m_getversion, push(new_contxt(), $3)); }; 
iconinfo:      '(' ICONINFO p ')'      { $$ = new_native(strdup("iconinfo"), yylineno, m_iconinfo, push(new_contxt(), $3)); }; 
pathonly:      '(' PATHONLY p ')'      { $$ = new_native(strdup("pathonly"), yylineno, m_pathonly, push(new_contxt(), $3)); }; 
patmatch:      '(' PATMATCH pp ')'     { $$ = new_native(strdup("patmatch"), yylineno, m_patmatch, $3); }; 
select:        '(' SELECT p ps ')'     { $$ = new_native(strdup("select"), yylineno, m_select, push(push(new_contxt(), $3), $4)); }; 
symbolset:     '(' SYMBOLSET pp ')'    { $$ = new_native(strdup("symbolset"), yylineno, m_symbolset, $3); }; 
symbolval:     '(' SYMBOLVAL p ')'     { $$ = new_native(strdup("symbolval"), yylineno, m_symbolval, push(new_contxt(), $3)); }; 
tackon:        '(' TACKON pp ')'       { $$ = new_native(strdup("tackon"), yylineno, m_tackon, $3); }; 
transcript:    '(' TRANSCRIPT pp ')'   { $$ = new_native(strdup("transcript"), yylineno, m_transcript, $3); }; 
%%

int main(int argc, char **argv)
{
    yyparse();
    leak_check();
}

