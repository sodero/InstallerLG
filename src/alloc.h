#ifndef ALLOC_H_
#define ALLOC_H_

#include "types.h"

entry_p create_s(); 
entry_p create_b(int nargs); 
void destroy (entry_p entry);
int n_used (entry_p entry);
int n_free (entry_p entry);

#endif
