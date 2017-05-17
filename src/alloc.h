#ifndef ALLOC_H_
#define ALLOC_H_

#include "types.h"

entry_p new_dangle(void); 
entry_p new_contxt(void); 
entry_p new_number(int n); 
entry_p new_string(char *n); 
entry_p new_symbol(char *n, entry_p e); 
entry_p new_custom(char *n, entry_p s, entry_p c); 
entry_p new_native(call_t call, entry_p e); 
entry_p new_symref(char *n, int l);
entry_p new_cusref(char *n, int l, entry_p e); 
entry_p new_success(void); 
entry_p new_failure(void); 

void kill(entry_p entry);
void push(entry_p dst, entry_p src);

#endif
