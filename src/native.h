#ifndef NATIVE_H_
#define NATIVE_H_

#include "alloc.h"
#include "types.h"

entry_p m_gosub(entry_p contxt);
entry_p m_set(entry_p contxt);
entry_p m_if(entry_p contxt);
entry_p m_while(entry_p contxt);
entry_p m_add(entry_p contxt);
entry_p m_lt(entry_p contxt);
entry_p m_lte(entry_p contxt);
entry_p m_gt(entry_p contxt);
entry_p m_gte(entry_p contxt);
entry_p m_eq(entry_p contxt);
entry_p m_mul(entry_p contxt);

int m_sub(int a, int b);
int m_div(int a, int b);
int m_and(int a, int b);
int m_or(int a, int b);
int m_xor(int a, int b);
int m_not(int a);
int m_bitand(int a, int b);
int m_bitor(int a, int b);
int m_bitxor(int a, int b);
int m_bitnot(int a);
int m_shiftleft(int a, int n);
int m_shiftright(int a, int n);

#define TWINS(A,B)\
entry_p A, B;\
if(contxt &&\
   contxt->parent &&\
   contxt->children &&\
   contxt->children[0] &&\
   contxt->children[0] != SENTINEL &&\
   contxt->children[0]->parent == contxt &&\
   contxt->children[1] &&\
   contxt->children[1] != SENTINEL &&\
   contxt->children[1]->parent == contxt)\
{\
    A = contxt->children[0];\
    B = contxt->children[1];\
}\
else\
{\
    error(PANIC);\
    pretty_print(contxt);\
    return new_failure();\
}

#define TRIPLES(A,B,C)\
entry_p A, B, C;\
if(contxt &&\
   contxt->parent &&\
   contxt->children &&\
   contxt->children[0] &&\
   contxt->children[0] != SENTINEL &&\
   contxt->children[0]->parent == contxt &&\
   contxt->children[1] &&\
   contxt->children[1] != SENTINEL &&\
   contxt->children[1]->parent == contxt &&\
   contxt->children[2] &&\
   contxt->children[2] != SENTINEL &&\
   contxt->children[2]->parent == contxt)\
{\
    A = contxt->children[0];\
    B = contxt->children[1];\
    C = contxt->children[2];\
}\
else\
{\
    error(PANIC);\
    pretty_print(contxt);\
    return new_failure();\
}

#endif
