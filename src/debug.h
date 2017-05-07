#ifndef DEBUG_H_
#define DEBUG_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define TRACE(...) fprintf (stderr, __VA_ARGS__)

void leak_check();

#endif
