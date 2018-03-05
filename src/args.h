//----------------------------------------------------------------------------
// args.h: 
//
// Functions and data types for handling command line arguments and workbench 
// tooltypes. 
//----------------------------------------------------------------------------

#ifndef ARGS_H_
#define ARGS_H_

enum 
{
    ARG_SCRIPT = 0,
    ARG_APPNAME,
    ARG_MINUSER,
    ARG_DEFUSER,
    ARG_LOGFILE,
    ARG_NOLOG, 
    ARG_NOPRETEND,
    ARG_NUMBER_OF 
};

int arg_init(int argc, char **argv);
char *arg_get(int ndx);
int arg_argc(int argc);
void arg_done(void);

#endif
