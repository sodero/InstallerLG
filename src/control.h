//----------------------------------------------------------------------------
// control.h: 
//
// Control structures
//
//----------------------------------------------------------------------------

#ifndef CONTROL_H_
#define CONTROL_H_

#include "types.h"

entry_p m_if(entry_p contxt);
entry_p m_select(entry_p contxt);
entry_p m_until(entry_p contxt);
entry_p m_while(entry_p contxt);

#endif
