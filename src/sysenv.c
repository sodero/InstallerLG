#include <string.h>
#include "sysenv.h"
#include "alloc.h"
  
void bootstrap(entry_p contxt)
{
    push(contxt, 
        new_symbol(strdup("@default-dest"), 
            new_string(strdup("Work:")))); 
/*
`@default-dest'
3367      directory where install wants to put things by default.
3368
3369 `@each-name'
3370 `@each-type'
3371      used in @{"`foreach'" Link "cs_foreach"}.
3372
3373 `@error-msg'
3374      message that would be displayed if error not trapped. See @{"`trap'" Link "cs_trap"}.
3375
3376 `@execute-dir'
3377      Installer will change to this directory before performing a
3378      statement @{"`run'" Link "s_run"}, or @{"`execute'" Link "s_execute"}.
3379
3380 `@icon'
3381      pathname of install start icon on WB start or (V42.12) install
3382      script on Shell start.
3383
3384 `@installer-version'
3385      Installer program version in `version' format.
3386
3387 `@language'
3388      language specified in tooltypes/Shell (locale name if available or
3389      `"english"').
3390
3391 `@pretend'
3392      state of `pretend' (dry run mode) flag: 0-Real, 1-Pretend.
3393
3394 `@special-msg'
3395      custom fatal error message.
3396
3397 `@user-level'
3398      0-Novice, 1-Average, 2-Expert.
*/
}

