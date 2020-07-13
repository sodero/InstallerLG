%{
/*--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/* parser.y:                                                                                                                                                                            */
/*                                                                                                                                                                                      */
/* InstallerLG parser                                                                                                                                                                   */
/*--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/* Copyright (C) 2018-2020, Ola Söder. All rights reserved.                                                                                                                             */
/* Licensed under the AROS PUBLIC LICENSE (APL) Version 1.1                                                                                                                             */
/*--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

#include "all.h"
#include "alloc.h"
#include "eval.h"
#include "init.h"
#include "lexer.h"

#include <string.h>

/*--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/* Always debug.                                                                                                                                                                        */
/*--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
#define YYDEBUG 1
%}

/*--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/* Enable verbose error messages.                                                                                                                                                      */
/*--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
%define parse.error verbose

/*--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/* We need the parser to be reentrant. It will leak memory otherwise.                                                                                                                   */
/*--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
%define api.pure full
%lex-param   { yyscan_t scanner }
%parse-param { yyscan_t scanner }
%expect 8
/*--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/* Primitives                                                                                                                                                                           */
/*--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
%token<s> /* string pri. */ SYM STR OOM
%token<n> /* number pri. */ INT HEX BIN
/*--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/* Tokens                                                                                                                                                                               */
/*--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/*        arithmetic.c|h */ /* '+' '/' '*' '-' */
%token /* comparison.c|h */ EQ GT GTE LT LTE NEQ
%token /* control.c|h    */ IF SELECT UNTIL WHILE TRACE RETRACE
%token /* debug.c|h      */ ASTRAW ASBRAW ASBEVAL EVAL OPTIONS
%token /* external.c|h   */ EXECUTE REXX RUN
%token /* exit.c|h       */ ABORT EXIT ONERROR TRAP REBOOT
%token /* file.c|h       */ COPYFILES COPYLIB DELETE EXISTS FILEONLY FOREACH MAKEASSIGN MAKEDIR PROTECT STARTUP TEXTFILE TOOLTYPE TRANSCRIPT RENAME
%token /* information.c  */ COMPLETE DEBUG MESSAGE USER WELCOME WORKING
%token /* logic.c|h      */ AND BITAND BITNOT BITOR BITXOR NOT IN OR SHIFTLEFT SHIFTRIGHT XOR
%token /* media.c        */ CLOSEMEDIA EFFECT SETMEDIA SHOWMEDIA
%token /* probe.c|h      */ DATABASE EARLIER GETASSIGN GETDEVICE GETDISKSPACE GETENV GETSIZE GETSUM GETVERSION ICONINFO QUERYDISPLAY
%token /* procedure.c|h  */ CUS DCL
%token /* prompt.c|h     */ ASKBOOL ASKCHOICE ASKDIR ASKDISK ASKFILE ASKNUMBER ASKOPTIONS ASKSTRING
%token /* strop.c|h      */ CAT EXPANDPATH FMT PATHONLY PATMATCH STRLEN SUBSTR TACKON
%token /* symbol.c|h     */ SET SYMBOLSET SYMBOLVAL
%token /* wb.c|h         */ OPENWBOBJECT SHOWWBOBJECT CLOSEWBOBJECT
%token /* options        */ ALL APPEND ASSIGNS BACK CHOICES COMMAND COMPRESSION CONFIRM DEFAULT DELOPTS DEST DISK FILES FONTS GETDEFAULTTOOL GETPOSITION GETSTACK GETTOOLTYPE HELP INFOS
       /*                */ INCLUDE NEWNAME NEWPATH NOGAUGE NOPOSITION NOREQ PATTERN PROMPT QUIET RANGE SAFE SETDEFAULTTOOL SETPOSITION SETSTACK SETTOOLTYPE SOURCE SWAPCOLORS OPTIONAL
       /*                */ RESIDENT OVERRIDE
/*--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/* Token data types                                                                                                                                                                     */
/*--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
%type<e> /* all nodes    */ start s p pp ps pps ivp vp vps dynopt opt opts xpb xpbs np sps par cv cvv add sub lt lte neq gt gte eq set cus dcl fmt if while until and or xor not bitand
       /*                */ bitor bitxor bitnot shiftleft shiftright in strlen substr askdir askfile askstring asknumber askchoice askoptions askbool askdisk cat exists expandpath
       /*                */ earlier fileonly getassign getdefaulttool getposition getstack gettooltype getdevice getdiskspace getenv getsize getsum getversion iconinfo querydisplay
       /*                */ pathonly patmatch div select symbolset symbolval tackon transcript complete user working welcome abort copyfiles copylib database debug delete execute exit
       /*                */ foreach makeassign makedir message onerror protect rename rexx run startup textfile tooltype trap reboot all append assigns choices command compression
       /*                */ confirm default mul delopts dest disk files fonts help infos include newname newpath optional back nogauge noposition noreq pattern prompt quiet range safe
       /*                */ resident override setdefaulttool setposition setstack settooltype source swapcolors openwbobject showwbobject closewbobject trace retrace closemedia effect
       /*                */ setmedia showmedia astraw options asbraw asbeval eval
/*--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/* Destruction                                                                                                                                                                          */
/*--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/* Use the destructor of the start symbol to set of the execution of the program.                                                                                                       */
%destructor { run($$);  }   start
/* Primitive strings are freed like you would expect                                                                                                                                    */
%destructor { free($$); }   SYM STR
/* Complex types are freed using the kill() function found in alloc.c                                                                                                                   */
%destructor { kill($$); }   s p pp ps pps ivp vp vps dynopt opt opts xpb xpbs np sps par cv cvv add sub div mul gt gte eq set cus dcl fmt if while until and or xor not bitand bitor
                            bitxor bitnot shiftleft shiftright in strlen substr askdir askfile askstring asknumber askchoice askoptions askbool askdisk exists expandpath earlier
                            fileonly getassign pattern getdefaulttool getposition getstack gettooltype optional resident override source getdevice getdiskspace getenv getsize getsum
                            getversion iconinfo querydisplay pathonly patmatch select symbolset symbolval tackon transcript complete user working welcome abort copyfiles copylib
                            database debug delete execute exit foreach makeassign makedir message onerror protect rename rexx run startup textfile tooltype trap reboot all assigns
                            choices command compression confirm default delopts dest disk lt lte neq files fonts help infos include newname newpath nogauge noposition settooltype cat
                            noreq prompt quiet range safe setdefaulttool setposition setstack swapcolors append openwbobject showwbobject closewbobject trace retrace back closemedia
                            effect setmedia showmedia astraw options asbraw asbeval eval
%%
/*--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/* Start                                                                                                                                                                                */
/*--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
start:          s                                { $$ = init($1); };
s:              vps                              ;
/*--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/* Phrase types                                                                                                                                                                         */
/*--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
p:              vp                               |
                np                               ;
pp:             p p                              { $$ = push(push(new_contxt(), $1), $2); };
ps:             ps p                             { $$ = push($1, $2); } |
                p                                { $$ = push(new_contxt(), $1); };
pps:            pps pp                           { $$ = merge($1, $2); } |
                pp                               ;
vp:             ivp                              |
                '(' vp ')'                       { $$ = $2; };
vps:            vps vps                          { $$ = merge($1, $2); } |
                vps opts                         { $$ = merge($1, $2);  } |
                opts vps                         { $$ = merge($1, $2);  } |
                vp                               { $$ = push(new_contxt(), $1); } |
                '(' vps ')'                      { $$ = $2; };
opts:           opts opts                        { $$ = merge($1, $2); } |
                opt                              { $$ = push(new_contxt(), $1); } |
                '(' opts ')'                     { $$ = $2; };
xpb:            '(' vps ')'                      { $$ = $2; } |
                '(' vps np ')'                   { $$ = push($2, $3); } |
                p                                { $$ = push(new_contxt(), $1); };
xpbs:           xpb                              { $$ = push(new_contxt(), $1); }|
                xpbs xpb                         { $$ = push($1, $2); };
np:             INT                              { $$ = new_number($1); } |
                HEX                              { $$ = new_number($1); } |
                BIN                              { $$ = new_number($1); } |
                STR                              { $$ = new_string($1); } |
                SYM                              { $$ = new_symref($1, LINE); } |
                OOM                              { $$ = NULL; YYFPRINTF(stderr, "Out of memory in line %d\n", LINE); YYABORT; };
sps:            sps SYM xpb                      { $$ = push(push($1, new_symbol($2)), $3) ; } |
                SYM xpb                          { $$ = push(push(new_contxt(), new_symbol($1)), $2); };
par:            par SYM                          { $$ = push($1, new_symbol($2)); } |
                SYM                              { $$ = push(new_contxt(), new_symbol($1)); };
cv:             p xpb                            { $$ = push(push(new_contxt(), $1), $2); };
cvv:            p xpb xpb                        { $$ = push(push(push(new_contxt(), $1), $2), $3); };
/*--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/* Modifiers                                                                                                                                                                            */
/*--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
opt:            all                              |
                append                           |
                assigns                          |
                back                             |
                choices                          |
                command                          |
                compression                      |
                confirm                          |
                default                          |
                delopts                          |
                dest                             |
                disk                             |
                files                            |
                fonts                            |
                getdefaulttool                   |
                getposition                      |
                getstack                         |
                gettooltype                      |
                help                             |
                include                          |
                infos                            |
                newname                          |
                newpath                          |
                nogauge                          |
                noposition                       |
                noreq                            |
                optional                         |
                override                         |
                pattern                          |
                prompt                           |
                quiet                            |
                range                            |
                safe                             |
                setdefaulttool                   |
                setposition                      |
                setstack                         |
                settooltype                      |
                source                           |
                swapcolors                       |
                dynopt                           |
                resident                         ;
/*--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/* Functions                                                                                                                                                                            */
/*--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
ivp:            add        /* arithmetic.c|h */  |
                div                              |
                mul                              |
                sub                              |
                and           /* logic.c|h */    |
                bitand                           |
                bitnot                           |
                bitor                            |
                bitxor                           |
                not                              |
                in                               |
                or                               |
                shiftleft                        |
                shiftright                       |
                xor                              |
                eq         /* comparison.c|h */  |
                gt                               |
                gte                              |
                lt                               |
                lte                              |
                neq                              |
                if            /* control.c|h */  |
                select                           |
                until                            |
                while                            |
                trace                            |
                retrace                          |
                astraw        /* debug.c|h */    |
                asbraw                           |
                asbeval                          |
                eval                             |
                options                          |
                execute      /* external.c|h */  |
                rexx                             |
                run                              |
                abort            /* exit.c|h */  |
                exit                             |
                onerror                          |
                trap                             |
                reboot                           |
                copyfiles        /* file.c|h */  |
                copylib                          |
                delete                           |
                exists                           |
                fileonly                         |
                foreach                          |
                makeassign                       |
                makedir                          |
                protect                          |
                startup                          |
                textfile                         |
                tooltype                         |
                transcript                       |
                rename                           |
                complete  /* information.c|h */  |
                debug                            |
                message                          |
                user                             |
                welcome                          |
                working                          |
                closemedia      /* media.c|h */  |
                effect                           |
                setmedia                         |
                showmedia                        |
                database        /* probe.c|h */  |
                earlier                          |
                getassign                        |
                getdevice                        |
                getdiskspace                     |
                getenv                           |
                getsize                          |
                getsum                           |
                getversion                       |
                iconinfo                         |
                querydisplay                     |
                cus         /* procedure.c|h */  |
                dcl                              |
                askbool        /* prompt.c|h */  |
                askchoice                        |
                askdir                           |
                askdisk                          |
                askfile                          |
                asknumber                        |
                askoptions                       |
                askstring                        |
                cat             /* strop.c|h */  |
                expandpath                       |
                fmt                              |
                pathonly                         |
                patmatch                         |
                strlen                           |
                substr                           |
                tackon                           |
                set            /* symbol.c|h */  |
                symbolset                        |
                symbolval                        |
                openwbobject       /* wb.c|h */  |
                showwbobject                     |
                closewbobject                    ;
/*--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/* arithmetic.c|h                                                                                                                                                                       */
/*--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
add:            '(' '+' ps ')'                   { $$ = new_native(strdup("+"), LINE, n_add, $3, NUMBER); };
div:            '(' '/' pp ')'                   { $$ = new_native(strdup("/"), LINE, n_div, $3, NUMBER); };
mul:            '(' '*' ps ')'                   { $$ = new_native(strdup("*"), LINE, n_mul, $3, NUMBER); };
sub:            '(' '-' ps ')'                   { $$ = new_native(strdup("-"), LINE, n_sub, $3, NUMBER); };
/*--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/* comparison.c|h                                                                                                                                                                       */
/*--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
eq:             '(' '=' pp ')'                   { $$ = new_native(strdup("="), LINE, n_eq, $3, NUMBER); } |
                '(' '=' p ')'                    { $$ = new_native(strdup("="), LINE, n_eq, push(new_contxt(), $3), NUMBER); };
gt:             '(' '>' pp ')'                   { $$ = new_native(strdup(">"), LINE, n_gt, $3, NUMBER); } |
                '(' '>' p ')'                    { $$ = new_native(strdup(">"), LINE, n_gt, push(new_contxt(), $3), NUMBER); };
gte:            '(' GTE pp ')'                   { $$ = new_native(strdup(">="), LINE, n_gte, $3, NUMBER); } |
                '(' GTE p ')'                    { $$ = new_native(strdup(">="), LINE, n_gte, push(new_contxt(), $3), NUMBER); };
lt:             '(' '<' pp ')'                   { $$ = new_native(strdup("<"), LINE, n_lt, $3, NUMBER); } |
                '(' '<' p ')'                    { $$ = new_native(strdup("<"), LINE, n_lt, push(new_contxt(), $3), NUMBER); };
lte:            '(' LTE pp ')'                   { $$ = new_native(strdup("<="), LINE, n_lte, $3, NUMBER); } |
                '(' LTE p ')'                    { $$ = new_native(strdup("<="), LINE, n_lte, push(new_contxt(), $3), NUMBER); };
neq:            '(' NEQ pp ')'                   { $$ = new_native(strdup("<>"), LINE, n_neq, $3, NUMBER); } |
                '(' NEQ p ')'                    { $$ = new_native(strdup("<>"), LINE, n_neq, push(new_contxt(), $3), NUMBER); };
/*--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/* control.c|h                                                                                                                                                                          */
/*--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
if:             '(' IF cvv ')'                   { $$ = new_native(strdup("if"), LINE, n_if, $3, NUMBER); } |
                '(' IF cv ')'                    { $$ = new_native(strdup("if"), LINE, n_if, $3, NUMBER); } |
                '(' IF p ')'                     { $$ = new_native(strdup("if"), LINE, n_if, push(new_contxt(), $3), NUMBER); };
select:         '(' SELECT p xpbs ')'            { $$ = new_native(strdup("select"), LINE, n_select, push(push(new_contxt(), $3), $4), NUMBER); };
until:          '(' UNTIL p vps ')'              { $$ = new_native(strdup("until"), LINE, n_until, push(push(new_contxt(), $3), $4), NUMBER); };
while:          '(' WHILE p vps ')'              { $$ = new_native(strdup("while"), LINE, n_while, push(push(new_contxt(), $3), $4), NUMBER); };
trace:          '(' TRACE ')'                    { $$ = new_native(strdup("trace"), LINE, n_trace, NULL, NUMBER); };
retrace:        '(' RETRACE ')'                  { $$ = new_native(strdup("retrace"), LINE, n_retrace, NULL, NUMBER); };
/*--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/* debug.c|h                                                                                                                                                                          */
/*--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
astraw:         '(' ASTRAW ')'                   { $$ = new_native(strdup("___astraw"), LINE, n_astraw, NULL, NUMBER); };
asbraw:         '(' ASBRAW p ')'                 { $$ = new_native(strdup("___asbraw"), LINE, n_asbraw, push(new_contxt(), $3), NUMBER); };
asbeval:        '(' ASBEVAL p ')'                { $$ = new_native(strdup("___asbeval"), LINE, n_asbeval, push(new_contxt(), $3), NUMBER); };
eval:           '(' EVAL p ')'                   { $$ = new_native(strdup("___eval"), LINE, n_eval, push(new_contxt(), $3), NUMBER); };
options:        '(' OPTIONS ')'                  { $$ = new_native(strdup("___options"), LINE, n_options, NULL, NUMBER); };
/*--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/* external.c|h                                                                                                                                                                         */
/*--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
execute:        '(' EXECUTE ps opts ')'          { $$ = new_native(strdup("execute"), LINE, n_execute, push($3, $4), NUMBER); } |
                '(' EXECUTE opts ps ')'          { $$ = new_native(strdup("execute"), LINE, n_execute, push($4, $3), NUMBER); } |
                '(' EXECUTE opts ps opts ')'     { $$ = new_native(strdup("execute"), LINE, n_execute, push($4, merge($3, $5)), NUMBER); } |
                '(' EXECUTE ps ')'               { $$ = new_native(strdup("execute"), LINE, n_execute, $3, NUMBER); };
rexx:           '(' REXX ps opts ')'             { $$ = new_native(strdup("rexx"), LINE, n_rexx, push($3, $4), NUMBER); } |
                '(' REXX opts ps ')'             { $$ = new_native(strdup("rexx"), LINE, n_rexx, push($4, $3), NUMBER); } |
                '(' REXX opts ps opts ')'        { $$ = new_native(strdup("rexx"), LINE, n_rexx, push($4, merge($3, $5)), NUMBER); } |
                '(' REXX ps ')'                  { $$ = new_native(strdup("rexx"), LINE, n_rexx, $3, NUMBER); };
run:            '(' RUN ps opts ')'              { $$ = new_native(strdup("run"), LINE, n_run, push($3, $4), NUMBER); } |
                '(' RUN opts ps ')'              { $$ = new_native(strdup("run"), LINE, n_run, push($4, $3), NUMBER); } |
                '(' RUN opts ps opts ')'         { $$ = new_native(strdup("run"), LINE, n_run, push($4, merge($3, $5)), NUMBER); } |
                '(' RUN ps ')'                   { $$ = new_native(strdup("run"), LINE, n_run, $3, NUMBER); };
/*--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/* exit.c|h                                                                                                                                                                             */
/*--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
abort:          '(' ABORT ps ')'                 { $$ = new_native(strdup("abort"), LINE, n_abort, $3, NUMBER); };
exit:           '(' EXIT ps quiet ')'            { $$ = new_native(strdup("exit"), LINE, n_exit, push($3, $4), NUMBER); } |
                '(' EXIT quiet ps ')'            { $$ = new_native(strdup("exit"), LINE, n_exit, push($4, $3), NUMBER); } |
                '(' EXIT quiet')'                { $$ = new_native(strdup("exit"), LINE, n_exit, push(new_contxt(), $3), NUMBER); } |
                '(' EXIT ps ')'                  { $$ = new_native(strdup("exit"), LINE, n_exit, $3, NUMBER); } |
                '(' EXIT ')'                     { $$ = new_native(strdup("exit"), LINE, n_exit, NULL, NUMBER); };
onerror:        '(' ONERROR vps ')'              { $$ = new_native(strdup("onerror"), LINE, n_procedure, push(new_contxt(),
                                                        new_custom(strdup("@onerror"), LINE, NULL, $3)), DANGLE); };
reboot:         '(' REBOOT ')'                   { $$ = new_native(strdup("reboot"), LINE, n_reboot, NULL, NUMBER); };
trap:           '(' TRAP p vps ')'               { $$ = new_native(strdup("trap"), LINE, n_trap, push(push(new_contxt(), $3), $4), NUMBER); };
/*--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/* file.c|h                                                                                                                                                                             */
/*--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
copyfiles:      '(' COPYFILES opts ')'           { $$ = new_native(strdup("copyfiles"), LINE, n_copyfiles, $3, STRING); };
copylib:        '(' COPYLIB opts ')'             { $$ = new_native(strdup("copylib"), LINE, n_copylib, $3, NUMBER); };
delete:         '(' DELETE ps opts')'            { $$ = new_native(strdup("delete"), LINE, n_delete, merge($3, $4), NUMBER); } |
                '(' DELETE opts ps')'            { $$ = new_native(strdup("delete"), LINE, n_delete, merge($4, $3), NUMBER); } |
                '(' DELETE opts ps opts ')'      { $$ = new_native(strdup("delete"), LINE, n_delete, merge($4, merge($3, $5)), NUMBER); } |
                '(' DELETE ps ')'                { $$ = new_native(strdup("delete"), LINE, n_delete, $3, NUMBER); };
exists:         '(' EXISTS p ')'                 { $$ = new_native(strdup("exists"), LINE, n_exists, push(new_contxt(), $3), NUMBER); } |
                '(' EXISTS p opts ')'            { $$ = new_native(strdup("exists"), LINE, n_exists, merge(push(new_contxt(), $3), $4), NUMBER); } |
                '(' EXISTS opts p ')'            { $$ = new_native(strdup("exists"), LINE, n_exists, merge(push(new_contxt(), $4), $3), NUMBER); };
fileonly:       '(' FILEONLY p ')'               { $$ = new_native(strdup("fileonly"), LINE, n_fileonly, push(new_contxt(), $3), STRING); };
foreach:        '(' FOREACH pp vps ')'           { $$ = new_native(strdup("foreach"), LINE, n_foreach, push($3, $4), NUMBER); };
makeassign:     '(' MAKEASSIGN pp safe ')'       { $$ = new_native(strdup("makeassign"), LINE, n_makeassign, push($3, $4), NUMBER); } |
                '(' MAKEASSIGN pp ')'            { $$ = new_native(strdup("makeassign"), LINE, n_makeassign, $3, NUMBER); } |
                '(' MAKEASSIGN p safe ')'        { $$ = new_native(strdup("makeassign"), LINE, n_makeassign, push(push(new_contxt(), $3), $4), NUMBER); } |
                '(' MAKEASSIGN p ')'             { $$ = new_native(strdup("makeassign"), LINE, n_makeassign, push(new_contxt(), $3), NUMBER); };
makedir:        '(' MAKEDIR p opts')'            { $$ = new_native(strdup("makedir"), LINE, n_makedir, merge(push(new_contxt(), $3), $4), NUMBER); } |
                '(' MAKEDIR opts p ')'           { $$ = new_native(strdup("makedir"), LINE, n_makedir, merge(push(new_contxt(), $4), $3), NUMBER); } |
                '(' MAKEDIR opts p opts ')'      { $$ = new_native(strdup("makedir"), LINE, n_makedir, merge(push(new_contxt(), $4), merge($3, $5)), NUMBER); } |
                '(' MAKEDIR p ')'                { $$ = new_native(strdup("makedir"), LINE, n_makedir, push(new_contxt(), $3), NUMBER); };
protect:        '(' PROTECT pp opts ')'          { $$ = new_native(strdup("protect"), LINE, n_protect, merge($3, $4), NUMBER); } |
                '(' PROTECT pp ')'               { $$ = new_native(strdup("protect"), LINE, n_protect, $3, NUMBER); } |
                '(' PROTECT p opts ')'           { $$ = new_native(strdup("protect"), LINE, n_protect, merge(push(new_contxt(), $3), $4), NUMBER); } |
                '(' PROTECT p ')'                { $$ = new_native(strdup("protect"), LINE, n_protect, push(new_contxt(), $3), NUMBER); };
startup:        '(' STARTUP p opts ')'           { $$ = new_native(strdup("startup"), LINE, n_startup, merge(push(new_contxt(), $3), $4), NUMBER); } |
                '(' STARTUP opts p ')'           { $$ = new_native(strdup("startup"), LINE, n_startup, merge(push(new_contxt(), $4), $3), NUMBER); } |
                '(' STARTUP opts p opts ')'      { $$ = new_native(strdup("startup"), LINE, n_startup, merge(push(new_contxt(), $4), merge($3, $5)), NUMBER); } |
                '(' STARTUP opts ')'             { $$ = new_native(strdup("startup"), LINE, n_startup, merge(push(new_contxt(), new_symref(strdup("@app-name"), LINE)), $3), NUMBER); };
textfile:       '(' TEXTFILE opts ')'            { $$ = new_native(strdup("textfile"), LINE, n_textfile, $3, NUMBER); };
tooltype:       '(' TOOLTYPE opts ')'            { $$ = new_native(strdup("tooltype"), LINE, n_tooltype, $3, NUMBER); };
transcript:     '(' TRANSCRIPT ps ')'            { $$ = new_native(strdup("transcript"), LINE, n_transcript, $3, NUMBER); };
rename:         '(' RENAME pp opts')'            { $$ = new_native(strdup("rename"), LINE, n_rename, merge($3, $4), NUMBER); } |
                '(' RENAME pp ')'                { $$ = new_native(strdup("rename"), LINE, n_rename, $3, NUMBER); };
/*--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/* information.c|h                                                                                                                                                                      */
/*--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
complete:       '(' COMPLETE p ')'               { $$ = new_native(strdup("complete"), LINE, n_complete, push(new_contxt(), $3), NUMBER); };
debug:          '(' DEBUG ps ')'                 { $$ = new_native(strdup("debug"), LINE, n_debug, $3, NUMBER); } |
                '(' DEBUG ')'                    { $$ = new_native(strdup("debug"), LINE, n_debug, NULL, NUMBER); };
message:        '(' MESSAGE ps opts ')'          { $$ = new_native(strdup("message"), LINE, n_message, merge($4, $3), NUMBER); } |
                '(' MESSAGE opts ps')'           { $$ = new_native(strdup("message"), LINE, n_message, merge($3, $4), NUMBER); } |
                '(' MESSAGE opts ps opts ')'     { $$ = new_native(strdup("message"), LINE, n_message, push(merge($3, $5), $4), NUMBER); } |
                '(' MESSAGE ps ')'               { $$ = new_native(strdup("message"), LINE, n_message, $3, NUMBER); };
user:           '(' USER p ')'                   { $$ = new_native(strdup("user"), LINE, n_user, push(new_contxt(), $3), NUMBER); };
welcome:        '(' WELCOME ps ')'               { $$ = new_native(strdup("welcome"), LINE, n_welcome, $3, NUMBER); } |
                '(' WELCOME ')'                  { $$ = new_native(strdup("welcome"), LINE, n_welcome, NULL, NUMBER); };
working:        '(' WORKING ps ')'               { $$ = new_native(strdup("working"), LINE, n_working, $3, NUMBER); } |
                '(' WORKING ')'                  { $$ = new_native(strdup("working"), LINE, n_working, NULL, NUMBER); };
/*--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/* logic.c|h                                                                                                                                                                            */
/*--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
and:            '(' AND ps ')'                   { $$ = new_native(strdup("AND"), LINE, n_and, $3, NUMBER); };
bitand:         '(' BITAND pp ')'                { $$ = new_native(strdup("BITAND"), LINE, n_bitand, $3, NUMBER); };
bitnot:         '(' BITNOT p ')'                 { $$ = new_native(strdup("BITNOT"), LINE, n_bitnot, push(new_contxt(), $3), NUMBER); };
bitor:          '(' BITOR pp ')'                 { $$ = new_native(strdup("BITOR"), LINE, n_bitor, $3, NUMBER); };
bitxor:         '(' BITXOR pp ')'                { $$ = new_native(strdup("BITXOR"), LINE, n_bitxor, $3, NUMBER); };
not:            '(' NOT p ')'                    { $$ = new_native(strdup("NOT"), LINE, n_not, push(new_contxt(), $3), NUMBER); };
in:             '(' IN p ps ')'                  { $$ = new_native(strdup("IN"), LINE, n_in, push(push(new_contxt(), $3), $4), NUMBER); };
or:             '(' OR ps ')'                    { $$ = new_native(strdup("OR"), LINE, n_or, $3, NUMBER); };
shiftleft:      '(' SHIFTLEFT pp ')'             { $$ = new_native(strdup("shiftleft"), LINE, n_shiftleft, $3, NUMBER); };
shiftright:     '(' SHIFTRIGHT pp ')'            { $$ = new_native(strdup("shiftright"), LINE, n_shiftright, $3, NUMBER); };
xor:            '(' XOR pp ')'                   { $$ = new_native(strdup("XOR"), LINE, n_xor, $3, NUMBER); };
/*--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/* media.c|h                                                                                                                                                                            */
/*--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
closemedia:     '(' CLOSEMEDIA p ')'             { $$ = new_native(strdup("closemedia"), LINE, n_closemedia, push(new_contxt(), $3), NUMBER); };
effect:         '(' EFFECT pp pp ')'   	         { $$ = new_native(strdup("effect"), LINE, n_effect, merge($3, $4), NUMBER); };
setmedia:       '(' SETMEDIA pp ')'              { $$ = new_native(strdup("setmedia"), LINE, n_setmedia, $3, NUMBER); } |
                '(' SETMEDIA pp p ')'            { $$ = new_native(strdup("setmedia"), LINE, n_setmedia, push($3, $4), NUMBER); };
showmedia:      '(' SHOWMEDIA pp pp ps ')'       { $$ = new_native(strdup("showmedia"), LINE, n_showmedia, merge(merge($3, $4), $5), NUMBER); };
/*--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/* probe.c|h                                                                                                                                                                            */
/*--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
database:       '(' DATABASE p ')'               { $$ = new_native(strdup("database"), LINE, n_database, push(new_contxt(), $3), STRING); } |
                '(' DATABASE pp ')'              { $$ = new_native(strdup("database"), LINE, n_database, $3, STRING); };
earlier:        '(' EARLIER pp ')'               { $$ = new_native(strdup("earlier"), LINE, n_earlier, $3, NUMBER); };
getassign:      '(' GETASSIGN p ')'              { $$ = new_native(strdup("getassign"), LINE, n_getassign, push(new_contxt(), $3), STRING); } |
                '(' GETASSIGN pp ')'             { $$ = new_native(strdup("getassign"), LINE, n_getassign, $3, STRING); };
getdevice:      '(' GETDEVICE p ')'              { $$ = new_native(strdup("getdevice"), LINE, n_getdevice, push(new_contxt(), $3), STRING); };
getdiskspace:   '(' GETDISKSPACE p ')'           { $$ = new_native(strdup("getdiskspace"), LINE, n_getdiskspace, push(new_contxt(), $3), NUMBER); } |
                '(' GETDISKSPACE pp ')'          { $$ = new_native(strdup("getdiskspace"), LINE, n_getdiskspace, $3, NUMBER); };
getenv:         '(' GETENV p ')'                 { $$ = new_native(strdup("getenv"), LINE, n_getenv, push(new_contxt(), $3), STRING); };
getsize:        '(' GETSIZE p ')'                { $$ = new_native(strdup("getsize"), LINE, n_getsize, push(new_contxt(), $3), NUMBER); };
getsum:         '(' GETSUM p ')'                 { $$ = new_native(strdup("getsum"), LINE, n_getsum, push(new_contxt(), $3), NUMBER); };
getversion:     '(' GETVERSION ')'               { $$ = new_native(strdup("getversion"), LINE, n_getversion, NULL, NUMBER); } |
                '(' GETVERSION p ')'             { $$ = new_native(strdup("getversion"), LINE, n_getversion, push(new_contxt(), $3), NUMBER); } |
                '(' GETVERSION p resident ')'    { $$ = new_native(strdup("getversion"), LINE, n_getversion, push(push(new_contxt(), $3), $4), NUMBER); };
iconinfo:       '(' ICONINFO opts ')'            { $$ = new_native(strdup("iconinfo"), LINE, n_iconinfo, $3, NUMBER); };
querydisplay:   '(' QUERYDISPLAY pp ')'          { $$ = new_native(strdup("querydisplay"), LINE, n_querydisplay, $3, NUMBER); };
/*--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/* procedure.c|h                                                                                                                                                                        */
/*--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
dcl:            '(' DCL SYM par s ')'            { $$ = new_native(strdup("procedure"), LINE, n_procedure, push(new_contxt(), new_custom($3, LINE, $4, $5)), NUMBER); } |
                '(' DCL SYM par ')'              { $$ = new_native(strdup("procedure"), LINE, n_procedure, push(new_contxt(), new_custom($3, LINE, $4, NULL)), NUMBER); } |
                '(' DCL SYM s ')'                { $$ = new_native(strdup("procedure"), LINE, n_procedure, push(new_contxt(), new_custom($3, LINE, NULL, $4)), NUMBER); } |
                '(' DCL SYM ')'                  { $$ = new_native(strdup("procedure"), LINE, n_procedure, push(new_contxt(), new_custom($3, LINE, NULL, NULL)), NUMBER); };
cus:            '(' SYM ps ')'                   { $$ = new_cusref($2, LINE, $3); } |
                '(' SYM ')'                      { $$ = new_cusref($2, LINE, NULL); };
/*--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/* prompt.c|h                                                                                                                                                                           */
/*--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
askbool:        '(' ASKBOOL ')'                  { $$ = new_native(strdup("askbool"), LINE, n_askbool, NULL, NUMBER); };
askbool:        '(' ASKBOOL opts ')'             { $$ = new_native(strdup("askbool"), LINE, n_askbool, $3, NUMBER); };
askchoice:      '(' ASKCHOICE opts ')'           { $$ = new_native(strdup("askchoice"), LINE, n_askchoice, $3, NUMBER); };
askdir:         '(' ASKDIR ')'                   { $$ = new_native(strdup("askdir"), LINE, n_askdir, NULL, STRING); };
askdir:         '(' ASKDIR opts ')'              { $$ = new_native(strdup("askdir"), LINE, n_askdir, $3, STRING); };
askdisk:        '(' ASKDISK opts ')'             { $$ = new_native(strdup("askdisk"), LINE, n_askdisk, $3, NUMBER); };
askfile:        '(' ASKFILE ')'                  { $$ = new_native(strdup("askfile"), LINE, n_askfile, NULL, STRING); };
askfile:        '(' ASKFILE opts ')'             { $$ = new_native(strdup("askfile"), LINE, n_askfile, $3, STRING); };
asknumber:      '(' ASKNUMBER ')'                { $$ = new_native(strdup("asknumber"), LINE, n_asknumber, NULL, NUMBER); };
asknumber:      '(' ASKNUMBER opts ')'           { $$ = new_native(strdup("asknumber"), LINE, n_asknumber, $3, NUMBER); };
askoptions:     '(' ASKOPTIONS opts ')'          { $$ = new_native(strdup("askoptions"), LINE, n_askoptions, $3, NUMBER); };
askstring:      '(' ASKSTRING ')'                { $$ = new_native(strdup("askstring"), LINE, n_askstring, NULL, STRING); };
askstring:      '(' ASKSTRING opts ')'           { $$ = new_native(strdup("askstring"), LINE, n_askstring, $3, STRING); };
/*--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/* strop.c|h                                                                                                                                                                            */
/*--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
cat:            '(' CAT ps ')'                   { $$ = new_native(strdup("cat"), LINE, n_cat, $3, STRING); };
expandpath:     '(' EXPANDPATH p ')'             { $$ = new_native(strdup("expandpath"), LINE, n_expandpath, push(new_contxt(), $3), STRING); };
fmt:            '(' STR ps ')'                   { $$ = new_native($2, LINE, n_fmt, $3, STRING); } |
                '(' STR ')'                      { $$ = new_native($2, LINE, n_fmt, NULL, STRING); };
pathonly:       '(' PATHONLY p ')'               { $$ = new_native(strdup("pathonly"), LINE, n_pathonly, push(new_contxt(), $3), STRING); };
patmatch:       '(' PATMATCH pp ')'              { $$ = new_native(strdup("patmatch"), LINE, n_patmatch, $3, NUMBER); };
strlen:         '(' STRLEN p ')'                 { $$ = new_native(strdup("strlen"), LINE, n_strlen, push(new_contxt(), $3), NUMBER); };
substr:         '(' SUBSTR pp ')'                { $$ = new_native(strdup("substr"), LINE, n_substr, $3, STRING); } |
                '(' SUBSTR pp p ')'              { $$ = new_native(strdup("substr"), LINE, n_substr, push($3, $4), STRING); };
tackon:         '(' TACKON pp ')'                { $$ = new_native(strdup("tackon"), LINE, n_tackon, $3, STRING); };
/*--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/* symbol.c|h                                                                                                                                                                           */
/*--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
set:            '(' SET sps ')'                  { $$ = new_native(strdup("set"), LINE, n_set, $3, DANGLE); };
symbolset:      '(' SYMBOLSET pps ')'            { $$ = new_native(strdup("symbolset"), LINE, n_symbolset, $3, DANGLE); };
symbolval:      '(' SYMBOLVAL p ')'              { $$ = new_native(strdup("symbolval"), LINE, n_symbolval, push(new_contxt(), $3), NUMBER); };
/*--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/* wb.c|h                                                                                                                                                                               */
/*--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
openwbobject:   '(' OPENWBOBJECT p ')'           { $$ = new_native(strdup("openwbobject"), LINE, n_openwbobject, push(new_contxt(), $3), NUMBER); } |
                '(' OPENWBOBJECT p opts ')'      { $$ = new_native(strdup("openwbobject"), LINE, n_openwbobject, merge(push(new_contxt(), $3), $4), NUMBER); } |
                '(' OPENWBOBJECT opts p ')'      { $$ = new_native(strdup("openwbobject"), LINE, n_openwbobject, merge(push(new_contxt(), $4), $3), NUMBER); } |
                '(' OPENWBOBJECT opts p opts ')' { $$ = new_native(strdup("openwbobject"), LINE, n_openwbobject, merge(push(new_contxt(), $4), merge($3, $5)), NUMBER); };
showwbobject:   '(' SHOWWBOBJECT p ')'           { $$ = new_native(strdup("showwbobject"), LINE, n_showwbobject, push(new_contxt(), $3), NUMBER); };
closewbobject:  '(' CLOSEWBOBJECT p ')'          { $$ = new_native(strdup("closewbobject"), LINE, n_closewbobject, push(new_contxt(), $3), NUMBER); };
/*--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/* Options                                                                                                                                                                              */
/*--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
all:            '(' ALL ')'                      { $$ = new_option(strdup("all"), OPT_ALL, NULL); };
append:         '(' APPEND ps ')'                { $$ = new_option(strdup("append"), OPT_APPEND, $3); };
assigns:        '(' ASSIGNS ')'                  { $$ = new_option(strdup("assigns"), OPT_ASSIGNS, NULL); };
back:           '(' BACK vps ')'                 { $$ = new_option(strdup("back"), OPT_BACK, $3); };
choices:        '(' CHOICES ps ')'               { $$ = new_option(strdup("choices"), OPT_CHOICES, $3); };
command:        '(' COMMAND ps ')'               { $$ = new_option(strdup("command"), OPT_COMMAND, $3); };
compression:    '(' COMPRESSION ')'              { $$ = new_option(strdup("compression"), OPT_COMPRESSION, NULL); };
confirm:        '(' CONFIRM ps ')'               { $$ = new_option(strdup("confirm"), OPT_CONFIRM, $3); } |
                '(' CONFIRM ')'                  { $$ = new_option(strdup("confirm"), OPT_CONFIRM, NULL); };
default:        '(' DEFAULT p ')'                { $$ = new_option(strdup("default"), OPT_DEFAULT, push(new_contxt(), $3)); };
delopts:        '(' DELOPTS ps ')'               { $$ = new_option(strdup("delopts"), OPT_DELOPTS, $3); } |
                '(' DELOPTS ')'                  { $$ = new_option(strdup("delopts"), OPT_DELOPTS, push(new_contxt(), new_symref(strdup("@null"), LINE))); };
dest:           '(' DEST p ')'                   { $$ = new_option(strdup("dest"), OPT_DEST, push(new_contxt(), $3)); };
disk:           '(' DISK ')'                     { $$ = new_option(strdup("disk"), OPT_DISK, NULL); };
files:          '(' FILES ')'                    { $$ = new_option(strdup("files"), OPT_FILES, NULL); };
fonts:          '(' FONTS ')'                    { $$ = new_option(strdup("fonts"), OPT_FONTS, NULL); };
getdefaulttool: '(' GETDEFAULTTOOL p ')'         { $$ = new_option(strdup("getdefaulttool"), OPT_GETDEFAULTTOOL, push(new_contxt(), $3)); };
getposition:    '(' GETPOSITION pp ')'           { $$ = new_option(strdup("getposition"), OPT_GETPOSITION, $3); };
getstack:       '(' GETSTACK p ')'               { $$ = new_option(strdup("getstack"), OPT_GETSTACK, push(new_contxt(), $3)); };
gettooltype:    '(' GETTOOLTYPE pp ')'           { $$ = new_option(strdup("gettooltype"), OPT_GETTOOLTYPE, $3); };
help:           '(' HELP ps ')'                  { $$ = new_option(strdup("help"), OPT_HELP, $3); } |
                '(' HELP ')'                     { $$ = new_option(strdup("help"), OPT_HELP, push(new_contxt(), new_symref(strdup("@null"), LINE))); };
infos:          '(' INFOS ')'                    { $$ = new_option(strdup("infos"), OPT_INFOS, NULL); };
include:        '(' INCLUDE p ')'                { $$ = new_option(strdup("include"), OPT_INCLUDE, push(new_contxt(), $3)); };
newname:        '(' NEWNAME p ')'                { $$ = new_option(strdup("newname"), OPT_NEWNAME, push(new_contxt(), $3)); };
newpath:        '(' NEWPATH ')'                  { $$ = new_option(strdup("newpath"), OPT_NEWPATH, NULL); } |
                '(' NEWPATH p ')'                { $$ = new_option(strdup("newpath"), OPT_NEWPATH, push(new_contxt(), $3)); };
nogauge:        '(' NOGAUGE ')'                  { $$ = new_option(strdup("nogauge"), OPT_NOGAUGE, NULL); };
noposition:     '(' NOPOSITION ')'               { $$ = new_option(strdup("noposition"), OPT_NOPOSITION, NULL); };
noreq:          '(' NOREQ ')'                    { $$ = new_option(strdup("noreq"), OPT_NOREQ, NULL); };
pattern:        '(' PATTERN p ')'                { $$ = new_option(strdup("pattern"), OPT_PATTERN, push(new_contxt(), $3)); };
prompt:         '(' PROMPT ps ')'                { $$ = new_option(strdup("prompt"), OPT_PROMPT, $3); } |
                '(' PROMPT ')'                   { $$ = new_option(strdup("prompt"), OPT_PROMPT, push(new_contxt(), new_symref(strdup("@null"), LINE))); };
quiet:          '(' QUIET ')'                    { $$ = new_option(strdup("quiet"), OPT_QUIET, NULL); };
range:          '(' RANGE pp ')'                 { $$ = new_option(strdup("range"), OPT_RANGE, $3); };
safe:           '(' SAFE ')'                     { $$ = new_option(strdup("safe"), OPT_SAFE, NULL); };
setdefaulttool: '(' SETDEFAULTTOOL p ')'         { $$ = new_option(strdup("setdefaulttool"), OPT_SETDEFAULTTOOL, push(new_contxt(), $3)); };
setposition:    '(' SETPOSITION pp ')'           { $$ = new_option(strdup("setposition"), OPT_SETPOSITION, $3); };
setstack:       '(' SETSTACK p ')'               { $$ = new_option(strdup("setstack"), OPT_SETSTACK, push(new_contxt(), $3)); };
settooltype:    '(' SETTOOLTYPE pp ')'           { $$ = new_option(strdup("settooltype"), OPT_SETTOOLTYPE, $3); } |
                '(' SETTOOLTYPE p ')'            { $$ = new_option(strdup("settooltype"), OPT_SETTOOLTYPE, push(new_contxt(), $3)); };
source:         '(' SOURCE p ')'                 { $$ = new_option(strdup("source"), OPT_SOURCE, push(new_contxt(), $3)); } |
                '(' SOURCE p all ')'             { $$ = new_option(strdup("source"), OPT_SOURCE, push(push(new_contxt(), $3), $4)); };
swapcolors:     '(' SWAPCOLORS ')'               { $$ = new_option(strdup("swapcolors"), OPT_SWAPCOLORS, NULL); };
optional:       '(' OPTIONAL ps ')'              { $$ = new_option(strdup("optional"), OPT_OPTIONAL, $3); } |
                '(' OPTIONAL ')'                 { $$ = new_option(strdup("optional"), OPT_OPTIONAL, push(new_contxt(), new_symref(strdup("@null"), LINE))); };
resident:       '(' RESIDENT ')'                 { $$ = new_option(strdup("resident"), OPT_RESIDENT, NULL); };
override:       '(' OVERRIDE p ')'               { $$ = new_option(strdup("override"), OPT_OVERRIDE, push(new_contxt(), $3)); };
dynopt:         '(' IF p opts ')'                { $$ = new_option(strdup("dynopt"), OPT_DYNOPT, push(push(new_contxt(), $3), $4)); } |
                '(' IF p opts opts ')'           { $$ = new_option(strdup("dynopt"), OPT_DYNOPT, push(push(push(new_contxt(), $3), $4), $5)); };
/*--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
%%
