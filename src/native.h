#ifndef NATIVE_H_
#define NATIVE_H_

#include "alloc.h"
#include "types.h"

entry_p m_gosub(entry_p contxt);
entry_p m_set(entry_p contxt);
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
entry_p m_strlen(entry_p contxt);
entry_p m_substr(entry_p contxt);
entry_p m_select(entry_p contxt);
entry_p m_symbolset(entry_p contxt);
entry_p m_symbolval(entry_p contxt);

#define ONLY(A)\
entry_p A;\
if(contxt &&\
   contxt->parent &&\
   contxt->children &&\
   contxt->children[0] &&\
   contxt->children[0] != SENTINEL &&\
   contxt->children[0]->parent == contxt)\
{\
    A = contxt->children[0];\
}\
else\
{\
    error(PANIC);\
    pretty_print(contxt);\
    return new_failure();\
}

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
