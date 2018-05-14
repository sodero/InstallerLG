//----------------------------------------------------------------------------
// alloc.h: 
//
// Functions for allocation of entry_t data and closely related functions.
//----------------------------------------------------------------------------

#ifndef ALLOC_H_
#define ALLOC_H_

#include "types.h"

//----------------------------------------------------------------------------
// Allocation of entry_t types.
//----------------------------------------------------------------------------
entry_p new_dangle(void); 
entry_p new_contxt(void); 
entry_p new_number(int n); 
entry_p new_failure(void); 
entry_p new_string(char *n); 
entry_p new_symbol(char *n); 
entry_p new_symref(char *n, int l);
entry_p new_cusref(char *n, int l, entry_p e); 
entry_p new_option(char *n, opt_t t, entry_p e); 
entry_p new_custom(char *n, int l, entry_p s, entry_p c); 
entry_p new_native(char *n, int l, call_t call, entry_p e, type_t r); 

//----------------------------------------------------------------------------
// Utilities. 
//----------------------------------------------------------------------------
void kill(entry_p entry);
entry_p append(entry_p **dst, entry_p e);
entry_p push(entry_p dst, entry_p src);
entry_p end(void); 

//----------------------------------------------------------------------------
// Macros. 
//----------------------------------------------------------------------------

#ifdef OOM
#define CALLOC(N,S) NULL
#define MALLOC(N) NULL
#define STRDUP(S) NULL
#else
#define CALLOC(N,S) calloc((N),(S)) 
#define MALLOC(N) malloc((N))
#define STRDUP(S) strdup((S))
#endif

#endif
