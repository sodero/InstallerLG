#ifndef DEBUG_H_
#define DEBUG_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <assert.h>

#define ASSERT(...) assert(__VA_ARGS__)
#define TRACE(...) fprintf (stderr, __VA_ARGS__)
#ifdef __APPLE__
#define LEAK_CHECK if (1) { char leaks[256]; \
                            snprintf(leaks,  \
                            sizeof (leaks),  \
                            "leaks %u >&2",  \
                            getpid());       \
                            system(leaks);   }
#else
#define LEAK_CHECK 
#endif

#endif
