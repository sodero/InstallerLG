#ifndef ALLOC_H_
#define ALLOC_H_

#include "types.h"

entry_p new_contxt(); 
entry_p new_number(int n); 
entry_p new_string(char *s); 
entry_p new_symbol(char *s, entry_p e); 
entry_p new_symref(char *s, int l);
entry_p new_native(call_t call, int nargs); 
entry_p new_cusref(char *s, entry_p e); 

entry_p new_success(); 
entry_p new_failure(char *s); 

void kill(entry_p entry);
void push(entry_p dst, entry_p src);

#endif
