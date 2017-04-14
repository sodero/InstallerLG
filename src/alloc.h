#ifndef ALLOC_H_
#define ALLOC_H_

#include "types.h"

entry_p create_s(); 
entry_p create_b(int nargs); 
entry_p create_num(int n); 
void kill (entry_p entry);
void push (entry_p dst, entry_p src);
int n_used (entry_p entry);
int n_free (entry_p entry);

#endif
