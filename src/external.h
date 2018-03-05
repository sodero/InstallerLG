//----------------------------------------------------------------------------
// external.h: 
//
// Execution of external scripts / binaries
//
//----------------------------------------------------------------------------

#ifndef EXTERNAL_H_
#define EXTERNAL_H_

#include "types.h"

entry_p m_execute(entry_p contxt);
entry_p m_rexx(entry_p contxt);
entry_p m_run(entry_p contxt);

#endif
