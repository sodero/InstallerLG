#ifndef NATIVE_H_
#define NATIVE_H_

#include "alloc.h"
#include "types.h"

entry_p eval(entry_p entry);

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

#define CCHECK(X) \
if(1) { \
  int ok = 1; \
  if(contxt->children) { \
    int i = 0; \
    while (i < X) { \
      if(!contxt->children[i] || \
        contxt->children[i] == \
        SENTINEL ) { ok = 0; break; } i++; } \
  } else { ok = 0; } \
  if(!ok) { \
    error(__LINE__, "Internal error", \
          __func__); \
    return new_failure(NULL); } }

#endif
