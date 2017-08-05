#ifndef EVAL_H_
#define EVAL_H_

#include "types.h"

void run(entry_p entry);
entry_p invoke(entry_p entry);
entry_p clone(entry_p entry); // Temp
entry_p resolve(entry_p entry);

int num(entry_p entry);
const char *str(entry_p entry);

#endif
