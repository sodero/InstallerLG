#include "builtin.h"

/* + */
int add(int a, int b)
{
    return a + b; 
}

/* - */
int sub(int a, int b)
{
    return a - b; 
}

/* * */
int mul(int a, int b)
{
    return a * b; 
}

/* / */
int div(int a, int b)
{
    return a / (b ? b : 1); 
}


/*
message
=  
>  
>= 
<  
<= 
<> 
AND 
OR  
XOR 
NOT 
BITAND 
BITOR  
BITXOR 
BITNOT
shiftleft 
shiftright
IN 
set
symbolset
cat
substr
strlen
exists
makedir
copyfiles
textfile
rename
delete
procedure
welcome
copylib
startup
tooltype
execute
run
rexx
makeassign
protect
complete
working
user
debug
transcript
tackon
fileonly
pathonly
expandpath
askdir
askfile
askstring
asknumber
askchoice
askoptions
askbool
askdisk
earlier
getsize
getdevice
getdiskspace
getsum
getversion
getenv
getassign
iconinfo
database
select
patmatch
symbolval
*/
