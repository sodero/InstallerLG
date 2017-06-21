#include <string.h>
#include "sysenv.h"
#include "alloc.h"
#include "util.h"
#include "native.h"
  
entry_p init(entry_p contxt)
{
    push(contxt, new_native(strdup("set"), __LINE__, m_set, push(new_contxt(), 
                 new_symbol(strdup("@init-done"), 
                 new_string(strdup("")))))); ror(contxt->children);
    push(contxt, new_native(strdup("set"), __LINE__, m_set, push(new_contxt(), 
                 new_symbol(strdup("@default-dest"), 
                 new_string(strdup("Work:")))))); ror(contxt->children);
    push(contxt, new_native(strdup("set"), __LINE__, m_set, push(new_contxt(), 
                 new_symbol(strdup("@error-msg"), 
                 new_string(strdup("Unknown error")))))); ror(contxt->children);
    push(contxt, new_native(strdup("set"), __LINE__, m_set, push(new_contxt(), 
                 new_symbol(strdup("@execute-dir"), 
                 new_string(strdup("-")))))); ror(contxt->children);
    push(contxt, new_native(strdup("set"), __LINE__, m_set, push(new_contxt(), 
                 new_symbol(strdup("@icon"), 
                 new_string(strdup("-")))))); ror(contxt->children);
    push(contxt, new_native(strdup("set"), __LINE__, m_set, push(new_contxt(), 
                 new_symbol(strdup("@installer-version"), 
                 new_string(strdup("V43.3")))))); ror(contxt->children);
    push(contxt, new_native(strdup("set"), __LINE__, m_set, push(new_contxt(), 
                 new_symbol(strdup("@language"), 
                 new_string(strdup("english")))))); ror(contxt->children);
    push(contxt, new_native(strdup("set"), __LINE__, m_set, push(new_contxt(), 
                 new_symbol(strdup("@pretend"), 
                 new_number(1))))); ror(contxt->children);
    push(contxt, new_native(strdup("set"), __LINE__, m_set, push(new_contxt(), 
                 new_symbol(strdup("@special-msg"), 
                 new_string(strdup("Custom error")))))); ror(contxt->children);
    push(contxt, new_native(strdup("set"), __LINE__, m_set, push(new_contxt(), 
                 new_symbol(strdup("@user-level"), 
                 new_number(2))))); ror(contxt->children);
    return contxt; 
/*
3369 `@each-name'
3370 `@each-type'
3371      used in @{"`foreach'" Link "cs_foreach"}.
*/
}

