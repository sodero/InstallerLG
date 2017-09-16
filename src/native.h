#ifndef NATIVE_H_
#define NATIVE_H_

#include "alloc.h"
#include "types.h"

entry_p m_gosub(entry_p contxt);
entry_p m_set(entry_p contxt);
entry_p m_procedure(entry_p contxt);
entry_p m_onerror(entry_p contxt);
entry_p m_if(entry_p contxt);
entry_p m_while(entry_p contxt);
entry_p m_until(entry_p contxt);
entry_p m_add(entry_p contxt);
entry_p m_lt(entry_p contxt);
entry_p m_lte(entry_p contxt);
entry_p m_gt(entry_p contxt);
entry_p m_gte(entry_p contxt);
entry_p m_eq(entry_p contxt);
entry_p m_mul(entry_p contxt);
entry_p m_sub(entry_p contxt);
entry_p m_div(entry_p contxt);
entry_p m_fmt(entry_p contxt);
entry_p m_and(entry_p contxt);
entry_p m_or(entry_p contxt);
entry_p m_xor(entry_p contxt);
entry_p m_not(entry_p contxt);
entry_p m_bitand(entry_p contxt);
entry_p m_bitor(entry_p contxt);
entry_p m_bitxor(entry_p contxt);
entry_p m_bitnot(entry_p contxt);
entry_p m_shiftleft(entry_p contxt);
entry_p m_shiftright(entry_p contxt);
entry_p m_in(entry_p contxt);
entry_p m_askdir(entry_p contxt);
entry_p m_askfile(entry_p contxt);
entry_p m_askstring(entry_p contxt);
entry_p m_asknumber(entry_p contxt);
entry_p m_askchoice(entry_p contxt);
entry_p m_askoptions(entry_p contxt);
entry_p m_askbool(entry_p contxt);
entry_p m_askdisk(entry_p contxt);
entry_p m_cat(entry_p contxt);
entry_p m_exists(entry_p contxt);
entry_p m_expandpath(entry_p contxt);
entry_p m_earlier(entry_p contxt);
entry_p m_fileonly(entry_p contxt);
entry_p m_getassign(entry_p contxt);
entry_p m_getdevice(entry_p contxt);
entry_p m_getdiskspace(entry_p contxt);
entry_p m_getenv(entry_p contxt);
entry_p m_getsize(entry_p contxt);
entry_p m_getsum(entry_p contxt);
entry_p m_getversion(entry_p contxt);
entry_p m_iconinfo(entry_p contxt);
entry_p m_pathonly(entry_p contxt);
entry_p m_patmatch(entry_p contxt);
entry_p m_select(entry_p contxt);
entry_p m_strlen(entry_p contxt);
entry_p m_substr(entry_p contxt);
entry_p m_symbolset(entry_p contxt);
entry_p m_symbolval(entry_p contxt);
entry_p m_tackon(entry_p contxt);
entry_p m_transcript(entry_p contxt);
entry_p m_makedir(entry_p contxt);
entry_p m_copyfiles(entry_p contxt);
entry_p m_copylib(entry_p contxt);
entry_p m_startup(entry_p contxt);
entry_p m_tooltype(entry_p contxt);
entry_p m_textfile(entry_p contxt);
entry_p m_execute(entry_p contxt);
entry_p m_run(entry_p contxt);
entry_p m_rexx(entry_p contxt);
entry_p m_makeassign(entry_p contxt);
entry_p m_rename(entry_p contxt);
entry_p m_delete(entry_p contxt);
entry_p m_protect(entry_p contxt);
entry_p m_complete(entry_p contxt);
entry_p m_message(entry_p contxt);
entry_p m_working(entry_p contxt);
entry_p m_welcome(entry_p contxt);
entry_p m_foreach(entry_p contxt);
entry_p m_abort(entry_p contxt);
entry_p m_exit(entry_p contxt);
entry_p m_trap(entry_p contxt);
entry_p m_debug(entry_p contxt);
entry_p m_database(entry_p contxt);

#define SET0 
#define SET1     a1 = contxt->children[0]
#define SET2     a2 = contxt->children[1]; SET1
#define SET3     a3 = contxt->children[2]; SET2
#define SETA(n)  SET##n 
#define ARG0 
#define ARG1     entry_p a1; ARG0
#define ARG2     entry_p a2; ARG1
#define ARG3     entry_p a3; ARG2
#define ARGS(n)  ARG##n SANE(n) SETA(n)
#define FAIL0    error_ng(PANIC);\
                 pretty_print(contxt);\
                 return new_failure()
#define SANE0    contxt &&\
                 contxt->parent &&\
                 contxt->children 
#define SANE1    SANE0 &&\
                 contxt->children[0] &&\
                 contxt->children[0] != end() &&\
                 contxt->children[0]->parent == contxt  
#define SANE2    SANE1 &&\
                 contxt->children[1] &&\
                 contxt->children[1] != end() &&\
                 contxt->children[1]->parent == contxt  
#define SANE3    SANE2 &&\
                 contxt->children[2] &&\
                 contxt->children[2] != end() &&\
                 contxt->children[2]->parent == contxt  
#define SANE(n)  if(!(SANE##n)) { FAIL0; }
/*
#define RNUM(X)  contxt->resolved->id = X; return contxt->resolved
#define RSTR(X)  free(contxt->resolved->name); contxt->resolved->name = X; return contxt->resolved
*/

#endif
