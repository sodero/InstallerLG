%{
//----------------------------------------------------------------------------
// parser.y: 
//
// InstallerNG parser
//----------------------------------------------------------------------------
// Copyright (C) 2018, Ola Söder. All rights reserved.
// Licensed under the AROS PUBLIC LICENSE (APL) Version 1.1
//----------------------------------------------------------------------------

#include "all.h"
#include "alloc.h"
#include "eval.h"
#include "init.h"
#include "lexer.h"

#include <string.h>
%}
/*----------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/* We need the parser to be reentrant, not */
/* because we want to, but because it will */
/* will leak memory otherwise.             */
%define api.pure full                                                                                            
%lex-param   { yyscan_t scanner }
%parse-param { yyscan_t scanner }
%expect 2
/*----------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/*- primitives ---------------------------------------------------------------------------------------------------------------------------------------------------------*/
%token<s> /* string pri. */ SYM STR 
%token<n> /* number pri. */ INT HEX BIN 
/*----------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/*- tokens -------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/*        arithmetic.c|h */ /* '+' '/' '*' '-' */
%token /* bitwise.c|h    */ AND BITAND BITNOT BITOR BITXOR NOT IN OR SHIFTLEFT SHIFTRIGHT XOR
%token /* comparison.c|h */ EQ GT GTE LT LTE NEQ
%token /* control.c|h    */ IF SELECT UNTIL WHILE
%token /* external.c|h   */ EXECUTE REXX RUN
%token /* exit.c|h       */ ABORT EXIT ONERROR TRAP
%token /* file.c|h       */ COPYFILES COPYLIB DELETE EXISTS FILEONLY FOREACH MAKEASSIGN MAKEDIR PROTECT 
       /*                */ STARTUP TEXTFILE TOOLTYPE TRANSCRIPT RENAME
%token /* information.c  */ COMPLETE DEBUG MESSAGE USER WELCOME WORKING 
%token /* probe.c|h      */ DATABASE EARLIER GETASSIGN GETDEVICE GETDISKSPACE GETENV GETSIZE GETSUM 
       /*                */ GETVERSION ICONINFO
%token /* procedure.c|h  */ CUS DCL
%token /* prompt.c|h     */ ASKBOOL ASKCHOICE ASKDIR ASKDISK ASKFILE ASKNUMBER ASKOPTIONS ASKSTRING
%token /* strop.c|h      */ CAT EXPANDPATH FMT PATHONLY PATMATCH STRLEN SUBSTR TACKON
%token /* symbol.c|h     */ SET SYMBOLSET SYMBOLVAL
%token /* options        */ ALL APPEND ASSIGNS CHOICES COMMAND COMPRESSION CONFIRM DEFAULT 
       /*                */ DELOPTS DEST DISK FILES FONTS GETDEFAULTTOOL GETPOSITION 
       /*                */ GETSTACK GETTOOLTYPE HELP INFOS INCLUDE NEWNAME NEWPATH NOGAUGE
       /*                */ NOPOSITION NOREQ PATTERN PROMPT QUIET RANGE SAFE 
       /*                */ SETDEFAULTTOOL SETPOSITION SETSTACK SETTOOLTYPE SOURCE SWAPCOLORS OPTIONAL 
       /*                */ RESIDENT OVERRIDE
/*----------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/*- token type information ---------------------------------------------------------------------------------------------------------------------------------------------*/
%type<e> /* all nodes    */ start s p pp ps pps ivp vp vps dynopt opt opts xpb xpbs np sps par cv cvv add sub
       /*                */ lt lte neq gt gte eq set cus dcl fmt if while until and or xor not bitand bitor 
       /*                */ bitxor bitnot shiftleft shiftright in strlen substr askdir askfile askstring 
       /*                */ asknumber askchoice askoptions askbool askdisk cat exists expandpath earlier 
       /*                */ fileonly getassign getdefaulttool getposition getstack gettooltype getdevice 
       /*                */ getdiskspace getenv getsize getsum getversion iconinfo pathonly patmatch div
       /*                */ select symbolset symbolval tackon transcript complete user working welcome 
       /*                */ abort copyfiles copylib database debug delete execute exit foreach makeassign 
       /*                */ makedir message onerror protect rename rexx run startup textfile tooltype
       /*                */ trap all append assigns choices command compression confirm default mul
       /*                */ delopts dest disk files fonts help infos include newname newpath optional 
       /*                */ nogauge noposition noreq pattern prompt quiet range safe resident override
       /*                */ setdefaulttool setposition setstack settooltype source swapcolors
/*----------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/*- destruction --------------------------------------------------------------------------------------------------------------------------------------------------------*/
/* Use the destructor of the start symbol to set of  */
/* the execution of the program.                     */
%destructor { run($$);  }   start 
/* Primitive strings are freed like you would expect */
%destructor { free($$); }   SYM STR
/* Complex types are freed using the kill() function */
/* found in alloc.c                                  */
%destructor { kill($$); }   s p pp ps pps ivp vp vps dynopt opt opts xpb xpbs np sps par cv cvv add sub div mul
                            gt gte eq set cus dcl fmt if while until and or xor not bitand bitor bitxor bitnot 
                            shiftleft shiftright in strlen substr askdir askfile askstring asknumber askchoice 
                            askoptions askbool askdisk exists expandpath earlier fileonly getassign pattern
                            getdefaulttool getposition getstack gettooltype optional resident override source
                            getdevice getdiskspace getenv getsize getsum getversion iconinfo pathonly patmatch 
                            select symbolset symbolval tackon transcript complete user working welcome abort 
                            copyfiles copylib database debug delete execute exit foreach makeassign makedir 
                            message onerror protect rename rexx run startup textfile tooltype trap all append 
                            assigns choices command compression confirm default delopts dest disk lt lte neq
                            files fonts help infos include newname newpath nogauge noposition settooltype cat 
                            noreq prompt quiet range safe setdefaulttool setposition setstack swapcolors
%%
/*----------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/*- start --------------------------------------------------------------------------------------------------------------------------------------------------------------*/
start:          s                               { $$ = init($1); };
s:              vps                             ;
/*----------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/*- phrase types -------------------------------------------------------------------------------------------------------------------------------------------------------*/
p:              vp                              |
                np                              ;
pp:             p p                             { $$ = push(push(new_contxt(), $1), $2); };
ps:             ps p                            { $$ = push($1, $2); } |
                p                               { $$ = push(new_contxt(), $1); };
pps:            pps p p                         { $$ = push(push($1, $2), $3); } |
                pp                              ;
vp:             ivp                             |
                '(' vp ')'                      { $$ = $2; };
vps:            vps vps                         { $$ = merge($1, $2); } |
                vp                              { $$ = push(new_contxt(), $1); } |
                '(' vps ')'                     { $$ = $2; };
opts:           opts opt                        { $$ = push($1, $2); } |
                opt                             { $$ = push(new_contxt(), $1); };
xpb:            '(' vps ')'                     { $$ = $2; } |
                '(' vps np ')'                  { $$ = push($2, $3); } |
                p                               { $$ = push(new_contxt(), $1); };
xpbs:           xpb                             { $$ = push(new_contxt(), $1); }|
                xpbs xpb                        { $$ = push($1, $2); };
np:             INT                             { $$ = new_number($1); } |
                HEX                             { $$ = new_number($1); } |
                BIN                             { $$ = new_number($1); } |
                STR                             { $$ = new_string($1); } |
                SYM                             { $$ = new_symref($1, LINE); };
sps:            sps SYM p                       { $$ = push(push($1, new_symbol($2)), $3) ; } |
                SYM p                           { $$ = push(push(new_contxt(), new_symbol($1)), $2); };
par:            par SYM                         { $$ = push($1, new_symbol($2)); } |
                SYM                             { $$ = push(new_contxt(), new_symbol($1)); };
cv:             p xpb                           { $$ = push(push(new_contxt(), $1), $2); };
cvv:            p xpb xpb                       { $$ = push(push(push(new_contxt(), $1), $2), $3); };
/*----------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/*- modifiers ----------------------------------------------------------------------------------------------------------------------------------------------------------*/
opt:            all                             |            
                append                          |         
                assigns                         |        
                choices                         |        
                command                         |        
                compression                     |        
                confirm                         |        
                default                         |        
                delopts                         |        
                dest                            |           
                disk                            |           
                files                           |          
                fonts                           |          
                getdefaulttool                  |
                getposition                     |
                getstack                        |
                gettooltype                     | 
                help                            |           
                include                         |        
                infos                           |          
                newname                         |        
                newpath                         |        
                nogauge                         |        
                noposition                      |     
                noreq                           |     
                optional                        |       
                override                        |
                pattern                         |        
                prompt                          |         
                quiet                           |         
                range                           |          
                safe                            |           
                setdefaulttool                  | 
                setposition                     | 
                setstack                        |       
                settooltype                     |    
                source                          |         
                swapcolors                      |     
                dynopt                          |
                resident                        ;
/*----------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/*- functions ----------------------------------------------------------------------------------------------------------------------------------------------------------*/
ivp:            add       /* arithmetic.c|h */  |
                div                             |
                mul                             |
                sub                             |
                and       /* bitwise.c|h */     |
                bitand                          |
                bitnot                          |
                bitor                           |
                bitxor                          |
                not                             |
                in                              | 
                or                              |
                shiftleft                       | 
                shiftright                      |
                xor                             |
                eq        /* comparison.c|h */  |
                gt                              |
                gte                             |
                lt                              |
                lte                             |
                neq                             |
                if        /* control.c|h */     |
                select                          |
                until                           |
                while                           |
                execute   /* external.c|h */    |
                rexx                            |
                run                             |
                abort     /* exit.c|h */        |
                exit                            |
                onerror                         |
                trap                            |
                copyfiles /* file.c|h */        |
                copylib                         |
                delete                          |
                exists                          |
                fileonly                        |
                foreach                         |
                makeassign                      |
                makedir                         |
                protect                         |
                startup                         |
                textfile                        |
                tooltype                        |
                transcript                      |
                rename                          |
                complete  /* information.c|h */ |
                debug                           |
                message                         |
                user                            |
                welcome                         |
                working                         |
                database  /* probe.c|h */       |
                earlier                         |
                getassign                       |
                getdevice                       |
                getdiskspace                    |
                getenv                          |
                getsize                         |
                getsum                          |
                getversion                      |
                iconinfo                        |
                cus       /* procedure.c|h */   |
                dcl                             |
                askbool   /* prompt.c|h */      |
                askchoice                       |
                askdir                          |
                askdisk                         |
                askfile                         |
                asknumber                       |
                askoptions                      |
                askstring                       |
                cat       /* strop.c|h */       |
                expandpath                      |
                fmt                             |
                pathonly                        |
                patmatch                        |
                strlen                          | 
                substr                          | 
                tackon                          |
                set       /* symbol.c|h */      |
                symbolset                       |
                symbolval                       ;
/*----------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/* arithmetic.c|h ------------------------------------------------------------------------------------------------------------------------------------------------------*/
add:            '(' '+' ps ')'                  { $$ = new_native(strdup("+"), LINE, m_add, $3, NUMBER); };
div:            '(' '/' pp ')'                  { $$ = new_native(strdup("/"), LINE, m_div, $3, NUMBER); };
mul:            '(' '*' ps ')'                  { $$ = new_native(strdup("*"), LINE, m_mul, $3, NUMBER); };
sub:            '(' '-' pp ')'                  { $$ = new_native(strdup("-"), LINE, m_sub, $3, NUMBER); };
/*----------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/* bitwise.c|h ---------------------------------------------------------------------------------------------------------------------------------------------------------*/
and:            '(' AND ps ')'                  { $$ = new_native(strdup("AND"), LINE, m_and, $3, NUMBER); }; 
bitand:         '(' BITAND pp ')'               { $$ = new_native(strdup("BITAND"), LINE, m_bitand, $3, NUMBER); }; 
bitnot:         '(' BITNOT p ')'                { $$ = new_native(strdup("BITNOT"), LINE, m_bitnot, push(new_contxt(), $3), NUMBER); }; 
bitor:          '(' BITOR pp ')'                { $$ = new_native(strdup("BITOR"), LINE, m_bitor, $3, NUMBER); }; 
bitxor:         '(' BITXOR pp ')'               { $$ = new_native(strdup("BITXOR"), LINE, m_bitxor, $3, NUMBER); }; 
not:            '(' NOT p ')'                   { $$ = new_native(strdup("NOT"), LINE, m_not, push(new_contxt(), $3), NUMBER); }; 
in:             '(' IN p ps ')'                 { $$ = new_native(strdup("IN"), LINE, m_in, push(push(new_contxt(), $3), $4), NUMBER); }; 
or:             '(' OR ps ')'                   { $$ = new_native(strdup("OR"), LINE, m_or, $3, NUMBER); }; 
shiftleft:      '(' SHIFTLEFT pp ')'            { $$ = new_native(strdup("shiftleft"), LINE, m_shiftleft, $3, NUMBER); }; 
shiftright:     '(' SHIFTRIGHT pp ')'           { $$ = new_native(strdup("shiftright"), LINE, m_shiftright, $3, NUMBER); }; 
xor:            '(' XOR pp ')'                  { $$ = new_native(strdup("XOR"), LINE, m_xor, $3, NUMBER); }; 
/*----------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/* comparison.c|h ------------------------------------------------------------------------------------------------------------------------------------------------------*/
eq:             '(' '=' pp ')'                  { $$ = new_native(strdup("="), LINE, m_eq, $3, NUMBER); };
gt:             '(' '>' pp ')'                  { $$ = new_native(strdup(">"), LINE, m_gt, $3, NUMBER); };
gte:            '(' GTE pp ')'                  { $$ = new_native(strdup(">="), LINE, m_gte, $3, NUMBER); };
lt:             '(' '<' pp ')'                  { $$ = new_native(strdup("<"), LINE, m_lt, $3, NUMBER); };
lte:            '(' LTE pp ')'                  { $$ = new_native(strdup("<="), LINE, m_lte, $3, NUMBER); };
neq:            '(' NEQ pp ')'                  { $$ = new_native(strdup("<>"), LINE, m_neq, $3, NUMBER); };
/*----------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/* control.c|h ---------------------------------------------------------------------------------------------------------------------------------------------------------*/
if:             '(' IF cvv ')'                  { $$ = new_native(strdup("if"), LINE, m_if, $3, NUMBER); } |
                '(' IF cv ')'                   { $$ = new_native(strdup("if"), LINE, m_if, $3, NUMBER); } |
                '(' IF p ')'                    { $$ = new_native(strdup("if"), LINE, m_if, push(new_contxt(), $3), NUMBER); };
select:         '(' SELECT p xpbs ')'           { $$ = new_native(strdup("select"), LINE, m_select, push(push(new_contxt(), $3), $4), NUMBER); }; 
until:          '(' UNTIL p vps ')'             { $$ = new_native(strdup("until"), LINE, m_until, push(push(new_contxt(), $3), $4), NUMBER); };
while:          '(' WHILE p vps ')'             { $$ = new_native(strdup("while"), LINE, m_while, push(push(new_contxt(), $3), $4), NUMBER); };
/*----------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/* external.c|h --------------------------------------------------------------------------------------------------------------------------------------------------------*/
execute:        '(' EXECUTE ps opts ')'         { $$ = new_native(strdup("execute"), LINE, m_execute, push($3, $4), NUMBER); } | 
                '(' EXECUTE opts ps ')'         { $$ = new_native(strdup("execute"), LINE, m_execute, push($4, $3), NUMBER); } | 
                '(' EXECUTE opts ps opts ')'    { $$ = new_native(strdup("execute"), LINE, m_execute, push(push($4, $3), $5), NUMBER); } |
                '(' EXECUTE ps ')'              { $$ = new_native(strdup("execute"), LINE, m_execute, $3, NUMBER); }; 
rexx:           '(' REXX ps opts ')'            { $$ = new_native(strdup("rexx"), LINE, m_rexx, push($3, $4), NUMBER); } |
                '(' REXX opts ps ')'            { $$ = new_native(strdup("rexx"), LINE, m_rexx, push($4, $3), NUMBER); } |
                '(' REXX opts ps opts ')'       { $$ = new_native(strdup("rexx"), LINE, m_rexx, push(push($4, $3), $5), NUMBER); } |
                '(' REXX ps ')'                 { $$ = new_native(strdup("rexx"), LINE, m_rexx, $3, NUMBER); };
run:            '(' RUN ps opts ')'             { $$ = new_native(strdup("run"), LINE, m_run, push($3, $4), NUMBER); } |
                '(' RUN opts ps ')'             { $$ = new_native(strdup("run"), LINE, m_run, push($4, $3), NUMBER); } |
                '(' RUN opts ps opts ')'        { $$ = new_native(strdup("run"), LINE, m_run, push(push($4, $3), $5), NUMBER); } |
                '(' RUN ps ')'                  { $$ = new_native(strdup("run"), LINE, m_run, $3, NUMBER); };
/*----------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/* exit.c|h ------------------------------------------------------------------------------------------------------------------------------------------------------------*/
abort:          '(' ABORT ps ')'                { $$ = new_native(strdup("abort"), LINE, m_abort, $3, NUMBER); }; 
exit:           '(' EXIT ps quiet ')'           { $$ = new_native(strdup("exit"), LINE, m_exit, push($3, $4), NUMBER); } | 
                '(' EXIT quiet ps ')'           { $$ = new_native(strdup("exit"), LINE, m_exit, push($4, $3), NUMBER); } | 
                '(' EXIT quiet')'               { $$ = new_native(strdup("exit"), LINE, m_exit, push(new_contxt(), $3), NUMBER); } |
                '(' EXIT ps ')'                 { $$ = new_native(strdup("exit"), LINE, m_exit, $3, NUMBER); } |
                '(' EXIT ')'                    { $$ = new_native(strdup("exit"), LINE, m_exit, NULL, NUMBER); }; 
onerror:        '(' ONERROR vps ')'             { $$ = new_native(strdup("onerror"), LINE, m_procedure, push(new_contxt(), 
                                                       new_custom(strdup("@onerror"), LINE, NULL, $3)), DANGLE); };
trap:           '(' TRAP p vps ')'              { $$ = new_native(strdup("trap"), LINE, m_trap, push(push(new_contxt(), $3), $4), NUMBER); };
/*----------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/* file.c|h ------------------------------------------------------------------------------------------------------------------------------------------------------------*/
copyfiles:      '(' COPYFILES opts ')'          { $$ = new_native(strdup("copyfiles"), LINE, m_copyfiles, $3, NUMBER); }; 
copylib:        '(' COPYLIB opts ')'            { $$ = new_native(strdup("copylib"), LINE, m_copylib, $3, NUMBER); }; 
delete:         '(' DELETE p opts')'            { $$ = new_native(strdup("delete"), LINE, m_delete, push(push(new_contxt(), $3), $4), NUMBER); } | 
                '(' DELETE opts p')'            { $$ = new_native(strdup("delete"), LINE, m_delete, push(push(new_contxt(), $4), $3), NUMBER); } | 
                '(' DELETE opts p opts ')'      { $$ = new_native(strdup("delete"), LINE, m_delete, push(push(push(new_contxt(), $4), $3), $5), NUMBER); } |
                '(' DELETE p ')'                { $$ = new_native(strdup("delete"), LINE, m_delete, push(new_contxt(), $3), NUMBER); }; 
exists:         '(' EXISTS p ')'                { $$ = new_native(strdup("exists"), LINE, m_exists, push(new_contxt(), $3), NUMBER); } |
                '(' EXISTS p noreq ')'          { $$ = new_native(strdup("exists"), LINE, m_exists, push(push(new_contxt(), $3), $4), NUMBER); }; 
fileonly:       '(' FILEONLY p ')'              { $$ = new_native(strdup("fileonly"), LINE, m_fileonly, push(new_contxt(), $3), STRING); }; 
foreach:        '(' FOREACH pp vps ')'          { $$ = new_native(strdup("foreach"), LINE, m_foreach, push($3, $4), NUMBER); };
makeassign:     '(' MAKEASSIGN pp safe ')'      { $$ = new_native(strdup("makeassign"), LINE, m_makeassign, push($3, $4), NUMBER); } | 
                '(' MAKEASSIGN pp ')'           { $$ = new_native(strdup("makeassign"), LINE, m_makeassign, $3, NUMBER); } | 
                '(' MAKEASSIGN p safe ')'       { $$ = new_native(strdup("makeassign"), LINE, m_makeassign, push(push(new_contxt(), $3), $4), NUMBER); } | 
                '(' MAKEASSIGN p ')'            { $$ = new_native(strdup("makeassign"), LINE, m_makeassign, push(new_contxt(), $3), NUMBER); };
makedir:        '(' MAKEDIR p opts')'           { $$ = new_native(strdup("makedir"), LINE, m_makedir, push(push(new_contxt(), $3), $4), NUMBER); } | 
                '(' MAKEDIR opts p ')'          { $$ = new_native(strdup("makedir"), LINE, m_makedir, push(push(new_contxt(), $4), $3), NUMBER); } | 
                '(' MAKEDIR opts p opts ')'     { $$ = new_native(strdup("makedir"), LINE, m_makedir, push(push(push(new_contxt(), $4), $3), $5), NUMBER); } |
                '(' MAKEDIR p ')'               { $$ = new_native(strdup("makedir"), LINE, m_makedir, push(new_contxt(), $3), NUMBER); }; 
protect:        '(' PROTECT pp opts ')'         { $$ = new_native(strdup("protect"), LINE, m_protect, push($3, $4), NUMBER); } | 
                '(' PROTECT pp ')'              { $$ = new_native(strdup("protect"), LINE, m_protect, $3, NUMBER); } |
                '(' PROTECT p opts ')'          { $$ = new_native(strdup("protect"), LINE, m_protect, push(push(new_contxt(), $3), $4), NUMBER); } | 
                '(' PROTECT p ')'               { $$ = new_native(strdup("protect"), LINE, m_protect, push(new_contxt(), $3), NUMBER); };
startup:        '(' STARTUP p opts ')'          { $$ = new_native(strdup("startup"), LINE, m_startup, push(push(new_contxt(), $3), $4), NUMBER); } |
                '(' STARTUP opts p ')'          { $$ = new_native(strdup("startup"), LINE, m_startup, push(push(new_contxt(), $4), $3), NUMBER); } |
                '(' STARTUP opts p opts ')'     { $$ = new_native(strdup("startup"), LINE, m_startup, push(push(push(new_contxt(), $4), $3), $5), NUMBER); };
textfile:       '(' TEXTFILE opts ')'           { $$ = new_native(strdup("textfile"), LINE, m_textfile, $3, NUMBER); }; 
tooltype:       '(' TOOLTYPE opts ')'           { $$ = new_native(strdup("tooltype"), LINE, m_tooltype, $3, NUMBER); }; 
transcript:     '(' TRANSCRIPT ps ')'           { $$ = new_native(strdup("transcript"), LINE, m_transcript, $3, NUMBER); }; 
rename:         '(' RENAME pp opts')'           { $$ = new_native(strdup("rename"), LINE, m_rename, push($3, $4), NUMBER); } | 
                '(' RENAME pp ')'               { $$ = new_native(strdup("rename"), LINE, m_rename, $3, NUMBER); }; 
/*----------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/* information.c|h -----------------------------------------------------------------------------------------------------------------------------------------------------*/
complete:       '(' COMPLETE p ')'              { $$ = new_native(strdup("complete"), LINE, m_complete, push(new_contxt(), $3), NUMBER); }; 
debug:          '(' DEBUG ps ')'                { $$ = new_native(strdup("debug"), LINE, m_debug, $3, NUMBER); }; 
message:        '(' MESSAGE ps all ')'          { $$ = new_native(strdup("message"), LINE, m_message, push($3, $4), NUMBER); } | 
                '(' MESSAGE ps ')'              { $$ = new_native(strdup("message"), LINE, m_message, $3, NUMBER); };
user:           '(' USER p ')'                  { $$ = new_native(strdup("user"), LINE, m_user, push(new_contxt(), $3), NUMBER); };
welcome:        '(' WELCOME ps ')'              { $$ = new_native(strdup("welcome"), LINE, m_welcome, $3, NUMBER); } |
                '(' WELCOME ')'                 { $$ = new_native(strdup("welcome"), LINE, m_welcome, NULL, NUMBER); }; 
working:        '(' WORKING ps ')'              { $$ = new_native(strdup("working"), LINE, m_working, $3, NUMBER); }; 
/*----------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/* probe.c|h -----------------------------------------------------------------------------------------------------------------------------------------------------------*/
database:       '(' DATABASE p ')'              { $$ = new_native(strdup("database"), LINE, m_database, push(new_contxt(), $3), STRING); } | 
                '(' DATABASE pp ')'             { $$ = new_native(strdup("database"), LINE, m_database, $3, STRING); }; 
earlier:        '(' EARLIER pp ')'              { $$ = new_native(strdup("earlier"), LINE, m_earlier, $3, NUMBER); }; 
getassign:      '(' GETASSIGN p ')'             { $$ = new_native(strdup("getassign"), LINE, m_getassign, push(new_contxt(), $3), STRING); } |
                '(' GETASSIGN pp ')'            { $$ = new_native(strdup("getassign"), LINE, m_getassign, $3, STRING); }; 
getdevice:      '(' GETDEVICE p ')'             { $$ = new_native(strdup("getdevice"), LINE, m_getdevice, push(new_contxt(), $3), STRING); }; 
getdiskspace:   '(' GETDISKSPACE p ')'          { $$ = new_native(strdup("getdiskspace"), LINE, m_getdiskspace, push(new_contxt(), $3), NUMBER); }; 
getenv:         '(' GETENV p ')'                { $$ = new_native(strdup("getenv"), LINE, m_getenv, push(new_contxt(), $3), STRING); }; 
getsize:        '(' GETSIZE p ')'               { $$ = new_native(strdup("getsize"), LINE, m_getsize, push(new_contxt(), $3), NUMBER); }; 
getsum:         '(' GETSUM p ')'                { $$ = new_native(strdup("getsum"), LINE, m_getsum, push(new_contxt(), $3), NUMBER); }; 
getversion:     '(' GETVERSION ')'              { $$ = new_native(strdup("getversion"), LINE, m_getversion, NULL, NUMBER); } |
                '(' GETVERSION p ')'            { $$ = new_native(strdup("getversion"), LINE, m_getversion, push(new_contxt(), $3), NUMBER); } |
                '(' GETVERSION p resident ')'   { $$ = new_native(strdup("getversion"), LINE, m_getversion, push(push(new_contxt(), $3), $4), NUMBER); }; 
iconinfo:       '(' ICONINFO opts ')'           { $$ = new_native(strdup("iconinfo"), LINE, m_iconinfo, $3, NUMBER); }; 
/*----------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/* procedure.c|h -------------------------------------------------------------------------------------------------------------------------------------------------------*/
dcl:            '(' DCL SYM par s ')'           { $$ = new_native(strdup("procedure"), LINE, m_procedure, push(new_contxt(), new_custom($3, LINE, $4, $5)), NUMBER); } |
                '(' DCL SYM par ')'             { $$ = new_native(strdup("procedure"), LINE, m_procedure, push(new_contxt(), new_custom($3, LINE, $4, NULL)), NUMBER); } |
                '(' DCL SYM s ')'               { $$ = new_native(strdup("procedure"), LINE, m_procedure, push(new_contxt(), new_custom($3, LINE, NULL, $4)), NUMBER); } |
                '(' DCL SYM ')'                 { $$ = new_native(strdup("procedure"), LINE, m_procedure, push(new_contxt(), new_custom($3, LINE, NULL, NULL)), NUMBER); };
cus:            '(' SYM ps ')'                  { $$ = new_cusref($2, LINE, $3); } |
                '(' SYM ')'                     { $$ = new_cusref($2, LINE, NULL); };
/*----------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/* prompt.c|h ----------------------------------------------------------------------------------------------------------------------------------------------------------*/
askbool:        '(' ASKBOOL ')'                 { $$ = new_native(strdup("askbool"), LINE, m_askbool, NULL, NUMBER); };
askbool:        '(' ASKBOOL opts ')'            { $$ = new_native(strdup("askbool"), LINE, m_askbool, $3, NUMBER); };
askchoice:      '(' ASKCHOICE opts ')'          { $$ = new_native(strdup("askchoice"), LINE, m_askchoice, $3, NUMBER); };
askdir:         '(' ASKDIR ')'                  { $$ = new_native(strdup("askdir"), LINE, m_askdir, NULL, STRING); };
askdir:         '(' ASKDIR opts ')'             { $$ = new_native(strdup("askdir"), LINE, m_askdir, $3, STRING); };
askdisk:        '(' ASKDISK opts ')'            { $$ = new_native(strdup("askdisk"), LINE, m_askdisk, $3, NUMBER); };
askfile:        '(' ASKFILE ')'                 { $$ = new_native(strdup("askfile"), LINE, m_askfile, NULL, STRING); };
askfile:        '(' ASKFILE opts ')'            { $$ = new_native(strdup("askfile"), LINE, m_askfile, $3, STRING); };
asknumber:      '(' ASKNUMBER ')'               { $$ = new_native(strdup("asknumber"), LINE, m_asknumber, NULL, NUMBER); };
asknumber:      '(' ASKNUMBER opts ')'          { $$ = new_native(strdup("asknumber"), LINE, m_asknumber, $3, NUMBER); };
askoptions:     '(' ASKOPTIONS opts ')'         { $$ = new_native(strdup("askoptions"), LINE, m_askoptions, $3, NUMBER); };
askstring:      '(' ASKSTRING ')'               { $$ = new_native(strdup("askstring"), LINE, m_askstring, NULL, STRING); };
askstring:      '(' ASKSTRING opts ')'          { $$ = new_native(strdup("askstring"), LINE, m_askstring, $3, STRING); };
/*----------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/* strop.c|h -----------------------------------------------------------------------------------------------------------------------------------------------------------*/
cat:            '(' CAT ps ')'                  { $$ = new_native(strdup("cat"), LINE, m_cat, $3, STRING); };
expandpath:     '(' EXPANDPATH p ')'            { $$ = new_native(strdup("expandpath"), LINE, m_expandpath, push(new_contxt(), $3), STRING); }; 
fmt:            '(' STR ps ')'                  { $$ = new_native($2, LINE, m_fmt, $3, STRING); } |
                '(' STR ')'                     { $$ = new_native($2, LINE, m_fmt, NULL, STRING); };
pathonly:       '(' PATHONLY p ')'              { $$ = new_native(strdup("pathonly"), LINE, m_pathonly, push(new_contxt(), $3), STRING); }; 
patmatch:       '(' PATMATCH pp ')'             { $$ = new_native(strdup("patmatch"), LINE, m_patmatch, $3, NUMBER); }; 
strlen:         '(' STRLEN p ')'                { $$ = new_native(strdup("strlen"), LINE, m_strlen, push(new_contxt(), $3), NUMBER); }; 
substr:         '(' SUBSTR pp ')'               { $$ = new_native(strdup("substr"), LINE, m_substr, $3, STRING); } |
                '(' SUBSTR pp p ')'             { $$ = new_native(strdup("substr"), LINE, m_substr, push($3, $4), STRING); };
tackon:         '(' TACKON pp ')'               { $$ = new_native(strdup("tackon"), LINE, m_tackon, $3, STRING); }; 
/*----------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/* symbol.c|h ----------------------------------------------------------------------------------------------------------------------------------------------------------*/
set:            '(' SET sps ')'                 { $$ = new_native(strdup("set"), LINE, m_set, $3, DANGLE); };
symbolset:      '(' SYMBOLSET pps ')'           { $$ = new_native(strdup("symbolset"), LINE, m_symbolset, $3, DANGLE); }; 
symbolval:      '(' SYMBOLVAL p ')'             { $$ = new_native(strdup("symbolval"), LINE, m_symbolval, push(new_contxt(), $3), NUMBER); }; 
/*----------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/*- options ------------------------------------------------------------------------------------------------------------------------------------------------------------*/
all:            '(' ALL ')'                     { $$ = new_option(strdup("all"), OPT_ALL, NULL); };
append:         '(' APPEND ps ')'               { $$ = new_option(strdup("append"), OPT_APPEND, $3); }; 
assigns:        '(' ASSIGNS ')'                 { $$ = new_option(strdup("assigns"), OPT_ASSIGNS, NULL); };
choices:        '(' CHOICES ps ')'              { $$ = new_option(strdup("choices"), OPT_CHOICES, $3); }; 
command:        '(' COMMAND ps ')'              { $$ = new_option(strdup("command"), OPT_COMMAND, $3); }; 
compression:    '(' COMPRESSION ')'             { $$ = new_option(strdup("compression"), OPT_COMPRESSION, NULL); };
confirm:        '(' CONFIRM p ')'               { $$ = new_option(strdup("confirm"), OPT_CONFIRM, push(new_contxt(), $3)); } |
                '(' CONFIRM ')'                 { $$ = new_option(strdup("confirm"), OPT_CONFIRM, NULL); };
default:        '(' DEFAULT p ')'               { $$ = new_option(strdup("default"), OPT_DEFAULT, push(new_contxt(), $3)); }; 
delopts:        '(' DELOPTS ps ')'              { $$ = new_option(strdup("delopts"), OPT_DELOPTS, $3); }; 
dest:           '(' DEST p ')'                  { $$ = new_option(strdup("dest"), OPT_DEST, push(new_contxt(), $3)); }; 
disk:           '(' DISK ')'                    { $$ = new_option(strdup("disk"), OPT_DISK, NULL); };
files:          '(' FILES ')'                   { $$ = new_option(strdup("files"), OPT_FILES, NULL); };
fonts:          '(' FONTS ')'                   { $$ = new_option(strdup("fonts"), OPT_FONTS, NULL); };
getdefaulttool: '(' GETDEFAULTTOOL p ')'        { $$ = new_option(strdup("getdefaulttool"), OPT_GETDEFAULTTOOL, push(new_contxt(), $3)); };
getposition:    '(' GETPOSITION pp ')'          { $$ = new_option(strdup("getposition"), OPT_GETPOSITION, $3); }; 
getstack:       '(' GETSTACK p ')'              { $$ = new_option(strdup("getstack"), OPT_GETSTACK, push(new_contxt(), $3)); };
gettooltype:    '(' GETTOOLTYPE pp ')'          { $$ = new_option(strdup("gettooltype"), OPT_GETTOOLTYPE, $3); };
help:           '(' HELP ps ')'                 { $$ = new_option(strdup("help"), OPT_HELP, $3); }; 
infos:          '(' INFOS ')'                   { $$ = new_option(strdup("infos"), OPT_INFOS, NULL); };
include:        '(' INCLUDE p ')'               { $$ = new_option(strdup("include"), OPT_INCLUDE, push(new_contxt(), $3)); }; 
newname:        '(' NEWNAME p ')'               { $$ = new_option(strdup("newname"), OPT_NEWNAME, push(new_contxt(), $3)); }; 
newpath:        '(' NEWPATH ')'                 { $$ = new_option(strdup("newpath"), OPT_NEWPATH, NULL); };
nogauge:        '(' NOGAUGE ')'                 { $$ = new_option(strdup("nogauge"), OPT_NOGAUGE, NULL); };
noposition:     '(' NOPOSITION ')'              { $$ = new_option(strdup("noposition"), OPT_NOPOSITION, NULL); };
noreq:          '(' NOREQ ')'                   { $$ = new_option(strdup("noreq"), OPT_NOREQ, NULL); };
pattern:        '(' PATTERN p ')'               { $$ = new_option(strdup("pattern"), OPT_PATTERN, push(new_contxt(), $3)); }; 
prompt:         '(' PROMPT ps ')'               { $$ = new_option(strdup("prompt"), OPT_PROMPT, $3); }; 
quiet:          '(' QUIET ')'                   { $$ = new_option(strdup("quiet"), OPT_QUIET, NULL); };
range:          '(' RANGE pp ')'                { $$ = new_option(strdup("range"), OPT_RANGE, $3); }; 
safe:           '(' SAFE ')'                    { $$ = new_option(strdup("safe"), OPT_SAFE, NULL); };
setdefaulttool: '(' SETDEFAULTTOOL p ')'        { $$ = new_option(strdup("setdefaulttool"), OPT_SETDEFAULTTOOL, push(new_contxt(), $3)); }; 
setposition:    '(' SETPOSITION pp ')'          { $$ = new_option(strdup("setposition"), OPT_SETPOSITION, $3); }; 
setstack:       '(' SETSTACK p ')'              { $$ = new_option(strdup("setstack"), OPT_SETSTACK, push(new_contxt(), $3)); }; 
settooltype:    '(' SETTOOLTYPE pp ')'          { $$ = new_option(strdup("settooltype"), OPT_SETTOOLTYPE, $3); } |
                '(' SETTOOLTYPE p ')'           { $$ = new_option(strdup("settooltype"), OPT_SETTOOLTYPE, push(new_contxt(), $3)); }; 
source:         '(' SOURCE p ')'                { $$ = new_option(strdup("source"), OPT_SOURCE, push(new_contxt(), $3)); }; 
swapcolors:     '(' SWAPCOLORS ')'              { $$ = new_option(strdup("swapcolors"), OPT_SWAPCOLORS, NULL); };
optional:       '(' OPTIONAL ps ')'             { $$ = new_option(strdup("optional"), OPT_OPTIONAL, $3); }; 
resident:       '(' RESIDENT ')'                { $$ = new_option(strdup("resident"), OPT_RESIDENT, NULL); };
override:       '(' OVERRIDE p ')'              { $$ = new_option(strdup("override"), OPT_OVERRIDE, push(new_contxt(), $3)); }; 
dynopt:         '(' IF p opt opt ')'            { $$ = new_option(strdup("dynopt"), OPT_DYNOPT, push(push(push(new_contxt(), $3), $4), $5)); };
/*----------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
%%

