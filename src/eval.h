#ifndef EVAL_H_
#define EVAL_H_

#include "types.h"

entry_p eval_as_number(entry_p entry);
entry_p eval_as_string(entry_p entry);
entry_p eval_as_stdout(entry_p entry);

#endif
