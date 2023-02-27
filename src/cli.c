//------------------------------------------------------------------------------
// cli.c:
//
// CLI Interface.
//
//------------------------------------------------------------------------------
// Copyright (C) 2018-2023, Ola Söder. All rights reserved.
// Licensed under the AROS PUBLIC LICENSE (APL) Version 1.1
//------------------------------------------------------------------------------

#include "gui.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//
// The gui_* functions are re-implementations of the gui.c functions written to use
// standard input and standard output.  Anything related to the display is ignored
// and the back option is also not implemented.
//
// Initialisation is hard coded to user level expert, no pretend.
//

inp_t gui_init(bool scr)
{
    (void)scr;

    printf("Initialising\n");

    return G_TRUE;
}

void gui_exit(void)
{
    printf("Exiting\n");
}

inp_t gui_message(const char *msg, bool bck)
{
    (void)bck;

    printf("%s\n", msg);

    return G_TRUE;
}

inp_t gui_finish(const char *msg)
{
    printf("Finish: %s\n", msg);

    return G_TRUE;
}

inp_t gui_working(const char *msg)
{
    printf("Working: %s\n", msg);

    return G_TRUE;
}

void gui_abort(const char *msg)
{
    printf("Aborting %s\n", msg);
}

int countList(const char** listOfStrings) {
    int32_t max = 0;
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
    int32_t opt = 0;
    const char **printingStrings = listOfStrings;

    if(!*printingStrings) return;

    while(*printingStrings)
    {
        printf("%d: %s\n", opt, *printingStrings);
        opt++;
        printingStrings++;
    }
}

inp_t gui_choice(const char *msg, const char *hlp, const char **nms, int32_t def, bool bck, int32_t *ret)
{
    (void)bck;

    int32_t max = countList(nms);
    printf("%s\n", msg);
    printf("Choose a number between 0 and %d (default is %d, H for help)\n", max, def);
    char response[12];
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
            int32_t res = atoi(response);
            if(res != 0) {
                if(res >= 0 && res <= max) {
                    *ret = res;
                    choseAnswer = true;
                } else {
                    printf("Number should be between 0 and %d\n", max);
                }
            }
        }
    } while(choseAnswer == false);

    return G_TRUE;
}

void printListWithSelection(const char** listOfStrings, int32_t selected) {
    int32_t opt = 0;
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

inp_t gui_options(const char *msg, const char *hlp, const char **nms, int32_t def, bool bck, int32_t *ret)
{
    (void)bck;

    int32_t max = countList(nms);
    int32_t selected = def;

    printf("%s\n", msg);
    char response[12];
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
            int32_t res = atoi(response);
            if(res == 0) {
                printf("Number should be between 0 and %d\n", max);
            } else {
                if(res >= 0 && res <= max) {
                    selected = selected ^ (1UL << res);
                } else {
                    printf("Number should be between 0 and %d\n", max);
                }
            }
        }
    } while(finished == false);
    *ret = selected;

    return G_TRUE;
}

inp_t gui_bool(const char *msg, const char *hlp, const char *yes, const char *nay, bool bck)
{
    (void)bck;

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
    (void)bck;

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
            response[strcspn((char * restrict)response, "\n")] = 0;
            *ret = strdup(response);
            choseAnswer = true;
        }
    } while(choseAnswer == false);

    return G_TRUE;
}

inp_t gui_number(const char *msg, const char *hlp, int32_t min, int32_t max, int32_t def, bool bck, int32_t *ret)
{
    (void)bck;

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
            int32_t res = atoi(response);
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

inp_t gui_welcome(const char *msg, int32_t *lvl, int32_t *lgf, int32_t *prt, int32_t min, bool npr, bool nlg)
{
    (void)lgf;
    (void)min;
    (void)npr;
    (void)nlg;

    printf("%s", msg);
    *lvl = 2;
    *prt = 0;

    return G_TRUE;
}

// The 'newpath' (pth) and 'assigns' (asn) parameters are ignored and treated as true.
inp_t gui_askdir(const char *msg, const char *hlp, bool pth, bool dsk, bool asn,
                const char *def, bool bck, const char **ret)
{
    (void)bck;
    (void)pth;
    (void)dsk;
    (void)asn;

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
            response[strcspn((char * restrict)response, "\n")] = 0;
            *ret = strdup(response);
            choseAnswer = true;
        }
    } while(choseAnswer == false);

    return G_TRUE;
}

// The 'newpath' (pth) parameter is ignored and treated as true.
inp_t gui_askfile(const char *msg, const char *hlp, bool pth, bool dsk,
                  const char *def, bool bck, const char **ret)
{
    (void)bck;
    (void)pth;
    (void)dsk;

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
            response[strcspn((char * restrict)response, "\n")] = 0;
            *ret = strdup(response);
            choseAnswer = true;
        }
    } while(choseAnswer == false);

    return G_TRUE;
}

inp_t gui_copyfiles_start(const char *msg, const char *hlp, pnode_p lst, bool cnf, bool bck)
{
    (void)hlp;
    (void)lst;
    (void)cnf;
    (void)bck;

    if(msg) {
        printf("Starting file copy %s.\n", msg);
    }

    return G_TRUE;
}

inp_t gui_copyfiles_setcur(const char *cur, bool nga, bool bck)
{
    (void)nga;
    (void)bck;

    if(cur) {
        printf("Copying files Cur:%s.\n", cur);
    }

    return G_TRUE;
}

void gui_copyfiles_end(void)
{
    printf("Finished copying files.\n");
}

void gui_complete(int com)
{
    printf("Progress: %d%% complete.\n", com);
}

inp_t gui_confirm(const char *msg, const char *hlp, bool bck)
{
    (void)bck;

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

    if(info) {
        printf("Error info: %s", info);
    }
}

void gui_effect(int eff, int32_t cl1, int32_t cl2)
{
    printf("Image effect %d with colors %d and %d", eff, cl1, cl2);
}

inp_t gui_closemedia(int mid)
{
    printf("Close media with mid %d", mid);

    return G_TRUE;
}

inp_t gui_setmedia(int mid, int32_t act, const char *par)
{
    printf("Set media with mid %d, act %d and par %s", mid, act, par ? par : "NONE");

    return G_TRUE;
}

inp_t gui_showmedia(int *mid, const char* mda, int32_t act)
{
    printf("Set media with mid %d, act %d and mda %s", *mid, act, mda);

    return G_TRUE;
}

// Defaulting to not set any values.  Not sure how this is used or what the effect will be.
void gui_query_screen(int *width, int32_t *height, int32_t *depth, int32_t *colors)
{
    (void)width;
    (void)height;
    (void)depth;
    (void)colors;
}

// Defaulting to not set any values.  Not sure how this is used or what the effect will be.
void gui_query_window(int *width, int32_t *height, int32_t *upper, int32_t *lower,
                      int32_t *left, int32_t *right)
{
    (void)width;
    (void)height;
    (void)upper;
    (void)lower;
    (void)left;
    (void)right;
}
