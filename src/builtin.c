#include "builtin.h"

/*
`(+ <expr1> <expr2> ...)'
     returns sum of expressions
*/
int add(int a, int b)
{
    return a + b; 
}

/* 
`(- <expr1> <expr2>)'
     returns `<expr1>' minus `<expr2>'
*/
int sub(int a, int b)
{
    return a - b; 
}

/*
`(* <expr1> <expr2> ...)'
     returns product of expressions
*/
int mul(int a, int b)
{
    return a * b; 
}

/* 
`(/ <expr1> <expr2>)'
     returns `<expr1>' divided by `<expr2>'
*/
int div(int a, int b)
{
    return a / (b ? b : 1); 
}

/* 
`(AND <expr1> <expr2>)'
     returns logical `AND' of `<expr1>' and `<expr2>'
*/
int and(int a, int b)
{
    return a && b; 
}

/* 
`(OR <expr1> <expr2>)'
     returns logical `OR' of `<expr1>' and `<expr2>'
*/
int or(int a, int b)
{
    return a || b; 
}

/* 
`(XOR <expr1> <expr2>)'
     returns logical `XOR' of `<expr1>' and `<expr2>'
*/
int xor(int a, int b)
{
    return (a && !b) || (!a && b); 
}

/* 
`(NOT <expr>)'
     returns logical `NOT' of `<expr>'
*/
int not(int a)
{
    return !a; 
}

/* 
`(BITAND <expr1> <expr2>)'
     returns bitwise `AND' of `<expr1>' and `<expr2>'
*/
int bitand(int a, int b)
{
    return a & b; 
}

/* 
`(BITOR <expr1> <expr2>)'
     returns bitwise `OR' of `<expr1>' and `<expr2>'
*/
int bitor(int a, int b)
{
    return a | b; 
}

/* 
`(BITXOR <expr1> <expr2>)'
     returns bitwise `XOR' of `<expr1>' and `<expr2>'
*/
int bitxor(int a, int b)
{
    return a ^ b; 
}

/* 
`(BITNOT <expr>)'
     returns bitwise `NOT' of `<expr>'
*/
int bitnot(int a)
{
    return ~a; 
}

/* 
`(shiftleft <number> <amount to shift>)'
     logical shift left
*/
int shiftleft(int a, int n)
{
    return a << n; 
}

/* 
`(shiftright <number> <amount to shift>)'
     logical shift right
*/
int shiftright(int a, int n)
{
    return a >> n; 
}

/* 
`(IN <expr> <bit-number> <bitnumber>...)'
     returns `<expr>' `AND' bits

Returns 0 if none of the given bit numbers (starting at 0 for the
LSB) is set in the result of expression, else returns a mask of the
bits that were set.

*/



/*
message
=  
>  
>= 
<  
<= 
<> 
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
