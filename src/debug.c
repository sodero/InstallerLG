#include "debug.h"

void leak_check()
{
#ifdef __APPLE__
    char leaks[256]; 
    snprintf(leaks, sizeof (leaks), "leaks %u > /dev/null", getpid());       
    if(system(leaks))
    {
        snprintf(leaks, sizeof (leaks), "leaks %u >&2", getpid());       
        system(leaks);  
    }
#endif
}
