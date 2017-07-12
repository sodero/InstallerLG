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
%token                      STRLEN SUBSTR ASKDIR ASKFILE ASKSTRING ASKNUMBER ASKCHOICE ASKOPTIONS ASKBOOL ASKDISK CAT EXISTS EXPANDPATH EARLIER FILEONLY GETASSIGN GETDEVICE GETDISKSPACE GETENV GETSIZE GETSUM GETVERSION ICONINFO PATHONLY PATMATCH SELECT SYMBOLSET SYMBOLVAL TACKON TRANSCRIPT COMPLETE USER WORKING WELCOME ABORT COPYFILES COPYLIB DATABASE DEBUG DELETE EXECUTE
%token                      ALL APPEND ASKUSER ASSIGNS CHOICES COMMAND COMPRESSION CONFIRM DEFAULT DELOPTS DEST DISK FAIL FILES FONTS FORCE HELP INFOS INCLUDE NEWNAME NEWPATH NOFAIL NOGAUGE NOPOSITION NOREQ OKNODELETE PATTERN PROMPT RANGE SAFE SETDEFAULTTOOL SETSTACK SETTOOLTYPE SOURCE SWAPCOLORS OPTIONAL RESIDENT 
%token<s>                   SYM STR 
%destructor { free($$); }   SYM STR
%token<n>                   INT HEX BIN 
%type<e>                    start 
%destructor { run($$);  }   start 
%type<e>                    s p pp ps vp vps opt opts vpb np sp sps par cv cvv
%destructor { kill($$); }   s p pp ps vp vps opt opts vpb np sp sps par cv cvv
%type<e>                    add sub div mul lt lte gt gte eq set cus dcl fmt if while until
%destructor { kill($$); }   add sub div mul lt lte gt gte eq set cus dcl fmt if while until
%type<e>                    and or xor not bitand bitor bitxor bitnot shiftleft shiftright in
%destructor { kill($$); }   and or xor not bitand bitor bitxor bitnot shiftleft shiftright in
%type<e>                    strlen substr askdir askfile askstring asknumber askchoice askoptions askbool askdisk cat exists expandpath earlier fileonly getassign getdevice getdiskspace getenv getsize getsum getversion iconinfo pathonly patmatch select symbolset symbolval tackon transcript complete user working welcome abort copyfiles copylib database debug delete execute
%destructor { kill($$); }   strlen substr askdir askfile askstring asknumber askchoice askoptions askbool askdisk cat exists expandpath earlier fileonly getassign getdevice getdiskspace getenv getsize getsum getversion iconinfo pathonly patmatch select symbolset symbolval tackon transcript complete user working welcome abort copyfiles copylib database debug delete execute
%type<e>                    all append askuser assigns choices command compression confirm default delopts dest disk fail files fonts force help infos include newname newpath nofail nogauge noposition noreq oknodelete pattern prompt range safe setdefaulttool setstack settooltype source swapcolors optional resident 
%destructor { kill($$); }   all append askuser assigns choices command compression confirm default delopts dest disk fail files fonts force help infos include newname newpath nofail nogauge noposition noreq oknodelete pattern prompt range safe setdefaulttool setstack settooltype source swapcolors optional resident 

%%
start:          s                           { $$ = init($1); };
s:              vps                         ;
p:              vp                          |
                np                          ;
pp:             p p                         { $$ = push(push(new_contxt(), $1), $2); };
ps:             ps p                        { $$ = push($1, $2); } |
                p                           { $$ = push(new_contxt(), $1); };
vps:            vps vp                      { $$ = push($1, $2); } |
                vp                          { $$ = push(new_contxt(), $1); };
opts:           opts opt                    { $$ = push($1, $2); } |
                opt                         { $$ = push(new_contxt(), $1); };
vpb:            '(' vps ')'                 { $$ = $2; } |
                vp                          ;
np:             INT                         { $$ = new_number($1); } |
                HEX                         { $$ = new_number($1); } |
                BIN                         { $$ = new_number($1); } |
                STR                         { $$ = new_string($1); } |
                SYM                         { $$ = new_symref($1, yylineno); };
sp:             SYM p                       { $$ = new_symbol($1, $2); };
sps:            sps sp                      { $$ = push($1, $2); } |
                sp                          { $$ = push(new_contxt(), $1); };
par:            par SYM                     { $$ = push($1, new_symbol($2, new_dangle())); } |
                SYM                         { $$ = push(new_contxt(), new_symbol($1, new_dangle())); };
cv:             p vpb                       { $$ = push(push(new_contxt(), $1), $2); };
cvv:            p vpb vpb                   { $$ = push(push(push(new_contxt(), $1), $2), $3); };
opt:            all                         |            
                append                      |         
                askuser                     |         
                assigns                     |        
                choices                     |        
                command                     |        
                compression                 |        
                confirm                     |        
                default                     |        
                delopts                     |        
                dest                        |           
                disk                        |           
                fail                        |           
                files                       |          
                fonts                       |          
                force                       |          
                help                        |           
                infos                       |          
                include                     |        
                newname                     |        
                newpath                     |        
                nofail                      |        
                nogauge                     |        
                noposition                  |     
                noreq                       |     
                oknodelete                  |        
                pattern                     |        
                prompt                      |         
                range                       |          
                safe                        |           
                setdefaulttool              | 
                setstack                    |       
                settooltype                 |    
                source                      |         
                swapcolors                  |     
                optional                    |       
                resident                    ;
vp:             add                         |
                sub                         |
                div                         |
                mul                         |
                lt                          |
                lte                         |
                gt                          |
                gte                         |
                eq                          |
                set                         |
                cus                         |
                dcl                         |
                fmt                         |
                if                          |
                while                       |
                until                       |
                and                         |
                or                          |
                xor                         |
                not                         |
                bitand                      |
                bitor                       |
                bitxor                      |
                bitnot                      |
                shiftleft                   | 
                shiftright                  |
                in                          | 
                strlen                      | 
                substr                      | 
                askdir                      |
                askfile                     |
                askstring                   |
                asknumber                   |
                askchoice                   |
                askoptions                  |
                askbool                     |
                askdisk                     |
                cat                         |
                exists                      |
                expandpath                  |
                earlier                     |
                fileonly                    |
                getassign                   |
                getdevice                   |
                getdiskspace                |
                getenv                      |
                getsize                     |
                getsum                      |
                getversion                  |
                iconinfo                    |
                pathonly                    |
                patmatch                    |
                select                      |
                symbolset                   |
                symbolval                   |
                tackon                      |
                transcript                  |
                user                        |
                working                     |
                welcome                     |
                abort                       |
                copyfiles                   |
                copylib                     |
                database                    |
                debug                       |
                delete                      |
                execute                     |
                complete                    ;
fmt:            '(' STR ps ')'              { $$ = new_native($2, yylineno, m_fmt, $3); } |
                '(' STR ')'                 { $$ = new_native($2, yylineno, m_fmt, NULL); };
dcl:            '(' DCL SYM par s ')'       { $$ = new_custom($3, yylineno, $4, $5); } |
                '(' DCL SYM s ')'           { $$ = new_custom($3, yylineno, NULL, $4); };
cus:            '(' SYM ps ')'              { $$ = new_cusref($2, yylineno, $3); } |
                '(' SYM ')'                 { $$ = new_cusref($2, yylineno, NULL); };
add:            '(' '+' ps ')'              { $$ = new_native(strdup("+"), yylineno, m_add, $3); };
mul:            '(' '*' ps ')'              { $$ = new_native(strdup("*"), yylineno, m_mul, $3); };
sub:            '(' '-' pp ')'              { $$ = new_native(strdup("-"), yylineno, m_sub, $3); };
div:            '(' '/' pp ')'              { $$ = new_native(strdup("/"), yylineno, m_div, $3); };
lt:             '(' '<' pp ')'              { $$ = new_native(strdup("<"), yylineno, m_lt, $3); };
lte:            '(' LTE pp ')'              { $$ = new_native(strdup("<="), yylineno, m_lte, $3); };
gt:             '(' '>' pp ')'              { $$ = new_native(strdup(">"), yylineno, m_gt, $3); };
gte:            '(' GTE pp ')'              { $$ = new_native(strdup(">="), yylineno, m_gte, $3); };
eq:             '(' '=' pp ')'              { $$ = new_native(strdup("="), yylineno, m_eq, $3); };
set:            '(' SET sps ')'             { $$ = new_native(strdup("set"), yylineno, m_set, $3); };
if:             '(' IF cvv ')'              { $$ = new_native(strdup("if"), yylineno, m_if, $3); };
while:          '(' WHILE cv ')'            { $$ = new_native(strdup("while"), yylineno, m_while, $3); };
until:          '(' UNTIL cv ')'            { $$ = new_native(strdup("until"), yylineno, m_until, $3); };
and:            '(' AND pp ')'              { $$ = new_native(strdup("AND"), yylineno, m_and, $3); }; 
or:             '(' OR pp ')'               { $$ = new_native(strdup("OR"), yylineno, m_or, $3); }; 
xor:            '(' XOR pp ')'              { $$ = new_native(strdup("XOR"), yylineno, m_xor, $3); }; 
not:            '(' NOT p ')'               { $$ = new_native(strdup("NOT"), yylineno, m_not, push(new_contxt(), $3)); }; 
bitand:         '(' BITAND pp ')'           { $$ = new_native(strdup("BITAND"), yylineno, m_bitand, $3); }; 
bitor:          '(' BITOR pp ')'            { $$ = new_native(strdup("BITOR"), yylineno, m_bitor, $3); }; 
bitxor:         '(' BITXOR pp ')'           { $$ = new_native(strdup("BITXOR"), yylineno, m_bitxor, $3); }; 
bitnot:         '(' BITNOT p ')'            { $$ = new_native(strdup("BITNOT"), yylineno, m_bitnot, push(new_contxt(), $3)); }; 
shiftleft:      '(' SHIFTLEFT pp ')'        { $$ = new_native(strdup("shiftleft"), yylineno, m_shiftleft, $3); }; 
shiftright:     '(' SHIFTRIGHT pp ')'       { $$ = new_native(strdup("shiftright"), yylineno, m_shiftright, $3); }; 
in:             '(' IN p ps ')'             { $$ = new_native(strdup("IN"), yylineno, m_in, push(push(new_contxt(), $3), $4)); }; 
strlen:         '(' STRLEN p ')'            { $$ = new_native(strdup("strlen"), yylineno, m_strlen, push(new_contxt(), $3)); }; 
substr:         '(' SUBSTR p ps ')'         { $$ = new_native(strdup("substr"), yylineno, m_substr, push(push(new_contxt(), $3), $4)); }; 
askdir:         '(' ASKDIR ')'              { $$ = new_native(strdup("askdir"), yylineno, m_askdir, NULL); };
askfile:        '(' ASKFILE ')'             { $$ = new_native(strdup("askfile"), yylineno, m_askfile, NULL); };
askstring:      '(' ASKSTRING ')'           { $$ = new_native(strdup("askstring"), yylineno, m_askstring, NULL); };
asknumber:      '(' ASKNUMBER ')'           { $$ = new_native(strdup("asknumber"), yylineno, m_asknumber, NULL); };
askchoice:      '(' ASKCHOICE ')'           { $$ = new_native(strdup("askchoice"), yylineno, m_askchoice, NULL); };
askoptions:     '(' ASKOPTIONS ')'          { $$ = new_native(strdup("askoptions"), yylineno, m_askoptions, NULL); };
askbool:        '(' ASKBOOL ')'             { $$ = new_native(strdup("askbool"), yylineno, m_askbool, NULL); };
askdisk:        '(' ASKDISK ')'             { $$ = new_native(strdup("askdisk"), yylineno, m_askdisk, NULL); };
cat:            '(' CAT ps ')'              { $$ = new_native(strdup("cat"), yylineno, m_cat, $3); };
exists:         '(' EXISTS p ')'            { $$ = new_native(strdup("exists"), yylineno, m_exists, push(new_contxt(), $3)); }; 
expandpath:     '(' EXPANDPATH p ')'        { $$ = new_native(strdup("expandpath"), yylineno, m_expandpath, push(new_contxt(), $3)); }; 
earlier:        '(' EARLIER pp ')'          { $$ = new_native(strdup("earlier"), yylineno, m_earlier, $3); }; 
fileonly:       '(' FILEONLY p ')'          { $$ = new_native(strdup("fileonly"), yylineno, m_fileonly, push(new_contxt(), $3)); }; 
getassign:      '(' GETASSIGN pp ')'        { $$ = new_native(strdup("getassign"), yylineno, m_getassign, $3); }; 
getdevice:      '(' GETDEVICE p ')'         { $$ = new_native(strdup("getdevice"), yylineno, m_getdevice, push(new_contxt(), $3)); }; 
getdiskspace:   '(' GETDISKSPACE p ')'      { $$ = new_native(strdup("getdiskspace"), yylineno, m_getdiskspace, push(new_contxt(), $3)); }; 
getenv:         '(' GETENV p ')'            { $$ = new_native(strdup("getenv"), yylineno, m_getenv, push(new_contxt(), $3)); }; 
getsize:        '(' GETSIZE p ')'           { $$ = new_native(strdup("getsize"), yylineno, m_getsize, push(new_contxt(), $3)); }; 
getsum:         '(' GETSUM p ')'            { $$ = new_native(strdup("getsum"), yylineno, m_getsum, push(new_contxt(), $3)); }; 
getversion:     '(' GETVERSION p ')'        { $$ = new_native(strdup("getversion"), yylineno, m_getversion, push(new_contxt(), $3)); }; 
iconinfo:       '(' ICONINFO p ')'          { $$ = new_native(strdup("iconinfo"), yylineno, m_iconinfo, push(new_contxt(), $3)); }; 
pathonly:       '(' PATHONLY p ')'          { $$ = new_native(strdup("pathonly"), yylineno, m_pathonly, push(new_contxt(), $3)); }; 
patmatch:       '(' PATMATCH pp ')'         { $$ = new_native(strdup("patmatch"), yylineno, m_patmatch, $3); }; 
select:         '(' SELECT p ps ')'         { $$ = new_native(strdup("select"), yylineno, m_select, push(push(new_contxt(), $3), $4)); }; 
symbolset:      '(' SYMBOLSET pp ')'        { $$ = new_native(strdup("symbolset"), yylineno, m_symbolset, $3); }; 
symbolval:      '(' SYMBOLVAL p ')'         { $$ = new_native(strdup("symbolval"), yylineno, m_symbolval, push(new_contxt(), $3)); }; 
tackon:         '(' TACKON pp ')'           { $$ = new_native(strdup("tackon"), yylineno, m_tackon, $3); }; 
transcript:     '(' TRANSCRIPT pp ')'       { $$ = new_native(strdup("transcript"), yylineno, m_transcript, $3); }; 
complete:       '(' COMPLETE p ')'          { $$ = new_native(strdup("complete"), yylineno, m_complete, push(new_contxt(), $3)); }; 
user:           '(' USER p ')'              { $$ = new_native(strdup("user"), yylineno, m_user, push(new_contxt(), $3)); }; 
working:        '(' WORKING ')'             { $$ = new_native(strdup("working"), yylineno, m_working, new_contxt()); }; 
welcome:        '(' WELCOME ps ')'          { $$ = new_native(strdup("welcome"), yylineno, m_welcome, $3); }; 
abort:          '(' ABORT ps ')'            { $$ = new_native(strdup("abort"), yylineno, m_abort, $3); }; 
copyfiles:      '(' COPYFILES opts ')'      { $$ = new_native(strdup("copyfiles"), yylineno, m_copyfiles, $3); }; 
copylib:        '(' COPYLIB opts ')'        { $$ = new_native(strdup("copylib"), yylineno, m_copylib, $3); }; 
database:       '(' DATABASE p ')'          { $$ = new_native(strdup("database"), yylineno, m_database, push(new_contxt(), $3)); } | 
                '(' DATABASE pp ')'         { $$ = new_native(strdup("database"), yylineno, m_database, $3); }; 
debug:          '(' DEBUG ps ')'            { $$ = new_native(strdup("debug"), yylineno, m_debug, $3); }; 
delete:         '(' DELETE p opts')'        { $$ = new_native(strdup("delete"), yylineno, m_delete, push(push(new_contxt(), $3), $4)); } | 
                '(' DELETE p ')'            { $$ = new_native(strdup("delete"), yylineno, m_delete, push(new_contxt(), $3)); }; 
execute:        '(' EXECUTE p opts')'       { $$ = new_native(strdup("execute"), yylineno, m_execute, push(push(new_contxt(), $3), $4)); } | 
                '(' EXECUTE p ')'           { $$ = new_native(strdup("execute"), yylineno, m_execute, push(new_contxt(), $3)); }; 

all:            '(' ALL ')'                 { $$ = new_option(strdup("all"), OPT_ALL, NULL); };
append:         '(' APPEND p ')'            { $$ = new_option(strdup("append"), OPT_APPEND, push(new_contxt(), $3)); }; 
askuser:        '(' ASKUSER ')'             { $$ = new_option(strdup("askuser"), OPT_ASKUSER, NULL); };
assigns:        '(' ASSIGNS ')'             { $$ = new_option(strdup("assigns"), OPT_ASSIGNS, NULL); };
choices:        '(' CHOICES ps ')'          { $$ = new_option(strdup("choices"), OPT_CHOICES, $3); }; 
command:        '(' COMMAND ps ')'          { $$ = new_option(strdup("command"), OPT_COMMAND, $3); }; 
compression:    '(' COMPRESSION ')'         { $$ = new_option(strdup("compression"), OPT_COMPRESSION, NULL); };
confirm:        '(' CONFIRM p ')'           { $$ = new_option(strdup("confirm"), OPT_CONFIRM, push(new_contxt(), $3)); }; 
default:        '(' DEFAULT p ')'           { $$ = new_option(strdup("default"), OPT_DEFAULT, push(new_contxt(), $3)); }; 
delopts:        '(' DELOPTS opts ')'        { $$ = new_option(strdup("delopts"), OPT_DELOPTS, $3); }; 
dest:           '(' DEST p ')'              { $$ = new_option(strdup("dest"), OPT_DEST, push(new_contxt(), $3)); }; 
disk:           '(' DISK ')'                { $$ = new_option(strdup("disk"), OPT_DISK, NULL); };
fail:           '(' FAIL ')'                { $$ = new_option(strdup("fail"), OPT_FAIL, NULL); };
files:          '(' FILES ')'               { $$ = new_option(strdup("files"), OPT_FILES, NULL); };
fonts:          '(' FONTS ')'               { $$ = new_option(strdup("fonts"), OPT_FONTS, NULL); };
force:          '(' FORCE ')'               { $$ = new_option(strdup("force"), OPT_FORCE, NULL); };
help:           '(' HELP ps ')'             { $$ = new_option(strdup("help"), OPT_HELP, $3); }; 
infos:          '(' INFOS ')'               { $$ = new_option(strdup("infos"), OPT_INFOS, NULL); };
include:        '(' INCLUDE p ')'           { $$ = new_option(strdup("include"), OPT_INCLUDE, push(new_contxt(), $3)); }; 
newname:        '(' NEWNAME p ')'           { $$ = new_option(strdup("newname"), OPT_NEWNAME, push(new_contxt(), $3)); }; 
newpath:        '(' NEWPATH ')'             { $$ = new_option(strdup("newpath"), OPT_NEWPATH, NULL); };
nofail:         '(' NOFAIL ')'              { $$ = new_option(strdup("nofail"), OPT_NOFAIL, NULL); };
nogauge:        '(' NOGAUGE ')'             { $$ = new_option(strdup("nogauge"), OPT_NOGAUGE, NULL); };
noposition:     '(' NOPOSITION ')'          { $$ = new_option(strdup("noposition"), OPT_NOPOSITION, NULL); };
noreq:          '(' NOREQ ')'               { $$ = new_option(strdup("noreq"), OPT_NOREQ, NULL); };
oknodelete:     '(' OKNODELETE ')'          { $$ = new_option(strdup("oknodelete"), OPT_OKNODELETE, NULL); };
pattern:        '(' PATTERN p ')'           { $$ = new_option(strdup("pattern"), OPT_PATTERN, push(new_contxt(), $3)); }; 
prompt:         '(' PROMPT ps ')'           { $$ = new_option(strdup("prompt"), OPT_PROMPT, $3); }; 
range:          '(' RANGE pp ')'            { $$ = new_option(strdup("range"), OPT_RANGE, $3); }; 
safe:           '(' SAFE ')'                { $$ = new_option(strdup("safe"), OPT_SAFE, NULL); };
setdefaulttool: '(' SETDEFAULTTOOL p ')'    { $$ = new_option(strdup("setdefaulttool"), OPT_SETDEFAULTTOOL, push(new_contxt(), $3)); }; 
setstack:       '(' SETSTACK p ')'          { $$ = new_option(strdup("setstack"), OPT_SETSTACK, push(new_contxt(), $3)); }; 
settooltype:    '(' SETTOOLTYPE pp ')'      { $$ = new_option(strdup("settooltype"), OPT_SETTOOLTYPE, $3); }; 
source:         '(' SOURCE p ')'            { $$ = new_option(strdup("source"), OPT_SOURCE, push(new_contxt(), $3)); }; 
swapcolors:     '(' SWAPCOLORS ')'          { $$ = new_option(strdup("swapcolors"), OPT_SWAPCOLORS, NULL); };
optional:       '(' OPTIONAL opts ')'       { $$ = new_option(strdup("optional"), OPT_OPTIONAL, $3); }; 
resident:       '(' RESIDENT ')'            { $$ = new_option(strdup("resident"), OPT_RESIDENT, NULL); };
%%

int main(int argc, char **argv)
{
    yyparse();
    leak_check();
}

