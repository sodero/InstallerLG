
/****************************************************************

   This file was created automatically by `FlexCat 2.18'
   from "../src/Installer.cd"

   using CatComp.sd 1.2 (24.09.1999)

   Do NOT edit by hand!

****************************************************************/

#ifndef Installer_STRINGS_H
#define Installer_STRINGS_H

#ifndef EXEC_TYPES_H
#include <exec/types.h>
#endif

#ifdef  Installer_BASIC_CODE
#undef  Installer_BASIC
#undef  Installer_CODE
#define Installer_BASIC
#define Installer_CODE
#endif

#ifdef  Installer_BASIC
#undef  Installer_ARRAY
#undef  Installer_BLOCK
#define Installer_ARRAY
#define Installer_BLOCK
#endif

#ifdef  Installer_ARRAY
#undef  Installer_NUMBERS
#undef  Installer_STRINGS
#define Installer_NUMBERS
#define Installer_STRINGS
#endif

#ifdef  Installer_BLOCK
#undef  Installer_STRINGS
#define Installer_STRINGS
#endif


#ifdef Installer_CODE
#include <proto/locale.h>
extern struct Library *LocaleBase;
#endif

#ifdef Installer_NUMBERS

#define MSG_COPYINGFILES 0
#define MSG_OVERWRITEEXISTINGDIRECTORY 1
#define MSG_ABORTCOPYTO 2
#define MSG_COULDNOTCOPYTO 3
#define MSG_DELETEWRITEPROTECTEDFILE 4
#define MSG_DELETEWRITEPROTECTEDDIRECTORY 5
#define MSG_OVERWRITEWRITEPROTECTEDFILE 6
#define MSG_DELETEFILE 7
#define MSG_DELETED 8
#define MSG_NOSUCHFILE 9
#define MSG_RENAMEDTO 10
#define MSG_COPIEDTO 11
#define MSG_DIRECTORYEXISTSALREADY 12
#define MSG_CREATED 13
#define MSG_GETMASK 14
#define MSG_PROTECT 15
#define MSG_INSTALLER 16
#define MSG_SETINSTALLATIONMODE 17
#define MSG_DESTINATIONDRAWER 18
#define MSG_COPYINGFILE 19
#define MSG_FILESTOINSTALL 20
#define MSG_INSTALLATIONMODEANDLOGGING 21
#define MSG_PROGRESS 22
#define MSG_PROCEED 23
#define MSG_RETRY 24
#define MSG_ABORT 25
#define MSG_YES 26
#define MSG_NO 27
#define MSG_OK 28
#define MSG_NEXT 29
#define MSG_SKIP 30
#define MSG_UNKNOWNERROR 31
#define MSG_SETUPFAILED 32
#define MSG_FAILEDCREATINGMUICUSTOMCLASS 33
#define MSG_FAILEDCREATINGMUIAPPLICATION 34
#define MSG_INITIALIZATIONFAILED 35
#define MSG_ERROR 36
#define MSG_SUCCESS 37
#define MSG_LINE 38
#define MSG_NOVICEUSERALLACTIONSAUTOMATIC 39
#define MSG_INTERMEDIATEUSERLIMITEDMANUALCONTROL 40
#define MSG_EXPERTUSERMUSTCONFIRMALLACTIONS 41
#define MSG_INSTALLFORREAL 42
#define MSG_DRYRUNONLY 43
#define MSG_NOLOGGING 44
#define MSG_LOGTOFILE 45
#define MSG_INSTALLERREQUIREDARGUMENTMISSING 46
#define MSG_NCANBEFOUNDIN 47
#define MSG_INSTALLATIONCOMPLETE 48
#define MSG_EXECUTED 49
#define MSG_ERRORCOULDNOTOPENFILE 50
#define MSG_LINE2 51
#define MSG_WORKINGONINSTALLATIONN 52
#define MSG_SELECTDIRECTORY 53
#define MSG_SELECTFILE 54
#define MSG_ASSIGNTO 55
#define MSG_REMOVEASSIGN 56
#define MSG_COULDNOTASSIGNTO 57
#define MSG_COULDNOTREMOVEASSIGN 58
#define MSG_APPENDTO 59
#define MSG_INCLUDEIN 60
#define MSG_VERSIONTOINSTALL 61
#define MSG_VERSIONCURRENTLYINSTALLED 62
#define MSG_UNKNOWNVERSION 63
#define MSG_DESTINATIONDRAWER2 64
#define MSG_THEREISNOCURRENTLYINSTALLEDVERSION 65

#endif /* Installer_NUMBERS */


/****************************************************************************/


#ifdef Installer_STRINGS

#define MSG_COPYINGFILES_STR "Copying file(s)"
#define MSG_OVERWRITEEXISTINGDIRECTORY_STR "Overwrite existing directory '%s'?"
#define MSG_ABORTCOPYTO_STR "Abort copy '%s' to '%s'.\n"
#define MSG_COULDNOTCOPYTO_STR "Could not copy '%s' to '%s'.\n"
#define MSG_DELETEWRITEPROTECTEDFILE_STR "Delete write protected file '%s'?"
#define MSG_DELETEWRITEPROTECTEDDIRECTORY_STR "Delete write protected directory '%s'?"
#define MSG_OVERWRITEWRITEPROTECTEDFILE_STR "Overwrite write protected file '%s'?"
#define MSG_DELETEFILE_STR "Delete file '%s'?"
#define MSG_DELETED_STR "Deleted '%s'.\n"
#define MSG_NOSUCHFILE_STR "No such file '%s'.\n"
#define MSG_RENAMEDTO_STR "Renamed '%s' to '%s'.\n"
#define MSG_COPIEDTO_STR "Copied '%s' to '%s'.\n"
#define MSG_DIRECTORYEXISTSALREADY_STR "Directory '%s' exists already.\n"
#define MSG_CREATED_STR "Created '%s'.\n"
#define MSG_GETMASK_STR "Get mask '%s' %d\n"
#define MSG_PROTECT_STR "Protect '%s' %d\n"
#define MSG_INSTALLER_STR "Installer"
#define MSG_SETINSTALLATIONMODE_STR "Set Installation Mode"
#define MSG_DESTINATIONDRAWER_STR "Destination drawer"
#define MSG_COPYINGFILE_STR "Copying file"
#define MSG_FILESTOINSTALL_STR "Files to install"
#define MSG_INSTALLATIONMODEANDLOGGING_STR "Installation mode and logging"
#define MSG_PROGRESS_STR "Progress"
#define MSG_PROCEED_STR "Proceed"
#define MSG_RETRY_STR "Retry"
#define MSG_ABORT_STR "Abort"
#define MSG_YES_STR "Yes"
#define MSG_NO_STR "No"
#define MSG_OK_STR "Ok"
#define MSG_NEXT_STR "Next"
#define MSG_SKIP_STR "Skip"
#define MSG_UNKNOWNERROR_STR "Unknown error"
#define MSG_SETUPFAILED_STR "Setup failed"
#define MSG_FAILEDCREATINGMUICUSTOMCLASS_STR "Failed creating MUI custom class"
#define MSG_FAILEDCREATINGMUIAPPLICATION_STR "Failed creating MUI application"
#define MSG_INITIALIZATIONFAILED_STR "Initialization failed"
#define MSG_ERROR_STR "Error"
#define MSG_SUCCESS_STR "Success"
#define MSG_LINE_STR "Line %d: %s '%s'"
#define MSG_NOVICEUSERALLACTIONSAUTOMATIC_STR "Novice User - All Actions Automatic"
#define MSG_INTERMEDIATEUSERLIMITEDMANUALCONTROL_STR "Intermediate User - Limited Manual Control"
#define MSG_EXPERTUSERMUSTCONFIRMALLACTIONS_STR "Expert User - Must Confirm all actions"
#define MSG_INSTALLFORREAL_STR "Install for real"
#define MSG_DRYRUNONLY_STR "Dry run only"
#define MSG_NOLOGGING_STR "No logging"
#define MSG_LOGTOFILE_STR "Log to file"
#define MSG_INSTALLERREQUIREDARGUMENTMISSING_STR "installer: required argument missing\n"
#define MSG_NCANBEFOUNDIN_STR "%s\n\n%s can be found in %s"
#define MSG_INSTALLATIONCOMPLETE_STR "Installation complete"
#define MSG_EXECUTED_STR "Executed '%s'.\n"
#define MSG_ERRORCOULDNOTOPENFILE_STR "Error: Could not open file '%s'\n"
#define MSG_LINE2_STR "Line %d: %s '%s'\n"
#define MSG_WORKINGONINSTALLATIONN_STR "Working on installation...\n\n"
#define MSG_SELECTDIRECTORY_STR "Select directory"
#define MSG_SELECTFILE_STR "Select file"
#define MSG_ASSIGNTO_STR "Assign '%s' to '%s'\n"
#define MSG_REMOVEASSIGN_STR "Remove assign '%s'\n"
#define MSG_COULDNOTASSIGNTO_STR "Could not assign '%s' to '%s'\n"
#define MSG_COULDNOTREMOVEASSIGN_STR "Could not remove assign '%s'\n"
#define MSG_APPENDTO_STR "Append '%s' to '%s'\n"
#define MSG_INCLUDEIN_STR "Include '%s' in '%s'\n"
#define MSG_VERSIONTOINSTALL_STR "Version to install"
#define MSG_VERSIONCURRENTLYINSTALLED_STR "Version currently installed"
#define MSG_UNKNOWNVERSION_STR "Unknown version"
#define MSG_DESTINATIONDRAWER2_STR "Destination drawer"
#define MSG_THEREISNOCURRENTLYINSTALLEDVERSION_STR "There is no currently installed version"

#endif /* Installer_STRINGS */


/****************************************************************************/


#ifdef Installer_ARRAY

struct Installer_ArrayType
{
    LONG   cca_ID;
    STRPTR cca_Str;
};

static const struct Installer_ArrayType Installer_Array[] =
{
    { MSG_COPYINGFILES, (STRPTR)MSG_COPYINGFILES_STR },
    { MSG_OVERWRITEEXISTINGDIRECTORY, (STRPTR)MSG_OVERWRITEEXISTINGDIRECTORY_STR },
    { MSG_ABORTCOPYTO, (STRPTR)MSG_ABORTCOPYTO_STR },
    { MSG_COULDNOTCOPYTO, (STRPTR)MSG_COULDNOTCOPYTO_STR },
    { MSG_DELETEWRITEPROTECTEDFILE, (STRPTR)MSG_DELETEWRITEPROTECTEDFILE_STR },
    { MSG_DELETEWRITEPROTECTEDDIRECTORY, (STRPTR)MSG_DELETEWRITEPROTECTEDDIRECTORY_STR },
    { MSG_OVERWRITEWRITEPROTECTEDFILE, (STRPTR)MSG_OVERWRITEWRITEPROTECTEDFILE_STR },
    { MSG_DELETEFILE, (STRPTR)MSG_DELETEFILE_STR },
    { MSG_DELETED, (STRPTR)MSG_DELETED_STR },
    { MSG_NOSUCHFILE, (STRPTR)MSG_NOSUCHFILE_STR },
    { MSG_RENAMEDTO, (STRPTR)MSG_RENAMEDTO_STR },
    { MSG_COPIEDTO, (STRPTR)MSG_COPIEDTO_STR },
    { MSG_DIRECTORYEXISTSALREADY, (STRPTR)MSG_DIRECTORYEXISTSALREADY_STR },
    { MSG_CREATED, (STRPTR)MSG_CREATED_STR },
    { MSG_GETMASK, (STRPTR)MSG_GETMASK_STR },
    { MSG_PROTECT, (STRPTR)MSG_PROTECT_STR },
    { MSG_INSTALLER, (STRPTR)MSG_INSTALLER_STR },
    { MSG_SETINSTALLATIONMODE, (STRPTR)MSG_SETINSTALLATIONMODE_STR },
    { MSG_DESTINATIONDRAWER, (STRPTR)MSG_DESTINATIONDRAWER_STR },
    { MSG_COPYINGFILE, (STRPTR)MSG_COPYINGFILE_STR },
    { MSG_FILESTOINSTALL, (STRPTR)MSG_FILESTOINSTALL_STR },
    { MSG_INSTALLATIONMODEANDLOGGING, (STRPTR)MSG_INSTALLATIONMODEANDLOGGING_STR },
    { MSG_PROGRESS, (STRPTR)MSG_PROGRESS_STR },
    { MSG_PROCEED, (STRPTR)MSG_PROCEED_STR },
    { MSG_RETRY, (STRPTR)MSG_RETRY_STR },
    { MSG_ABORT, (STRPTR)MSG_ABORT_STR },
    { MSG_YES, (STRPTR)MSG_YES_STR },
    { MSG_NO, (STRPTR)MSG_NO_STR },
    { MSG_OK, (STRPTR)MSG_OK_STR },
    { MSG_NEXT, (STRPTR)MSG_NEXT_STR },
    { MSG_SKIP, (STRPTR)MSG_SKIP_STR },
    { MSG_UNKNOWNERROR, (STRPTR)MSG_UNKNOWNERROR_STR },
    { MSG_SETUPFAILED, (STRPTR)MSG_SETUPFAILED_STR },
    { MSG_FAILEDCREATINGMUICUSTOMCLASS, (STRPTR)MSG_FAILEDCREATINGMUICUSTOMCLASS_STR },
    { MSG_FAILEDCREATINGMUIAPPLICATION, (STRPTR)MSG_FAILEDCREATINGMUIAPPLICATION_STR },
    { MSG_INITIALIZATIONFAILED, (STRPTR)MSG_INITIALIZATIONFAILED_STR },
    { MSG_ERROR, (STRPTR)MSG_ERROR_STR },
    { MSG_SUCCESS, (STRPTR)MSG_SUCCESS_STR },
    { MSG_LINE, (STRPTR)MSG_LINE_STR },
    { MSG_NOVICEUSERALLACTIONSAUTOMATIC, (STRPTR)MSG_NOVICEUSERALLACTIONSAUTOMATIC_STR },
    { MSG_INTERMEDIATEUSERLIMITEDMANUALCONTROL, (STRPTR)MSG_INTERMEDIATEUSERLIMITEDMANUALCONTROL_STR },
    { MSG_EXPERTUSERMUSTCONFIRMALLACTIONS, (STRPTR)MSG_EXPERTUSERMUSTCONFIRMALLACTIONS_STR },
    { MSG_INSTALLFORREAL, (STRPTR)MSG_INSTALLFORREAL_STR },
    { MSG_DRYRUNONLY, (STRPTR)MSG_DRYRUNONLY_STR },
    { MSG_NOLOGGING, (STRPTR)MSG_NOLOGGING_STR },
    { MSG_LOGTOFILE, (STRPTR)MSG_LOGTOFILE_STR },
    { MSG_INSTALLERREQUIREDARGUMENTMISSING, (STRPTR)MSG_INSTALLERREQUIREDARGUMENTMISSING_STR },
    { MSG_NCANBEFOUNDIN, (STRPTR)MSG_NCANBEFOUNDIN_STR },
    { MSG_INSTALLATIONCOMPLETE, (STRPTR)MSG_INSTALLATIONCOMPLETE_STR },
    { MSG_EXECUTED, (STRPTR)MSG_EXECUTED_STR },
    { MSG_ERRORCOULDNOTOPENFILE, (STRPTR)MSG_ERRORCOULDNOTOPENFILE_STR },
    { MSG_LINE2, (STRPTR)MSG_LINE2_STR },
    { MSG_WORKINGONINSTALLATIONN, (STRPTR)MSG_WORKINGONINSTALLATIONN_STR },
    { MSG_SELECTDIRECTORY, (STRPTR)MSG_SELECTDIRECTORY_STR },
    { MSG_SELECTFILE, (STRPTR)MSG_SELECTFILE_STR },
    { MSG_ASSIGNTO, (STRPTR)MSG_ASSIGNTO_STR },
    { MSG_REMOVEASSIGN, (STRPTR)MSG_REMOVEASSIGN_STR },
    { MSG_COULDNOTASSIGNTO, (STRPTR)MSG_COULDNOTASSIGNTO_STR },
    { MSG_COULDNOTREMOVEASSIGN, (STRPTR)MSG_COULDNOTREMOVEASSIGN_STR },
    { MSG_APPENDTO, (STRPTR)MSG_APPENDTO_STR },
    { MSG_INCLUDEIN, (STRPTR)MSG_INCLUDEIN_STR },
    { MSG_VERSIONTOINSTALL, (STRPTR)MSG_VERSIONTOINSTALL_STR },
    { MSG_VERSIONCURRENTLYINSTALLED, (STRPTR)MSG_VERSIONCURRENTLYINSTALLED_STR },
    { MSG_UNKNOWNVERSION, (STRPTR)MSG_UNKNOWNVERSION_STR },
    { MSG_DESTINATIONDRAWER2, (STRPTR)MSG_DESTINATIONDRAWER2_STR },
    { MSG_THEREISNOCURRENTLYINSTALLEDVERSION, (STRPTR)MSG_THEREISNOCURRENTLYINSTALLEDVERSION_STR },
};


#endif /* Installer_ARRAY */


/****************************************************************************/


#ifdef Installer_BLOCK

static const char Installer_Block[] =
{

     "\x00\x00\x00\x00" "\x00\x10"
    MSG_COPYINGFILES_STR "\x00"
     "\x00\x00\x00\x01" "\x00\x22"
    MSG_OVERWRITEEXISTINGDIRECTORY_STR ""
     "\x00\x00\x00\x02" "\x00\x1a"
    MSG_ABORTCOPYTO_STR "\x00"
     "\x00\x00\x00\x03" "\x00\x1e"
    MSG_COULDNOTCOPYTO_STR "\x00"
     "\x00\x00\x00\x04" "\x00\x22"
    MSG_DELETEWRITEPROTECTEDFILE_STR "\x00"
     "\x00\x00\x00\x05" "\x00\x26"
    MSG_DELETEWRITEPROTECTEDDIRECTORY_STR ""
     "\x00\x00\x00\x06" "\x00\x24"
    MSG_OVERWRITEWRITEPROTECTEDFILE_STR ""
     "\x00\x00\x00\x07" "\x00\x12"
    MSG_DELETEFILE_STR "\x00"
     "\x00\x00\x00\x08" "\x00\x0e"
    MSG_DELETED_STR ""
     "\x00\x00\x00\x09" "\x00\x14"
    MSG_NOSUCHFILE_STR "\x00"
     "\x00\x00\x00\x0a" "\x00\x16"
    MSG_RENAMEDTO_STR ""
     "\x00\x00\x00\x0b" "\x00\x16"
    MSG_COPIEDTO_STR "\x00"
     "\x00\x00\x00\x0c" "\x00\x20"
    MSG_DIRECTORYEXISTSALREADY_STR "\x00"
     "\x00\x00\x00\x0d" "\x00\x0e"
    MSG_CREATED_STR ""
     "\x00\x00\x00\x0e" "\x00\x12"
    MSG_GETMASK_STR "\x00"
     "\x00\x00\x00\x0f" "\x00\x10"
    MSG_PROTECT_STR ""
     "\x00\x00\x00\x10" "\x00\x0a"
    MSG_INSTALLER_STR "\x00"
     "\x00\x00\x00\x11" "\x00\x16"
    MSG_SETINSTALLATIONMODE_STR "\x00"
     "\x00\x00\x00\x12" "\x00\x12"
    MSG_DESTINATIONDRAWER_STR ""
     "\x00\x00\x00\x13" "\x00\x0c"
    MSG_COPYINGFILE_STR ""
     "\x00\x00\x00\x14" "\x00\x10"
    MSG_FILESTOINSTALL_STR ""
     "\x00\x00\x00\x15" "\x00\x1e"
    MSG_INSTALLATIONMODEANDLOGGING_STR "\x00"
     "\x00\x00\x00\x16" "\x00\x08"
    MSG_PROGRESS_STR ""
     "\x00\x00\x00\x17" "\x00\x08"
    MSG_PROCEED_STR "\x00"
     "\x00\x00\x00\x18" "\x00\x06"
    MSG_RETRY_STR "\x00"
     "\x00\x00\x00\x19" "\x00\x06"
    MSG_ABORT_STR "\x00"
     "\x00\x00\x00\x1a" "\x00\x04"
    MSG_YES_STR "\x00"
     "\x00\x00\x00\x1b" "\x00\x02"
    MSG_NO_STR ""
     "\x00\x00\x00\x1c" "\x00\x02"
    MSG_OK_STR ""
     "\x00\x00\x00\x1d" "\x00\x04"
    MSG_NEXT_STR ""
     "\x00\x00\x00\x1e" "\x00\x04"
    MSG_SKIP_STR ""
     "\x00\x00\x00\x1f" "\x00\x0e"
    MSG_UNKNOWNERROR_STR "\x00"
     "\x00\x00\x00\x20" "\x00\x0c"
    MSG_SETUPFAILED_STR ""
     "\x00\x00\x00\x21" "\x00\x20"
    MSG_FAILEDCREATINGMUICUSTOMCLASS_STR ""
     "\x00\x00\x00\x22" "\x00\x20"
    MSG_FAILEDCREATINGMUIAPPLICATION_STR "\x00"
     "\x00\x00\x00\x23" "\x00\x16"
    MSG_INITIALIZATIONFAILED_STR "\x00"
     "\x00\x00\x00\x24" "\x00\x06"
    MSG_ERROR_STR "\x00"
     "\x00\x00\x00\x25" "\x00\x08"
    MSG_SUCCESS_STR "\x00"
     "\x00\x00\x00\x26" "\x00\x10"
    MSG_LINE_STR ""
     "\x00\x00\x00\x27" "\x00\x24"
    MSG_NOVICEUSERALLACTIONSAUTOMATIC_STR "\x00"
     "\x00\x00\x00\x28" "\x00\x2a"
    MSG_INTERMEDIATEUSERLIMITEDMANUALCONTROL_STR ""
     "\x00\x00\x00\x29" "\x00\x26"
    MSG_EXPERTUSERMUSTCONFIRMALLACTIONS_STR ""
     "\x00\x00\x00\x2a" "\x00\x10"
    MSG_INSTALLFORREAL_STR ""
     "\x00\x00\x00\x2b" "\x00\x0c"
    MSG_DRYRUNONLY_STR ""
     "\x00\x00\x00\x2c" "\x00\x0a"
    MSG_NOLOGGING_STR ""
     "\x00\x00\x00\x2d" "\x00\x0c"
    MSG_LOGTOFILE_STR "\x00"
     "\x00\x00\x00\x2e" "\x00\x26"
    MSG_INSTALLERREQUIREDARGUMENTMISSING_STR "\x00"
     "\x00\x00\x00\x2f" "\x00\x1a"
    MSG_NCANBEFOUNDIN_STR "\x00"
     "\x00\x00\x00\x30" "\x00\x16"
    MSG_INSTALLATIONCOMPLETE_STR "\x00"
     "\x00\x00\x00\x31" "\x00\x10"
    MSG_EXECUTED_STR "\x00"
     "\x00\x00\x00\x32" "\x00\x20"
    MSG_ERRORCOULDNOTOPENFILE_STR ""
     "\x00\x00\x00\x33" "\x00\x12"
    MSG_LINE2_STR "\x00"
     "\x00\x00\x00\x34" "\x00\x1c"
    MSG_WORKINGONINSTALLATIONN_STR ""
     "\x00\x00\x00\x35" "\x00\x10"
    MSG_SELECTDIRECTORY_STR ""
     "\x00\x00\x00\x36" "\x00\x0c"
    MSG_SELECTFILE_STR "\x00"
     "\x00\x00\x00\x37" "\x00\x14"
    MSG_ASSIGNTO_STR ""
     "\x00\x00\x00\x38" "\x00\x14"
    MSG_REMOVEASSIGN_STR "\x00"
     "\x00\x00\x00\x39" "\x00\x1e"
    MSG_COULDNOTASSIGNTO_STR ""
     "\x00\x00\x00\x3a" "\x00\x1e"
    MSG_COULDNOTREMOVEASSIGN_STR "\x00"
     "\x00\x00\x00\x3b" "\x00\x14"
    MSG_APPENDTO_STR ""
     "\x00\x00\x00\x3c" "\x00\x16"
    MSG_INCLUDEIN_STR "\x00"
     "\x00\x00\x00\x3d" "\x00\x12"
    MSG_VERSIONTOINSTALL_STR ""
     "\x00\x00\x00\x3e" "\x00\x1c"
    MSG_VERSIONCURRENTLYINSTALLED_STR "\x00"
     "\x00\x00\x00\x3f" "\x00\x10"
    MSG_UNKNOWNVERSION_STR "\x00"
     "\x00\x00\x00\x40" "\x00\x12"
    MSG_DESTINATIONDRAWER2_STR ""
     "\x00\x00\x00\x41" "\x00\x28"
    MSG_THEREISNOCURRENTLYINSTALLEDVERSION_STR "\x00"

};

#endif /* Installer_BLOCK */


/****************************************************************************/


#ifdef Installer_CODE

#ifndef Installer_CODE_EXISTS
 #define Installer_CODE_EXISTS

 STRPTR GetInstallerString(struct Installer_LocaleInfo *li, LONG stringNum)
 {
 LONG   *l;
 UWORD  *w;
 STRPTR  builtIn;

     l = (LONG *)Installer_Block;

     while (*l != stringNum)
       {
       w = (UWORD *)((ULONG)l + 4);
       l = (LONG *)((ULONG)l + (ULONG)*w + 6);
       }
     builtIn = (STRPTR)((ULONG)l + 6);

// #define Installer_XLocaleBase LocaleBase
// #define LocaleBase li->li_LocaleBase
    
     if(LocaleBase && li)
        return(GetCatalogStr(li->li_Catalog, stringNum, builtIn));

// #undef  LocaleBase
// #define LocaleBase XLocaleBase
// #undef  Installer_XLocaleBase

     return(builtIn);
 }

#else

 STRPTR GetInstallerString(struct Installer_LocaleInfo *li, LONG stringNum);

#endif /* Installer_CODE_EXISTS */

#endif /* Installer_CODE */


/****************************************************************************/


#endif /* Installer_STRINGS_H */
