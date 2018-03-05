//----------------------------------------------------------------------------
// exit.h: 
//
// Interuption of program execution
//
//----------------------------------------------------------------------------

#ifndef EXIT_H_
#define EXIT_H_

#include "types.h"

entry_p m_abort(entry_p contxt);
entry_p m_exit(entry_p contxt);
entry_p m_onerror(entry_p contxt);
entry_p m_trap(entry_p contxt);

#endif
