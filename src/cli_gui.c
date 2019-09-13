//------------------------------------------------------------------------------
// cligui.c:
//
// CLI GUI.
//
//------------------------------------------------------------------------------
// Copyright (C) 2018-2019, Ola Söder. All rights reserved.
// Licensed under the AROS PUBLIC LICENSE (APL) Version 1.1
//------------------------------------------------------------------------------

#include "gui.h"

#include <stdio.h>

#include <stdlib.h>

#ifndef __GNUC__
#define __attribute__(a)
typedef LONG IPTR;
#endif

inp_t gui_init(bool scr)
{
    return G_TRUE;
}

void gui_exit(void)
{
    printf("Exiting\n");
}

inp_t gui_message(const char *msg, bool bck)
{
    printf("%s\n", msg);
    return G_TRUE;
}

inp_t gui_finish(const char *msg)
{
    return G_TRUE;
}

inp_t gui_working(const char *msg)
{
    printf("%s\n", msg);
    return G_TRUE;
}

void gui_abort(const char *msg)
{
    printf("Aborting\n");
}

inp_t gui_choice(const char *msg, const char *hlp, const char **nms, int def,
                 bool bck, int *ret)
{
    return G_TRUE;
}

inp_t gui_options(const char *msg, const char *hlp, const char **nms, int def,
                  bool bck, int *ret)
{
    return G_TRUE;
}

inp_t gui_bool(const char *msg, const char *hlp, const char *yes,
               const char *nay, bool bck)
{
    return G_TRUE;
}

inp_t gui_string(const char *msg,
                 const char *hlp,
                 const char *def,
                 bool bck,
                 const char **ret)
{
    return G_TRUE;
}

inp_t gui_number(const char *msg,
                 const char *hlp,
                 int min,
                 int max,
                 int def,
                 bool bck,
                 int *ret)
{
    return G_TRUE;
}

inp_t gui_welcome(const char *msg, int *lvl, int *lgf, int *prt, int min,
                  bool npr, bool nlg)
{
    printf("%s", msg);
    return G_TRUE;
}

inp_t gui_askdir(const char *msg, const char *hlp, bool pth, bool dsk, bool asn,
                 const char *def, bool bck, const char **ret)
{
    return G_TRUE;
}

inp_t gui_askfile(const char *msg, const char *hlp, bool pth, bool dsk,
                  const char *def, bool bck, const char **ret)
{
    return G_TRUE;
}

inp_t gui_copyfiles_start(const char *msg, const char *hlp, pnode_p lst,
                          bool cnf, bool bck)
{
    return G_TRUE;
}

inp_t gui_copyfiles_setcur(const char *cur, bool nga, bool bck)
{
    return G_TRUE;
}

void gui_copyfiles_end(void)
{

}

void gui_complete(int com)
{
    printf("Progress: %d% complete.\n", com);
}

inp_t gui_confirm(const char *msg, const char *hlp, bool bck)
{
    printf("Confirm\n");
    printf("%s\n", msg);
    char response[5];
    do {
        printf("Y(confirm)/N(cancel)/H(help) > ");
        fgets(response, 5, stdin);
        if(strcmp(response, "H\n") == 0) {
            printf("%s\n", hlp);
        }
    } while(strcmp(response, "Y\n") != 0 && strcmp(response, "N\n") != 0);
    return strcmp(response, "Y\n") == 0 ? G_TRUE : G_FALSE;
}

void gui_error(int line, const char *type, const char *info)
{
    printf("Error of type %s on line %d.", type, line);
    printf("Error info: %s", info);
}

void gui_effect(int eff, int cl1, int cl2)
{
    printf("Image effect %d with colors %d and %d", eff, cl1, cl2);
}

inp_t gui_closemedia(int mid)
{
    return G_TRUE;
}

inp_t gui_setmedia(int mid, int act, const char *par)
{
    return G_TRUE;
}

inp_t gui_showmedia(int *mid, const char* mda, int act)
{
    return G_TRUE;
}

