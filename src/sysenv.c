#include <string.h>
#include "sysenv.h"
#include "alloc.h"
  
void bootstrap(entry_p contxt)
{
    push(contxt, 
        new_symbol(strdup("@version"), 
            new_string(strdup("1.0")))); 
}

