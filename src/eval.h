#ifndef EVAL_H_
#define EVAL_H_

#include "types.h"

void run(entry_p entry);
entry_p invoke(entry_p entry);
entry_p resolve(entry_p entry);
entry_p number(entry_p entry);
entry_p string(entry_p entry);

#endif
