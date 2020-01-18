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
    printf("Aborting %s\n", msg);
}

int countList(const char** listOfStrings) {
    int max = 0;
    const char **countingStrings = listOfStrings;

    if(!*countingStrings) return 0;

    while(*countingStrings)
    {
        max++;
        countingStrings++;
    }
    max--;

    return max;
}

void printList(const char** listOfStrings) {
    int opt = 0;
    const char **printingStrings = listOfStrings;

    if(!*printingStrings) return;

    while(*printingStrings)
    {
        printf("%d: %s\n", opt, *printingStrings);
        opt++;
        printingStrings++;
    }
}

inp_t gui_choice(const char *msg, const char *hlp, const char **nms, int def, bool bck, int *ret)
{
    int max = countList(nms);

    printf("%s\n", msg);
    printf("Choose a number between 0 and %d (default is %d, H for help)\n", max, def);
    char response[5];
    bool choseAnswer = false;
    do {
        printList(nms);
        printf("Enter number > ");
        fgets(response, 12, stdin);
        if(strcmp(response, "H\n") == 0) {
            printf("%s\n", hlp);
        } else if(strcmp(response, "\n") == 0) {
            *ret = 1UL << def;
            choseAnswer = true;
        } else if(strcmp(response, "0\n") == 0) {
            *ret = 1;
            choseAnswer = true;
        } else {
            int res = atoi(response);
            if(res != 0) {
                if(res >= 0 && res <= max) {
                    *ret = 1UL << res;
                    choseAnswer = true;
                } else {
                    printf("Number should be between 0 and %d\n", max);
                }
            }
        }
    } while(choseAnswer == false);
    return G_TRUE;
}

void printListWithSelection(const char** listOfStrings, int selected) {
    int opt = 0;
    const char **printingStrings = listOfStrings;

    if(!*printingStrings) return;

    while(*printingStrings)
    {
        char selectedOption = (selected & (1UL << opt)) ? 'X' : ' ';
        printf("%d: [%c] - %s\n", opt, selectedOption, *printingStrings);
        opt++;
        printingStrings++;
    }
}

inp_t gui_options(const char *msg, const char *hlp, const char **nms, int def, bool bck, int *ret)
{
    int max = countList(nms);
    int selected = def;

    printf("%s\n", msg);
    char response[5];
    bool finished = false;
    do {
        printListWithSelection(nms, selected);
        printf("Choose a number to toggle option (H for help, C to accept) > ");
        printf("%d\n", selected);
        fgets(response, 12, stdin);
        if(strcmp(response, "H\n") == 0) {
            printf("%s\n", hlp);
        } else if(strcmp(response, "C\n") == 0) {
            finished = true;
        } else if(strcmp(response, "0\n") == 0) {
            selected = selected ^ 1UL;
        } else {
            int res = atoi(response);
            if(res != 0) {
                if(res >= 0 && res <= max) {
                    selected = selected ^ (1UL << res);
                } else {
                    printf("Number should be between 0 and %d\n", max);
                }
            } else {
                printf("Number should be between 0 and %d\n", max);
            }
        }
    } while(finished == false);
    *ret = selected;
    return G_TRUE;
}

inp_t gui_bool(const char *msg, const char *hlp, const char *yes, const char *nay, bool bck)
{
    char response[5];
    printf("%s\n", msg);
    printf("Pick an option (H for help)\n");
    do {
        printf("Y: %s\n", yes);
        printf("N: %s\n", nay);
        printf("Y or N > ");
        fgets(response, 5, stdin);
        if(strcmp(response, "H\n") == 0) {
            printf("%s\n", hlp);
        } else if(strcmp(response, "Y\n") == 0 || strcmp(response, "Yes\n") == 0) {
            return G_TRUE;
        } else if(strcmp(response, "N\n") == 0 || strcmp(response, "No\n") == 0) {
            return G_FALSE;
        }
    } while(true);
}

inp_t gui_string(const char *msg, const char *hlp, const char *def, bool bck, const char **ret)
{
    printf("%s\n", msg);
    printf("Enter a string (default is '%s', H for help)\n", def);
    char response[255];
    bool choseAnswer = false;
    do {
        printf("Enter string > ");
        fgets(response, 255, stdin);
        if(strcmp(response, "H\n") == 0) {
            printf("%s\n", hlp);
        } else if(strcmp(response, "\n") == 0) {
            *ret = def;
            choseAnswer = true;
        } else  {
            strcpy(*ret, response);
            choseAnswer = true;
        }
    } while(choseAnswer == false);
    return G_TRUE;
}

inp_t gui_number(const char *msg, const char *hlp, int min, int max, int def, bool bck, int *ret)
{
    printf("%s\n", msg);
    printf("Choose a number between %d and %d (default is %d, H for help)\n", min, max, def);
    char response[12];
    bool choseAnswer = false;
    do {
        printf("Enter number > ");
        fgets(response, 12, stdin);
        if(strcmp(response, "H\n") == 0) {
            printf("%s\n", hlp);
        } else if(strcmp(response, "\n") == 0) {
            *ret = def;
            choseAnswer = true;
        } else if(strcmp(response, "0\n") == 0) {
            *ret = 0;
            choseAnswer = true;
        } else {
            int res = atoi(response);
            if(res != 0) {
                if(res >= min && res <= max) {
                    *ret = res;
                    choseAnswer = true;
                } else {
                    printf("Number should be between %d and %d\n", min, max);
                }
            }
        }
    } while(choseAnswer == false);
    return G_TRUE;
}

inp_t gui_welcome(const char *msg, int *lvl, int *lgf, int *prt, int min, bool npr, bool nlg)
{
    printf("%s", msg);
    return G_TRUE;
}

inp_t gui_askdir(const char *msg, const char *hlp, bool pth, bool dsk, bool asn,
                const char *def, bool bck, const char **ret)
{
    printf("%s\n", msg);
    printf("Enter a directory path (default is '%s', H for help)\n", def);
    char response[1024];
    bool choseAnswer = false;
    do {
        printf("Enter path > ");
        fgets(response, 1024, stdin);
        if(strcmp(response, "H\n") == 0) {
            printf("%s\n", hlp);
        } else if(strcmp(response, "\n") == 0) {
            *ret = def;
            choseAnswer = true;
        } else  {
            strcpy(*ret, response);
            choseAnswer = true;
        }
    } while(choseAnswer == false);
    return G_TRUE;
}

inp_t gui_askfile(const char *msg, const char *hlp, bool pth, bool dsk,
                  const char *def, bool bck, const char **ret)
{
    printf("%s\n", msg);
    printf("Enter a file name (default is '%s', H for help)\n", def);
    char response[1024];
    bool choseAnswer = false;
    do {
        printf("Enter file > ");
        fgets(response, 1024, stdin);
        if(strcmp(response, "H\n") == 0) {
            printf("%s\n", hlp);
        } else if(strcmp(response, "\n") == 0) {
            *ret = def;
            choseAnswer = true;
        } else  {
            strcpy(*ret, response);
            choseAnswer = true;
        }
    } while(choseAnswer == false);
    return G_TRUE;
}

inp_t gui_copyfiles_start(const char *msg, const char *hlp, pnode_p lst, bool cnf, bool bck)
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
    printf("Progress: %d%% complete.\n", com);
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

void gui_query_screen(int *width, int *height, int *depth, int *colors)
{

}

void gui_query_window(int *width, int *height, int *upper, int *lower,
                      int *left, int *right)
{

}