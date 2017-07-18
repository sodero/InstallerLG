#ifndef ALLOC_H_
#define ALLOC_H_

#include "types.h"

entry_p new_dangle(void); 
entry_p new_contxt(void); 
entry_p new_number(int n); 
entry_p new_string(char *n); 
entry_p new_symbol(char *n, entry_p e); 
entry_p new_custom(char *n, int l, entry_p s, entry_p c); 
entry_p new_native(char *n, int l, call_t call, entry_p e); 
entry_p new_option(char *n, opt_t t, entry_p e); 
entry_p new_symref(char *n, int l);
entry_p new_cusref(char *n, int l, entry_p e); 
entry_p new_success(void); 
entry_p new_failure(void); 

void kill(entry_p entry);
entry_p push(entry_p dst, entry_p src);
entry_p end(void); 

#endif
