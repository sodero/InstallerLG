#ifndef UTIL_H_
#define UTIL_H_

#include "types.h"

void eval_print (entry_p entry);
void short_print (entry_p entry);
void pretty_print (entry_p entry);
void print_list(entry_p *entries);
void ror(entry_p *e);
entry_p local(entry_p e);
entry_p global(entry_p e);
entry_p get_opt(entry_p c, opt_t t);
int c_sane(entry_p c, size_t n);
int s_sane(entry_p c, size_t n);

/*
#define DISRES  contxt->resolved
#define DISNUM  contxt->resolved->id
#define DISSTR  contxt->resolved->name
*/
#define RNUM(X) contxt->resolved->id = X; return contxt->resolved
#define RSTR(X) free(contxt->resolved->name); contxt->resolved->name = X; return contxt->resolved
#define CARG(X)  (contxt->children[X - 1])
#define CSYM(X) (contxt->symbols[X - 1])
#endif
