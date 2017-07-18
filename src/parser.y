%{
#include <stdio.h>
#include <string.h>
#include "debug.h"
#include "native.h"
#include "eval.h"
#include "util.h"
#include "sysenv.h"
#include "lexer.h"
%}

%define api.pure full                                                                                            
%lex-param   { yyscan_t scanner }
%parse-param { yyscan_t scanner }

%token                      SET DCL IF WHILE UNTIL
%token                      AND OR XOR NOT LTE GTE
%token                      BITAND BITOR BITXOR BITNOT 
%token                      SHIFTLEFT SHIFTRIGHT IN
%token                      STRLEN SUBSTR ASKDIR ASKFILE ASKSTRING ASKNUMBER ASKCHOICE ASKOPTIONS ASKBOOL ASKDISK CAT EXISTS EXPANDPATH EARLIER FILEONLY GETASSIGN GETDEVICE GETDISKSPACE GETENV GETSIZE GETSUM GETVERSION ICONINFO PATHONLY PATMATCH SELECT SYMBOLSET SYMBOLVAL TACKON TRANSCRIPT COMPLETE USER WORKING WELCOME ABORT COPYFILES COPYLIB DATABASE DEBUG DELETE EXECUTE EXIT FOREACH MAKEASSIGN MAKEDIR MESSAGE ONERROR PROTECT RENAME REXX RUN STARTUP TEXTFILE TOOLTYPE TRAP
%token                      ALL APPEND ASKUSER ASSIGNS CHOICES COMMAND COMPRESSION CONFIRM DEFAULT DELOPTS DEST DISK FAIL FILES FONTS FORCE HELP INFOS INCLUDE NEWNAME NEWPATH NOFAIL NOGAUGE NOPOSITION NOREQ OKNODELETE PATTERN PROMPT QUIET RANGE SAFE SETDEFAULTTOOL SETSTACK SETTOOLTYPE SOURCE SWAPCOLORS OPTIONAL RESIDENT 
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
%type<e>                    strlen substr askdir askfile askstring asknumber askchoice askoptions askbool askdisk cat exists expandpath earlier fileonly getassign getdevice getdiskspace getenv getsize getsum getversion iconinfo pathonly patmatch select symbolset symbolval tackon transcript complete user working welcome abort copyfiles copylib database debug delete execute exit foreach makeassign makedir message onerror protect rename rexx run startup textfile tooltype trap
%destructor { kill($$); }   strlen substr askdir askfile askstring asknumber askchoice askoptions askbool askdisk cat exists expandpath earlier fileonly getassign getdevice getdiskspace getenv getsize getsum getversion iconinfo pathonly patmatch select symbolset symbolval tackon transcript complete user working welcome abort copyfiles copylib database debug delete execute exit foreach makeassign makedir message onerror protect rename rexx run startup textfile tooltype trap
%type<e>                    all append askuser assigns choices command compression confirm default delopts dest disk fail files fonts force help infos include newname newpath nofail nogauge noposition noreq oknodelete pattern prompt quiet range safe setdefaulttool setstack settooltype source swapcolors optional resident 
%destructor { kill($$); }   all append askuser assigns choices command compression confirm default delopts dest disk fail files fonts force help infos include newname newpath nofail nogauge noposition noreq oknodelete pattern prompt quiet range safe setdefaulttool setstack settooltype source swapcolors optional resident 

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
                vp                          { $$ = push(new_contxt(), $1); };
np:             INT                         { $$ = new_number($1); } |
                HEX                         { $$ = new_number($1); } |
                BIN                         { $$ = new_number($1); } |
                STR                         { $$ = new_string($1); } |
                SYM                         { $$ = new_symref($1, LINE); };
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
                quiet                       |         
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
                exit                        |
                foreach                     |
                makeassign                  |
                makedir                     |
                message                     |
                onerror                     |
                protect                     |
                rename                      |
                rexx                        |
                run                         |
                startup                     |
                textfile                    |
                tooltype                    |
                trap                        |
                complete                    ;
fmt:            '(' STR ps ')'              { $$ = new_native($2, LINE, m_fmt, $3); } |
                '(' STR ')'                 { $$ = new_native($2, LINE, m_fmt, NULL); };
dcl:            '(' DCL SYM par s ')'       { $$ = new_custom($3, LINE, $4, $5); } |
                '(' DCL SYM s ')'           { $$ = new_custom($3, LINE, NULL, $4); };
cus:            '(' SYM ps ')'              { $$ = new_cusref($2, LINE, $3); } |
                '(' SYM ')'                 { $$ = new_cusref($2, LINE, NULL); };
add:            '(' '+' ps ')'              { $$ = new_native(strdup("+"), LINE, m_add, $3); };
mul:            '(' '*' ps ')'              { $$ = new_native(strdup("*"), LINE, m_mul, $3); };
sub:            '(' '-' pp ')'              { $$ = new_native(strdup("-"), LINE, m_sub, $3); };
div:            '(' '/' pp ')'              { $$ = new_native(strdup("/"), LINE, m_div, $3); };
lt:             '(' '<' pp ')'              { $$ = new_native(strdup("<"), LINE, m_lt, $3); };
lte:            '(' LTE pp ')'              { $$ = new_native(strdup("<="), LINE, m_lte, $3); };
gt:             '(' '>' pp ')'              { $$ = new_native(strdup(">"), LINE, m_gt, $3); };
gte:            '(' GTE pp ')'              { $$ = new_native(strdup(">="), LINE, m_gte, $3); };
eq:             '(' '=' pp ')'              { $$ = new_native(strdup("="), LINE, m_eq, $3); };
set:            '(' SET sps ')'             { $$ = new_native(strdup("set"), LINE, m_set, $3); };
if:             '(' IF cvv ')'              { $$ = new_native(strdup("if"), LINE, m_if, $3); };
while:          '(' WHILE cv ')'            { $$ = new_native(strdup("while"), LINE, m_while, $3); };
until:          '(' UNTIL cv ')'            { $$ = new_native(strdup("until"), LINE, m_until, $3); };
and:            '(' AND pp ')'              { $$ = new_native(strdup("AND"), LINE, m_and, $3); }; 
or:             '(' OR pp ')'               { $$ = new_native(strdup("OR"), LINE, m_or, $3); }; 
xor:            '(' XOR pp ')'              { $$ = new_native(strdup("XOR"), LINE, m_xor, $3); }; 
not:            '(' NOT p ')'               { $$ = new_native(strdup("NOT"), LINE, m_not, push(new_contxt(), $3)); }; 
bitand:         '(' BITAND pp ')'           { $$ = new_native(strdup("BITAND"), LINE, m_bitand, $3); }; 
bitor:          '(' BITOR pp ')'            { $$ = new_native(strdup("BITOR"), LINE, m_bitor, $3); }; 
bitxor:         '(' BITXOR pp ')'           { $$ = new_native(strdup("BITXOR"), LINE, m_bitxor, $3); }; 
bitnot:         '(' BITNOT p ')'            { $$ = new_native(strdup("BITNOT"), LINE, m_bitnot, push(new_contxt(), $3)); }; 
shiftleft:      '(' SHIFTLEFT pp ')'        { $$ = new_native(strdup("shiftleft"), LINE, m_shiftleft, $3); }; 
shiftright:     '(' SHIFTRIGHT pp ')'       { $$ = new_native(strdup("shiftright"), LINE, m_shiftright, $3); }; 
in:             '(' IN p ps ')'             { $$ = new_native(strdup("IN"), LINE, m_in, push(push(new_contxt(), $3), $4)); }; 
strlen:         '(' STRLEN p ')'            { $$ = new_native(strdup("strlen"), LINE, m_strlen, push(new_contxt(), $3)); }; 
substr:         '(' SUBSTR p ps ')'         { $$ = new_native(strdup("substr"), LINE, m_substr, push(push(new_contxt(), $3), $4)); }; 
askdir:         '(' ASKDIR ')'              { $$ = new_native(strdup("askdir"), LINE, m_askdir, NULL); };
askfile:        '(' ASKFILE ')'             { $$ = new_native(strdup("askfile"), LINE, m_askfile, NULL); };
askstring:      '(' ASKSTRING ')'           { $$ = new_native(strdup("askstring"), LINE, m_askstring, NULL); };
asknumber:      '(' ASKNUMBER ')'           { $$ = new_native(strdup("asknumber"), LINE, m_asknumber, NULL); };
askchoice:      '(' ASKCHOICE ')'           { $$ = new_native(strdup("askchoice"), LINE, m_askchoice, NULL); };
askoptions:     '(' ASKOPTIONS ')'          { $$ = new_native(strdup("askoptions"), LINE, m_askoptions, NULL); };
askbool:        '(' ASKBOOL ')'             { $$ = new_native(strdup("askbool"), LINE, m_askbool, NULL); };
askdisk:        '(' ASKDISK ')'             { $$ = new_native(strdup("askdisk"), LINE, m_askdisk, NULL); };
cat:            '(' CAT ps ')'              { $$ = new_native(strdup("cat"), LINE, m_cat, $3); };
exists:         '(' EXISTS p ')'            { $$ = new_native(strdup("exists"), LINE, m_exists, push(new_contxt(), $3)); }; 
expandpath:     '(' EXPANDPATH p ')'        { $$ = new_native(strdup("expandpath"), LINE, m_expandpath, push(new_contxt(), $3)); }; 
earlier:        '(' EARLIER pp ')'          { $$ = new_native(strdup("earlier"), LINE, m_earlier, $3); }; 
fileonly:       '(' FILEONLY p ')'          { $$ = new_native(strdup("fileonly"), LINE, m_fileonly, push(new_contxt(), $3)); }; 
getassign:      '(' GETASSIGN pp ')'        { $$ = new_native(strdup("getassign"), LINE, m_getassign, $3); }; 
getdevice:      '(' GETDEVICE p ')'         { $$ = new_native(strdup("getdevice"), LINE, m_getdevice, push(new_contxt(), $3)); }; 
getdiskspace:   '(' GETDISKSPACE p ')'      { $$ = new_native(strdup("getdiskspace"), LINE, m_getdiskspace, push(new_contxt(), $3)); }; 
getenv:         '(' GETENV p ')'            { $$ = new_native(strdup("getenv"), LINE, m_getenv, push(new_contxt(), $3)); }; 
getsize:        '(' GETSIZE p ')'           { $$ = new_native(strdup("getsize"), LINE, m_getsize, push(new_contxt(), $3)); }; 
getsum:         '(' GETSUM p ')'            { $$ = new_native(strdup("getsum"), LINE, m_getsum, push(new_contxt(), $3)); }; 
getversion:     '(' GETVERSION p ')'        { $$ = new_native(strdup("getversion"), LINE, m_getversion, push(new_contxt(), $3)); }; 
iconinfo:       '(' ICONINFO p ')'          { $$ = new_native(strdup("iconinfo"), LINE, m_iconinfo, push(new_contxt(), $3)); }; 
pathonly:       '(' PATHONLY p ')'          { $$ = new_native(strdup("pathonly"), LINE, m_pathonly, push(new_contxt(), $3)); }; 
patmatch:       '(' PATMATCH pp ')'         { $$ = new_native(strdup("patmatch"), LINE, m_patmatch, $3); }; 
select:         '(' SELECT p ps ')'         { $$ = new_native(strdup("select"), LINE, m_select, push(push(new_contxt(), $3), $4)); }; 
symbolset:      '(' SYMBOLSET pp ')'        { $$ = new_native(strdup("symbolset"), LINE, m_symbolset, $3); }; 
symbolval:      '(' SYMBOLVAL p ')'         { $$ = new_native(strdup("symbolval"), LINE, m_symbolval, push(new_contxt(), $3)); }; 
tackon:         '(' TACKON pp ')'           { $$ = new_native(strdup("tackon"), LINE, m_tackon, $3); }; 
transcript:     '(' TRANSCRIPT pp ')'       { $$ = new_native(strdup("transcript"), LINE, m_transcript, $3); }; 
complete:       '(' COMPLETE p ')'          { $$ = new_native(strdup("complete"), LINE, m_complete, push(new_contxt(), $3)); }; 
user:           '(' USER p ')'              { $$ = new_native(strdup("user"), LINE, m_user, push(new_contxt(), $3)); }; 
working:        '(' WORKING ')'             { $$ = new_native(strdup("working"), LINE, m_working, new_contxt()); }; 
welcome:        '(' WELCOME ps ')'          { $$ = new_native(strdup("welcome"), LINE, m_welcome, $3); }; 
abort:          '(' ABORT ps ')'            { $$ = new_native(strdup("abort"), LINE, m_abort, $3); }; 
copyfiles:      '(' COPYFILES opts ')'      { $$ = new_native(strdup("copyfiles"), LINE, m_copyfiles, $3); }; 
copylib:        '(' COPYLIB opts ')'        { $$ = new_native(strdup("copylib"), LINE, m_copylib, $3); }; 
database:       '(' DATABASE p ')'          { $$ = new_native(strdup("database"), LINE, m_database, push(new_contxt(), $3)); } | 
                '(' DATABASE pp ')'         { $$ = new_native(strdup("database"), LINE, m_database, $3); }; 
debug:          '(' DEBUG ps ')'            { $$ = new_native(strdup("debug"), LINE, m_debug, $3); }; 
delete:         '(' DELETE p opts')'        { $$ = new_native(strdup("delete"), LINE, m_delete, push(push(new_contxt(), $3), $4)); } | 
                '(' DELETE p ')'            { $$ = new_native(strdup("delete"), LINE, m_delete, push(new_contxt(), $3)); }; 
execute:        '(' EXECUTE p opts')'       { $$ = new_native(strdup("execute"), LINE, m_execute, push(push(new_contxt(), $3), $4)); } | 
                '(' EXECUTE p ')'           { $$ = new_native(strdup("execute"), LINE, m_execute, push(new_contxt(), $3)); }; 
exit:           '(' EXIT ps opt')'          { $$ = new_native(strdup("exit"), LINE, m_exit, push(push(new_contxt(), $3), $4)); } | 
                '(' EXIT ps ')'             { $$ = new_native(strdup("exit"), LINE, m_exit, push(new_contxt(), $3)); } |
                '(' EXIT ')'                { $$ = new_native(strdup("exit"), LINE, m_exit, NULL); }; 
foreach:        '(' FOREACH pp vpb ')'      { $$ = new_native(strdup("foreach"), LINE, m_foreach, push($3, $4)); };
makeassign:     '(' MAKEASSIGN pp opt')'    { $$ = new_native(strdup("makeassign"), LINE, m_makeassign, push(push(new_contxt(), $3), $4)); } | 
                '(' MAKEASSIGN pp ')'       { $$ = new_native(strdup("makeassign"), LINE, m_makeassign, push(new_contxt(), $3)); };
makedir:        '(' MAKEDIR p opts')'       { $$ = new_native(strdup("makedir"), LINE, m_makedir, push(push(new_contxt(), $3), $4)); } | 
                '(' MAKEDIR p ')'           { $$ = new_native(strdup("makedir"), LINE, m_makedir, push(new_contxt(), $3)); }; 
message:        '(' MESSAGE ps opt')'       { $$ = new_native(strdup("message"), LINE, m_message, push(push(new_contxt(), $3), $4)); } | 
                '(' MESSAGE ps ')'          { $$ = new_native(strdup("message"), LINE, m_message, push(new_contxt(), $3)); };
onerror:        '(' ONERROR vpb ')'         { $$ = new_native(strdup("onerror"), LINE, m_onerror, $3); };
protect:        '(' PROTECT pp opt ')'      { $$ = new_native(strdup("protect"), LINE, m_protect, push($3, $4)); } | 
                '(' PROTECT pp ')'          { $$ = new_native(strdup("protect"), LINE, m_protect, $3); };
rename:         '(' RENAME pp opts')'       { $$ = new_native(strdup("rename"), LINE, m_rename, push($3, $4)); } | 
                '(' RENAME pp ')'           { $$ = new_native(strdup("rename"), LINE, m_rename, $3); }; 
rexx:           '(' REXX p opts')'          { $$ = new_native(strdup("rexx"), LINE, m_rexx, push(push(new_contxt(), $3), $4)); } |
                '(' REXX p ')'              { $$ = new_native(strdup("rexx"), LINE, m_rexx, push(new_contxt(), $3)); };
run:            '(' RUN p opts')'           { $$ = new_native(strdup("run"), LINE, m_run, push(push(new_contxt(), $3), $4)); } |
                '(' RUN p ')'               { $$ = new_native(strdup("run"), LINE, m_run, push(new_contxt(), $3)); };
startup:        '(' STARTUP p opts')'       { $$ = new_native(strdup("startup"), LINE, m_startup, push(push(new_contxt(), $3), $4)); };
textfile:       '(' TEXTFILE opts ')'       { $$ = new_native(strdup("textfile"), LINE, m_textfile, $3); }; 
tooltype:       '(' TOOLTYPE opts ')'       { $$ = new_native(strdup("tooltype"), LINE, m_tooltype, $3); }; 
trap:           '(' TRAP p vpb ')'          { $$ = new_native(strdup("trap"), LINE, m_trap, push(push(new_contxt(), $3), $4)); };

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
quiet:          '(' QUIET ')'               { $$ = new_option(strdup("quiet"), OPT_QUIET, NULL); };
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

