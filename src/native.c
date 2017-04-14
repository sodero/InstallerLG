#include <stdio.h>
#include "native.h"

/*
hidden top level function 
*/
entry_p eval(entry_p entry)
{ 
    int u = used (entry);
    if (u)
    {
        int i = 0; 
        while (i < u)
        {
            entry_p stmt = entry->value.native.args[i]; 
            if (stmt->type == NATIVE)
            {
                call_t call = stmt->value.native.call;
                entry_p *args = stmt->value.native.args; 
                if (call && args)
                {
                    entry_p result = call (args); 
                    pretty_print (result);
                }
            }
            i++; 
        }
    }
    return 0;
}

/*
`(+ <expr1> <expr2> ...)'
     returns sum of expressions
*/
entry_p m_add (entry_p *argv)
{
    int a = argv[0]->value.number, 
        b = argv[1]->value.number; 
    entry_p entry = new_number (a + b); 

    printf("a:%d (%p)\n", a, argv[0]);
    printf("b:%d (%p)\n", b, argv[1]);

    return entry;  
}

/* 
`(- <expr1> <expr2>)'
     returns `<expr1>' minus `<expr2>'
*/
int m_sub(int a, int b)
{
    return a - b; 
}

/*
`(* <expr1> <expr2> ...)'
     returns product of expressions
*/
int m_mul(int a, int b)
{
    return a * b; 
}

/* 
`(/ <expr1> <expr2>)'
     returns `<expr1>' divided by `<expr2>'
*/
int m_div(int a, int b)
{
    return a / (b ? b : 1); 
}

/* 
`(AND <expr1> <expr2>)'
     returns logical `AND' of `<expr1>' and `<expr2>'
*/
int m_and(int a, int b)
{
    return a && b; 
}

/* 
`(OR <expr1> <expr2>)'
     returns logical `OR' of `<expr1>' and `<expr2>'
*/
int m_or(int a, int b)
{
    return a || b; 
}

/* 
`(XOR <expr1> <expr2>)'
     returns logical `XOR' of `<expr1>' and `<expr2>'
*/
int m_xor(int a, int b)
{
    return (a && !b) || (!a && b); 
}

/* 
`(NOT <expr>)'
     returns logical `NOT' of `<expr>'
*/
int m_not(int a)
{
    return !a; 
}

/* 
`(BITAND <expr1> <expr2>)'
     returns bitwise `AND' of `<expr1>' and `<expr2>'
*/
int m_bitand(int a, int b)
{
    return a & b; 
}

/* 
`(BITOR <expr1> <expr2>)'
     returns bitwise `OR' of `<expr1>' and `<expr2>'
*/
int m_bitor(int a, int b)
{
    return a | b; 
}

/* 
`(BITXOR <expr1> <expr2>)'
     returns bitwise `XOR' of `<expr1>' and `<expr2>'
*/
int m_bitxor(int a, int b)
{
    return a ^ b; 
}

/* 
`(BITNOT <expr>)'
     returns bitwise `NOT' of `<expr>'
*/
int m_bitnot(int a)
{
    return ~a; 
}

/* 
`(shiftleft <number> <amount to shift>)'
     logical shift left
*/
int m_shiftleft(int a, int n)
{
    return a << n; 
}

/* 
`(shiftright <number> <amount to shift>)'
     logical shift right
*/
int m_shiftright(int a, int n)
{
    return a >> n; 
}

/*

- varje funktion tar samma argument, en struct
  som innehaller:
    - int antalet argument (in) n
    - symboltabellindex till forsta argument (in)
       - de foljer pa varandra i tabellen
       - returvardet ligger i nastkommande index 

- returnerar pekare till nasta funktion
  som ska anropas? nej, det behovs inte. alla
  funktioner (inkl. toppnoden, se nedan) har koll
  pa sina argument.  

- symboltabellen innehaller ung. samma saker
  som node_t. den maste ha minst en typ till; 
  funktion. 

- toppnoden, programmet, ar ocksa en funktion som 
  tar n antal argument

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
