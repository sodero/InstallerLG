#ifndef NATIVE_H_
#define NATIVE_H_

#include "alloc.h"
#include "types.h"

entry_p eval(entry_p entry);

entry_p m_cus(entry_p contxt);
entry_p m_set(entry_p contxt);
entry_p m_add(entry_p contxt);

int m_sub(int a, int b);
int m_mul(int a, int b);
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

#define S_CHECK(X) CHECK(X,symbols,contxt)
#define C_CHECK(X) CHECK(X,children,contxt)

#define CHECK(X,W,Q) \
if(1) { \
  int ok = 1; \
  if(Q->parent && \
     Q->W) \
  { int i = 0; \
    while (i < X) { \
      if(!Q->W[i] || \
        Q->W[i] == \
        SENTINEL ) { ok = 0; break; } i++; } \
  } else { ok = 0; } \
  if(!ok) { error(PANIC); return new_failure(); }}

#endif
