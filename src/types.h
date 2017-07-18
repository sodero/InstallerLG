#ifndef TYPES_H_
#define TYPES_H_

#define VECLEN 4 
#define NUMLEN 16
#define BUFSIZE 4096
#define SENTINEL ((entry_p) push)

typedef struct entry_s * entry_p;
typedef entry_p (*call_t) (entry_p);
typedef enum 
{ 
    OPT_ALL,
    OPT_APPEND,
    OPT_ASKUSER,
    OPT_ASSIGNS,
    OPT_CHOICES,
    OPT_COMMAND,
    OPT_COMPRESSION,
    OPT_CONFIRM,
    OPT_DEFAULT,
    OPT_DELOPTS, 
    OPT_DEST,
    OPT_DISK,
    OPT_FAIL,
    OPT_FILES,
    OPT_FONTS,
    OPT_FORCE,
    OPT_HELP,
    OPT_INFOS,
    OPT_INCLUDE,
    OPT_NEWNAME,
    OPT_NEWPATH,
    OPT_NOFAIL,
    OPT_NOGAUGE,
    OPT_NOPOSITION,
    OPT_NOREQ, 
    OPT_OKNODELETE,
    OPT_PATTERN,
    OPT_PROMPT,
    OPT_QUIET,
    OPT_RANGE, 
    OPT_SAFE,
    OPT_SETDEFAULTTOOL,
    OPT_SETSTACK,
    OPT_SETTOOLTYPE,
    OPT_SOURCE,
    OPT_SWAPCOLORS,
    OPT_OPTIONAL,
    OPT_RESIDENT 
} opt_t; 
typedef enum 
{
    NUMBER,
    STRING, 
    SYMBOL,
    SYMREF,
    NATIVE, 
    OPTION, 
    CUSTOM, 
    CUSREF, 
    CONTXT,
    STATUS,
    DANGLE
} type_t;

struct entry_s
{
    type_t type; 
    int id; 
    char *name; 
    call_t call; 
    entry_p expression; 
    entry_p resolved; 
    entry_p *children; 
    entry_p *symbols; 
    entry_p parent; 
}; 

typedef struct entry_s entry_t; 

#endif
