#ifndef ALLOC_H_
#define ALLOC_H_

#include "types.h"

entry_p new_s (); 
entry_p new_native (call_t call, int nargs); 
entry_p new_number (int n); 

void kill (entry_p entry);
void push (entry_p dst, entry_p src);

int used (entry_p entry);
int left (entry_p entry);

#endif
