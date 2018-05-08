//----------------------------------------------------------------------------
// gui.h: 
//
// MUI based GUI
//
//----------------------------------------------------------------------------

#ifndef GUI_H_
#define GUI_H_

#include "file.h"

int gui_init(void);
void gui_exit(void);
void gui_welcome(const char *msg, int *lvl, int *lgf, int *prt);
void gui_message(const char *msg, int imm); 
int gui_confirm(const char *msg); 
int gui_bool(const char *msg, const char *hlp, const char *yes, const char *no); 
int gui_choice(const char *msg, const char *hlp, const char **nms, int def); 
const char * gui_string(const char *msg, const char *hlp, const char *def, int *hlt); 
int gui_number(const char *msg, const char *hlp, int min, int max, int def, int *hlt); 
int gui_options(const char *msg, const char *hlp, const char **nms, int def); 
int gui_error(int id, const char *type, const char *info);
const char *gui_askdir(const char *msg, const char *hlp, int pth, int dsk, int asn, const char *def);
const char *gui_askfile(const char *msg, const char *hlp, int pth, int dsk, const char *def);
int gui_copyfiles_start(const char *msg, const char *hlp, pnode_p lst, int cnf); 
int gui_copyfiles_setcur(const char *cur, int nogauge); 
void gui_copyfiles_end(void); 
int gui_complete(int com); 
int gui_run(const char *msg, const char *hlp); 

#endif
