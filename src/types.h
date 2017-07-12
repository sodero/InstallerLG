#ifndef TYPES_H_
#define TYPES_H_

#define SYMSIZE 8 
#define BUFSIZE 256
#define SENTINEL ((entry_p) push)

typedef struct entry_s * entry_p;
typedef entry_p (*call_t) (entry_p);
typedef enum 
{ 
    OPT_ALL,
    OPT_RESIDENT, 
    OPT_NOREQ, 
    OPT_PROMPT,
    OPT_HELP,
    OPT_SOURCE,
    OPT_DEST,
    OPT_NEWNAME,
    OPT_CHOICES,
    OPT_CONFIRM,
    OPT_COMMAND,
    OPT_PATTERN,
    OPT_FILES,
    OPT_INFOS,
    OPT_NOPOSITION,
    OPT_SETTOOLTYPE,
    OPT_SETDEFAULTTOOL,
    OPT_SETSTACK,
    OPT_SETPOSITION, 
    OPT_SWAPCOLORS,
    OPT_NOGAUGE,
    OPT_FAIL,
    OPT_NOFAIL,
    OPT_OKNODELETE,
    OPT_FONTS,
    OPT_FORCE,
    OPT_ASKUSER,
    OPT_SAFE,
    OPT_COMPRESSION,
    OPT_APPEND,
    OPT_INCLUDE,
    OPT_DISK,
    OPT_ASSIGNS,
    OPT_NEWPATH
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
