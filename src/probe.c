//------------------------------------------------------------------------------
// probe.c:
//
// Host system information retrieval
//------------------------------------------------------------------------------
// Copyright (C) 2018-2020, Ola Söder. All rights reserved.
// Licensed under the AROS PUBLIC LICENSE (APL) Version 1.1
//------------------------------------------------------------------------------

#include "alloc.h"
#include "error.h"
#include "eval.h"
#include "file.h"
#include "gui.h"
#include "probe.h"
#include "util.h"
#include <limits.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>

#ifdef AMIGA
#include <dos/dos.h>
#include <dos/dosextens.h>
#include <exec/execbase.h>
#include <exec/memory.h>
#include <exec/resident.h>
# ifdef __MORPHOS__
#  include <exec/system.h>
# endif
# ifdef __AROS__
#  include <proto/processor.h>
#  include <resources/processor.h>
# endif
#include <proto/dos.h>
#include <proto/exec.h>
#include <proto/icon.h>
#include <workbench/workbench.h>
#endif

//------------------------------------------------------------------------------
// CPU ID:s
//------------------------------------------------------------------------------
typedef enum {NONE, PPC, ARM, M68000, M68010, M68020, M68030, M68040, M68060,
              X86, X86_64} cpu_t;

#if defined(__MORPHOS__) && !defined(LG_TEST)
//------------------------------------------------------------------------------
// Name:        h_cpu_id
// Description: Get host CPU ID. MorphOS implementation.
// Input:       ---
// Return:      cpu_t: Host CPU architecture ID.
//------------------------------------------------------------------------------
static cpu_t h_cpu_id(void)
{
    uint32_t arc = NONE;

    NewGetSystemAttrs(&arc, sizeof(arc), SYSTEMINFOTYPE_MACHINE);

    // On MorphOS, there is only PPC (and no define).
    return arc == 1 ? PPC : NONE;
}

#elif defined(__AROS__) && !defined(LG_TEST)
//------------------------------------------------------------------------------
// Name:        h_cpu_id
// Description: Get host CPU ID. AROS implementation.
// Input:       ---
// Return:      cpu_t: Host CPU architecture ID.
//------------------------------------------------------------------------------
static cpu_t h_cpu_id(void)
{
    APTR ProcessorBase = OpenResource("processor.resource");

    if(!ProcessorBase)
    {
        // Unknown error.
        return NONE;
    }

    ULONG fam;
    struct TagItem tags[] = {{GCIT_Family, (IPTR) &fam}, {TAG_DONE, TAG_DONE}};
    GetCPUInfo(tags);

    switch(fam)
    {
        case CPUFAMILY_60X:
        case CPUFAMILY_7X0:
        case CPUFAMILY_74XX:
        case CPUFAMILY_4XX:
           return PPC;

        case CPUFAMILY_ARM_3:
        case CPUFAMILY_ARM_4:
        case CPUFAMILY_ARM_4T:
        case CPUFAMILY_ARM_5:
        case CPUFAMILY_ARM_5T:
        case CPUFAMILY_ARM_5TE:
        case CPUFAMILY_ARM_5TEJ:
        case CPUFAMILY_ARM_6:
        case CPUFAMILY_ARM_7:
           return ARM;

        case CPUFAMILY_MOTOROLA_68000:
           return M68000;

        case CPUFAMILY_AMD_K5:
        case CPUFAMILY_AMD_K6:
        case CPUFAMILY_AMD_K7:
        case CPUFAMILY_INTEL_486:
        case CPUFAMILY_INTEL_PENTIUM:
        case CPUFAMILY_INTEL_PENTIUM_PRO:
        case CPUFAMILY_INTEL_PENTIUM4:
           return X86;

        case CPUFAMILY_AMD_K8:
        case CPUFAMILY_AMD_K9:
        case CPUFAMILY_AMD_K10:
           return X86_64;

        default:
           return NONE;
    }
}

#elif defined(AMIGA) && !defined(LG_TEST)
//------------------------------------------------------------------------------
// Name:        h_cpu_id
// Description: Get host CPU ID. AmigaOS implementation.
//
//              Beware: ### NOT TESTED ###
//
// Input:       ---
// Return:      cpu_t: Host CPU architecture ID.
//------------------------------------------------------------------------------
static cpu_t h_cpu_id(void)
{
    // This might work on OS3. OS4 probably needs some sugar on top.
    struct ExecBase *AbsSysBase = *((struct ExecBase **) 4);
    UWORD flags = AbsSysBase->AttnFlags;

    if(flags & AFF_68010)
    {
        return M68010;
    }
    else if(flags & AFF_68020)
    {
        return M68020;
    }
    else if(flags & AFF_68030)
    {
        return M68030;
    }
    else if(flags & AFF_68040)
    {
        return M68040;
    }
    else if(flags & AFF_68060)
    {
        return M68060;
    }
    else
    {
        return M68000;
    }
}

#else
//------------------------------------------------------------------------------
// Name:        h_cpu_id
// Description: Get host CPU ID. Dummy / test implementation.
// Input:       ---
// Return:      cpu_t: Host CPU architecture ID.
//------------------------------------------------------------------------------
static cpu_t h_cpu_id(void)
{
    // In test mode / on non Amigas we shouldn't report anything but 'Unknown'.
    // Doing so would create dependencies between test results and host system.
    return NONE;
}
#endif

//------------------------------------------------------------------------------
// Name:        h_cpu_name
// Description: Helper for n_database. Get host CPU architecture.
// Input:       ---
// Return:      char *: Host CPU architecture.
//------------------------------------------------------------------------------
static char *h_cpu_name(void)
{
    char *cpu[] = { "Unknown CPU", "PowerPC", "ARM", "M68000", "M68010", "M68020",
                    "M68030", "M68040", "M68060", "X86", "X86_64"};

    // Trans ID to string.
    cpu_t cid  = h_cpu_id();
    return cpu[(cid < (sizeof(cpu) / sizeof(cpu[NONE]))) ? cid : NONE];
}

//------------------------------------------------------------------------------
// Name:        h_os_name
// Description: Helper for n_database. Get name of host OS.
// Input:       ---
// Return:      char *: Name of host OS.
//------------------------------------------------------------------------------
static char *h_os_name(void)
{
    // Host OS or 'Unknown'.
    #if defined(AMIGA) && !defined(LG_TEST)
    if(FindResident("MorphOS"))
    {
        return "MorphOS";
    }

    // TODO - Try to open aros.library instead?
    if(FindResident("processor.resource"))
    {
        return "AROS";
    }

    // Use AmigaOS as fallback.
    return "AmigaOS";
    #else
    // In test mode / on non Amigas we shouldn't report anything but 'Unknown'.
    // Doing so would create dependencies between test results and host system.
    return "Unknown OS";
    #endif
}

//------------------------------------------------------------------------------
// Name:        h_chipmem.
// Description: Helper for n_database. Get free chipmem in bytes.
// Input:       ---
// Return:      int32_t:    Free chipmem.
//------------------------------------------------------------------------------
static int32_t h_chipmem(void)
{
    return
    #if defined(AMIGA) && !defined(LG_TEST)
    AvailMem(MEMF_CHIP);
    #else
    // In test mode / on non Amigas we shouldn't report anything but a dummy
    // value. Doing so would create dependencies between test results and host
    // system. Pretend that we have 512 KiB free chipmem.
    (int32_t) 1 << 19;
    #endif
}

//------------------------------------------------------------------------------
// Name:        h_totalmem.
// Description: Helper for n_database. Get free chipmem + fastmem in bytes.
// Input:       ---
// Return:      int32_t:    Free chipmem + fastmem.
//------------------------------------------------------------------------------
static int32_t h_totalmem(void)
{
    return
    #if defined(AMIGA) && !defined(LG_TEST)
    AvailMem(MEMF_ANY);
    #else
    // In test mode / on non Amigas we shouldn't report anything but a dummy
    // value. Doing so would create dependencies between test results and host
    // system. Pretend that we have 1 MiB free chipmem + fastmem.
    (int32_t) 1 << 20;
    #endif
}

//------------------------------------------------------------------------------
// (database <feature> [<checkvalue>])
//    return information about the Amiga that the Installer
//    is running on.
//
// Refer to Installer.guide 1.19 (29.4.96) 1995-96 by ESCOM AG
//------------------------------------------------------------------------------
entry_p n_database(entry_p contxt)
{
    // We need atleast one argument
    C_SANE(1, NULL);

    char *feat = str(C_ARG(1));

    if(strcasecmp(feat, "cpu") == 0)
    {
        // Get host CPU name.
        snprintf(buf_get(B_KEY), buf_len(), "%s", h_cpu_name());
    }
    else if(strcasecmp(feat, "os") == 0)
    {
        // Get host OS name.
        snprintf(buf_get(B_KEY), buf_len(), "%s", h_os_name());
    }
    else if(strcasecmp(feat, "graphics-mem") == 0)
    {
        // Get free chipmem.
        snprintf(buf_get(B_KEY), buf_len(), "%d", h_chipmem());
    }
    else if(strcasecmp(feat, "total-mem") == 0)
    {
        // Get free fast + chipmem.
        snprintf(buf_get(B_KEY), buf_len(), "%d", h_totalmem());
    }
    else
    {
        // Missing: 'vblank', 'fpu' and 'chiprev'.
        snprintf(buf_get(B_KEY), buf_len(), "%s", "Unknown");
    }

    // Are we testing for a specific value?
    if(exists(C_ARG(2)))
    {
        if(strcasecmp(buf_put(B_KEY), str(C_ARG(2))) == 0)
        {
            // Value <-> result match.
            R_STR(DBG_ALLOC(strdup("1")));
        }

        // Value <-> result mismatch.
        R_STR(DBG_ALLOC(strdup("0")));
    }

    // Return result as string.
    R_STR(DBG_ALLOC(strdup(buf_put(B_KEY))));
}

//------------------------------------------------------------------------------
// (earlier <file1> <file2>)
//     true if file1 earlier than file2
//
// Refer to Installer.guide 1.19 (29.4.96) 1995-96 by ESCOM AG
//------------------------------------------------------------------------------
entry_p n_earlier(entry_p contxt)
{
    // We need two filenames.
    C_SANE(2, NULL);

    // One struct per file.
    struct stat old, new;

    // Get information about the first file.
    if(stat(str(C_ARG(1)), &old))
    {
        // Could not read from file / dir.
        ERR(ERR_READ, str(C_ARG(1)));
        R_NUM(LG_FALSE);
    }

    // Get information about the second file.
    if(stat(str(C_ARG(2)), &new))
    {
        // Could not read from file / dir.
        ERR(ERR_READ, str(C_ARG(2)));
        R_NUM(LG_FALSE);
    }

    // Is the first older than the second one?
    R_NUM(old.st_mtime < new.st_mtime ? 1 : 0);
}

//------------------------------------------------------------------------------
// (getassign <name> <opts>)
//     return value of logical name (no `:') `<opts>': 'v'-volumes,
//     'a'-assigns, 'd'-devices
//
// Refer to Installer.guide 1.19 (29.4.96) 1995-96 by ESCOM AG
//------------------------------------------------------------------------------
entry_p n_getassign(entry_p contxt)
{
    // We need one or more arguments.
    C_SANE(1, NULL);

    // On non Amiga systems, or in test mode, this is a stub.
    #if defined(AMIGA) && !defined(LG_TEST)
    struct DosList *dl;
    const char *asn = str(C_ARG(1));
    size_t asnl = strlen(asn);

    if(!asnl)
    {
        // Invalid assign; an empty string is how the CBM installer fails.
        return end();
    }

    // The second argument is optional.
    entry_p option = C_ARG(2);

    // The bitmask must contain atleast this LDF_READ.
    ULONG msk = LDF_READ;

    // Parse the option string if it exists.
    if(exists(option))
    {
        const char *o = str(option);

        if(*o)
        {
            // Translate from Installer speak to DOS speak.
            while(*o)
            {
                msk |= (*o == 'v') ? LDF_VOLUMES : 0;
                msk |= (*o == 'd') ? LDF_DEVICES : 0;
                msk |= (*o == 'a') ? LDF_ASSIGNS : 0;
                o++;
            }
        }
        else
        {
            // The CBM installer returns an empty string if option is empty.
            return end();
        }
    }
    else
    // The default behaviour, when no option string is present, is to look for
    // logical assignments.
    {
        msk |= LDF_ASSIGNS;
    }

    // Prepare to walk the device list.
    dl = (struct DosList *) LockDosList(msk);

    if(dl)
    {
        ULONG bits[] = { LDF_ASSIGNS, LDF_VOLUMES, LDF_DEVICES, 0 };

        // Iterate over all flags.
        for(size_t i = 0; bits[i]; i++)
        {
            // For all flags matching the option string (or its absence),
            // traverse the doslist.
            if(msk & bits[i])
            {
                struct DosList *dc = (struct DosList *)
                                      NextDosEntry(dl, bits[i]);
                while(dc)
                {
                    const char *n = B2CSTR(dc->dol_Name);

                    // Ignore case when looking for match.
                    if(!strcasecmp(asn, n))
                    {
                        // Unlock doslist and allocate enough memory to hold any
                        // path.
                        char *r = DBG_ALLOC(calloc(PATH_MAX, 1));
                        UnLockDosList(msk);

                        if(r)
                        {
                            // The form common to all types. Do we need to do
                            // anything with LDF_VOLUMES?
                            snprintf(r, PATH_MAX, "%s:", n);

                            // Logical assignments. Get the full path from the
                            // lock.
                            if(bits[i] == LDF_ASSIGNS)
                            {
                                BPTR l = (BPTR) Lock(r, ACCESS_READ);

                                if(l)
                                {
                                    NameFromLock(l, r, PATH_MAX);
                                    UnLock(l);
                                }
                            }
                            // Devices. No other options than 'd' are allowed
                            // in the options string for some reason (in the
                            // CBM installer).
                            else if(bits[i] == LDF_DEVICES)
                            {
                                if((bits[i] | LDF_READ) == msk)
                                {
                                    // Cut ':'.
                                    r[asnl] = '\0';
                                }
                                else
                                {
                                    // Clear.
                                    r[0] = '\0';
                                }
                            }

                            // Success.
                            R_STR(r);
                        }
                        else
                        {
                            PANIC(contxt);
                            return end();
                        }
                    }
                    else
                    {
                        // No match. Next list item.
                        dc = (struct DosList *) NextDosEntry(dc, bits[i]);
                    }
                }
            }
        }

        // Not found.
        UnLockDosList(msk);
    }
    else
    {
        // Could not lock doslist. I'm not sure this can happen. I believe
        // LockDosList will block until the end of time if a problem occurs.
        ERR(ERR_READ, asn);
    }
    #endif

    // Return empty string on failure.
    return end();
}

//------------------------------------------------------------------------------
// (getdevice <path>)
//     returns name of device upon which <path> resides
//
// Refer to Installer.guide 1.19 (29.4.96) 1995-96 by ESCOM AG
//------------------------------------------------------------------------------
entry_p n_getdevice(entry_p contxt)
{
    // We need a path.
    C_SANE(1, NULL);

    #if defined(AMIGA) && !defined(LG_TEST)
    BPTR lock = (BPTR) Lock(str(C_ARG(1)), ACCESS_READ);
    struct InfoData id;

    if(!lock)
    {
        // Use current directory as fallback.
        lock = (BPTR) Lock("", ACCESS_READ);
    }

    if(lock && Info(lock, &id))
    {
        UnLock(lock);
        struct DosList *dl = (struct DosList *) BADDR(id.id_VolumeNode);

        if(dl && dl->dol_Task)
        {
            struct MsgPort *mp = dl->dol_Task;
            ULONG msk = LDF_READ | LDF_DEVICES;
            dl = (struct DosList *) LockDosList(msk);

            while(dl && mp != dl->dol_Task)
            {
                // Search for <path> handler in the list of devices.
                dl = (struct DosList *) NextDosEntry(dl, LDF_DEVICES);
            }

            // Did we find the device?
            if(dl && B2CSTR(dl->dol_Name))
            {
                // Copy device name before unlocking just in case.
                char *dev = DBG_ALLOC(strdup(B2CSTR(dl->dol_Name)));
                UnLockDosList(msk);
                R_STR(dev);
            }

            UnLockDosList(msk);
        }
    }

    // Could not get <path> info.
    ERR(ERR_READ, str(C_ARG(1)));
    #endif
    // Return empty string on failure.
    return end();
}

//------------------------------------------------------------------------------
// (getdiskspace <pathname> [<unit>])                                    (V44)
//     return available space
//
// Refer to Installer.guide 1.20 (25.10.1999) 1995-99 by Amiga Inc.
//------------------------------------------------------------------------------
entry_p n_getdiskspace(entry_p contxt)
{
    // We need a path.
    C_SANE(1, NULL);

    #if defined(AMIGA) && !defined(LG_TEST)
    // Attempt to lock path.
    const char *n = str(C_ARG(1));
    BPTR lock = (BPTR) Lock(n, ACCESS_READ);

    // Do we have a lock?
    if(lock)
    {
        struct InfoData id;

        // Retrieve information from lock.
        if(Info(lock, &id))
        {
            long long free = (long long) (id.id_NumBlocks - id.id_NumBlocksUsed)
                                          * id.id_BytesPerBlock;
            // Release lock ASAP.
            UnLock(lock);

            // From the Installer.guide 1.20:
            //
            // The parameter <unit> is optional and defines the unit for the
            // returned disk space: "B" (or omitted) is "Bytes", "K" is
            // "Kilobytes", "M" is "Megabytes" and "G" is "Gigabytes".
            if(exists(C_ARG(2)))
            {
                switch(*str(C_ARG(2)))
                {
                    case 'K':
                    case 'k':
                        free >>= 10;
                        break;

                    case 'M':
                    case 'm':
                        free >>= 20;
                        break;

                    case 'G':
                    case 'g':
                        free >>= 30;
                        break;
                }
            }

            // Cap the return value.
            R_NUM(free > INT_MAX ? INT_MAX : (int32_t) free);
        }

        // Info() failed. Release lock.
        UnLock(lock);
    }

    // For some reason, we could not acquire a lock on <path>, or, we could get
    // a lock, but failed when trying to retrieve info from the lock.
    ERR(ERR_READ, n);
    #endif

    // Failure.
    R_NUM(-1);
}

//------------------------------------------------------------------------------
// (getenv <name>)
//     return value of environment variable
//
// Refer to Installer.guide 1.19 (29.4.96) 1995-96 by ESCOM AG
//------------------------------------------------------------------------------
entry_p n_getenv(entry_p contxt)
{
    // We need a variable name.
    C_SANE(1, NULL);

    // Is there such an environment variable?
    char *env = getenv(str(C_ARG(1)));

    if(env)
    {
        // Return what we found.
        R_STR(DBG_ALLOC(strdup(env)));
    }

    // Nothing found, return empty string.
    return end();
}

//------------------------------------------------------------------------------
// (getsize <file>)
//     return size
//
// Refer to Installer.guide 1.19 (29.4.96) 1995-96 by ESCOM AG
//------------------------------------------------------------------------------
entry_p n_getsize(entry_p contxt)
{
    // We need a file name.
    C_SANE(1, NULL);

    // Open the file in read only mode.
    FILE *file = h_fopen(contxt, str(C_ARG(1)), "r", false);

    if(file)
    {
        // Seek to the end of the file.
        fseek(file, 0L, SEEK_END);

        // Let the result be the position.
        int32_t res = (int32_t) ftell(file);

        // We're done.
        h_fclose(&file);

        // Return position.
        R_NUM(res);
    }

    // Could not read from file.
    ERR(ERR_READ_FILE, str(C_ARG(1)));
    R_NUM(LG_FALSE);
}

//------------------------------------------------------------------------------
// (getsum <file>)
//     return checksum of file for comparison purposes
//
// Refer to Installer.guide 1.19 (29.4.96) 1995-96 by ESCOM AG
//------------------------------------------------------------------------------
entry_p n_getsum(entry_p contxt)
{
    // We need a filename.
    C_SANE(1, NULL);

    const char *name = str(C_ARG(1));
    FILE *file = h_fopen(contxt, name, "r", false);

    if(file)
    {
        int chr = getc(file), alfa = 1, beta = 0;

        // Adler-32 checksum.
        while(chr != EOF)
        {
            alfa = (alfa + chr) % 65521;
            beta = (alfa + beta) % 65521;
            chr = getc(file);
        }

        if(feof(file))
        {
            // File completed.
            h_fclose(&file);

            // Return checksum.
            R_NUM((beta << 16) | alfa);
        }

        // I/O error. Close and bail.
        h_fclose(&file);
    }

    // Could not read from file.
    ERR(ERR_READ_FILE, name);
    R_NUM(LG_FALSE);
}

//------------------------------------------------------------------------------
// Name:        h_getversion_rsp
// Description: Helper for h_getversion_rsp and h_getversion_dev. Get resident
//              version from Resident struct.
// Input:       struct Resident *rsp:   Resident struct from FindResident.
// Return:      int32_t:                Resident version.
//------------------------------------------------------------------------------
#if defined(AMIGA) && !defined(LG_TEST)
static int32_t h_getversion_rsp(struct Resident *rsp)
{
    if(!rsp)
    {
        // Invalid.
        return LG_NOVER;
    }

    // Major and revision.
    int32_t maj, rev;

    // Version string pattern.
    const char *ids = rsp->rt_IdString;
    const char *pat = "%*[^0123456789]%d.%d%*[^\0]";

    // Find the revision in the id string. The major part of our parsed result
    // should match rt_Version.
    if(sscanf(ids, pat, &maj, &rev) == 2 && maj == rsp->rt_Version)
    {
        // We found both major and revision.
        return (maj << 16) | rev;
    }

    // Don't trust the parsed result. Revision unknown.
    return rsp->rt_Version << 16;
}
#endif

//------------------------------------------------------------------------------
// Name:        h_getversion_res
// Description: Helper for n_getversion. Get resident version.
// Input:       char *name: Resident name.
// Return:      int32_t:    Resident version.
//------------------------------------------------------------------------------
static int32_t h_getversion_res(const char *name)
{
    #if defined(AMIGA) && !defined(LG_TEST)
    return h_getversion_rsp(FindResident(name));
    #else
    (void) name;
    return LG_NOVER;
    #endif
}

//------------------------------------------------------------------------------
// Name:        h_getversion_dev
// Description: Helper for n_getversion. Get device version.
// Input:       char *name: Filename.
// Return:      int32_t:    File version.
//------------------------------------------------------------------------------
static int32_t h_getversion_dev(const char *name)
{
    // Failure.
    int32_t ver = LG_NOVER;

    #if defined(AMIGA) && !defined(LG_TEST)
    struct MsgPort *port = CreateMsgPort();

    if(!port)
    {
        // No port.
        return ver;
    }

    // Big enough for all devices (magic number from Scout).
    size_t size = sizeof(struct IOStdReq) + 128;

    // Allocate and initialize standard request.
    struct IOStdReq *req = CreateIORequest(port, size);

    if(req)
    {
        // We don't know what unit to use. Try something.
        for(int unit = -1; unit < 16; unit++)
        {
            if(OpenDevice(name, unit, (struct IORequest *) req, 0) == 0)
            {
                // Translate version and revision to Installer format.
                if(req->io_Device)
                {
                    ver = req->io_Device->dd_Library.lib_Version << 16 |
                          req->io_Device->dd_Library.lib_Revision;
                }

                CloseDevice((struct IORequest *) req);
                break;
            }
        }

        DeleteIORequest(req);
    }

    DeleteMsgPort(port);
    #else
    (void) name;
    #endif

    // Success or failure.
    return ver;
}

//------------------------------------------------------------------------------
// Name:        h_getversion_lib
// Description: Helper for n_getversion. Get library version.
// Input:       char *name: Library name.
// Return:      int32_t:    Library version.
//------------------------------------------------------------------------------
static int32_t h_getversion_lib(const char *name)
{
    // Assume failure.
    int32_t ver = LG_NOVER;

    #if defined(AMIGA) && !defined(LG_TEST)
    struct Library *lib = OpenLibrary(name, 0);
    // Assume that 'name' is a library that can be opened.
    if(lib)
    {
        // Get version and revision.
        ver = (lib->lib_Version << 16) | lib->lib_Revision;

        // Library is no longer needed.
        CloseLibrary(lib);
    }
    #else
    (void) name;
    #endif

    // Success or failure.
    return ver;
}

//------------------------------------------------------------------------------
// Name:        h_getversion_file
// Description: Helper for n_getversion. Get file version.
// Input:       char *name: Filename.
// Return:      int32_t:    File version.
//------------------------------------------------------------------------------
int32_t h_getversion_file(const char *name)
{
    FILE *file = NULL;

    #if defined(AMIGA) && !defined(LG_TEST)
    struct Process *pro = (struct Process *) FindTask(NULL);
    // Save the current window ptr.
    APTR win = pro->pr_WindowPtr;

    // Disable auto request.
    pro->pr_WindowPtr = (APTR) -1L;
    #endif

    // Attempt to open file.
    file = h_fopen(end(), name, "r", false);

    #if defined(AMIGA) && !defined(LG_TEST)
    // Restore auto request.
    pro->pr_WindowPtr = win;
    #endif

    // Invalid version.
    int32_t ver = LG_NOVER;

    if(!file)
    {
        // Failure.
        return ver;
    }

    // Version key string.
    int key[] = {'$','V','E','R',':',' ', 0};
    size_t ndx = 0;

    // Find position of the version key.
    for(int chr = 0; chr != EOF && key[ndx];
        ndx = chr == key[ndx] ? ndx + 1 : 0)
    {
        chr = fgetc(file);
    }

    // Did we find the key?
    if(!key[ndx])
    {
        // Fill up buffer with enough data to hold any realistic version string.
        fread(buf_get(B_KEY), 1, buf_len(), file);

        // Begin after whitespace.
        char *data = strchr(buf_put(B_KEY), ' ');

        if(data)
        {
            // Major and revision.
            int32_t maj = 0, rev = 0;

            // Version string pattern.
            const char *pat = "%*[^0123456789]%d.%d%*[^\0]";

            // Try to find version string.
            if(sscanf(data, pat, &maj, &rev) == 2)
            {
                // We found something.
                ver = (maj << 16) | rev;
            }
        }
    }

    // We're done.
    h_fclose(&file);

    // If we have a valid version return that. Otherwise the file might be a
    // library, try to get the library version and return that instead.
    return ver == LG_NOVER ? h_getversion_lib(name) : ver;
}

//------------------------------------------------------------------------------
// (getversion <file> (resident))
//     return version/revision of file, library, etc. as 32 bit num
//
// Refer to Installer.guide 1.19 (29.4.96) 1995-96 by ESCOM AG
//------------------------------------------------------------------------------
entry_p n_getversion(entry_p contxt)
{
    // Arguments are optional.
    C_SANE(0, NULL);

    // Any arguments / options given?
    if(contxt->children)
    {
        // If so, they must be valid and >= 1.
        C_SANE(1, contxt);

        // Name of file / lib / etc.
        const char *name = str(C_ARG(1)),
        #if defined(AMIGA) && !defined(LG_TEST)
        *file = FilePart(name);
        #else
        *file = name;
        #endif

        // Invalid version.
        int32_t ver = LG_NOVER;

        // Get resident module version.
        if(opt(contxt, OPT_RESIDENT))
        {
            ver = h_getversion_res(file);
        }

        if(ver == LG_NOVER)
        {
            // Get file version.
            ver = h_getversion_file(name);
        }

        // Only attempt to open library / device if file doesn't exist.
        if(h_exists(file) == LG_NONE)
        {
            if(ver == LG_NOVER)
            {
                // Get library version.
                ver = h_getversion_lib(file);
            }

            if(ver == LG_NOVER)
            {
                // Get device version.
                ver = h_getversion_dev(file);
            }
        }

        // Failure (0) or version / revision.
        R_NUM((ver == LG_NOVER) ? 0 : ver);
    }

    #if defined(AMIGA) && !defined(LG_TEST)
    // No arguments, return version of Exec.
    extern struct ExecBase *SysBase;
    R_NUM((SysBase->LibNode.lib_Version << 16) | SysBase->SoftVer);
    #else
    R_NUM(LG_FALSE);
    #endif
}

//------------------------------------------------------------------------------
// (iconinfo <parameters>)
//     return information about an icon (V42.12)
//
// Refer to Installer.guide 1.19 (29.4.96) 1995-96 by ESCOM AG
//
// Despite what the Installer.guide says, 'help', 'prompt', 'confirm' and 'safe'
// are dead options in OS 3.9. We choose to ignore the guide and mimic the
// behaviour of the implementation in 3.9. Also, the 3.9 implementation deletes
// tooltypes when (gettooltype) is used. This is assumed to be a bug and
// therefore not mimiced.
//------------------------------------------------------------------------------
entry_p n_iconinfo(entry_p contxt)
{
    // One or more arguments.
    C_SANE(1, contxt);

    entry_p dst     =   opt(contxt, OPT_DEST);
    entry_p types[] = { opt(contxt, OPT_GETTOOLTYPE),
                        opt(contxt, OPT_GETDEFAULTTOOL),
                        opt(contxt, OPT_GETSTACK),
                        opt(contxt, OPT_GETPOSITION), end() };

    // We need an icon.
    if(!dst)
    {
        ERR(ERR_MISSING_OPTION, "dest");
        R_NUM(LG_FALSE);
    }

    // Suffix isn't needed.
    char *file = str(dst);

    #if defined(AMIGA) && !defined(LG_TEST)
    // Get icon information.
    struct DiskObject *obj = (struct DiskObject *) GetDiskObject(file);
    #else
    char *obj = file;
    #endif

    // Exit if we can't read from icon.
    if(!obj)
    {
        ERR(ERR_READ_FILE, file);
        R_NUM(LG_FALSE);
    }

    // Iterate over all options.
    for(size_t i = 0; types[i] != end() && !DID_ERR; i++)
    {
        // Is the current option not set?
        if(!types[i])
        {
            // Next option.
            continue;
        }

        // Iterate over all its children.
        for(size_t j = 0; exists(types[i]->children[j]); j++)
        {
            // Get variable name.
            char *name = str(types[i]->children[j]);

            // Skip empty variable names.
            if(!(*name))
            {
                continue;
            }

            // Get option type.
            int32_t type = types[i]->id;
            char *svl = NULL;

            #if defined(AMIGA) && !defined(LG_TEST)
            // Is this a numerical value?
            if(type == OPT_GETSTACK || type == OPT_GETPOSITION)
            {
                int v = (type == OPT_GETSTACK ? obj->do_StackSize : j == 0 ?
                         obj->do_CurrentX : obj->do_CurrentY);

                snprintf(buf_get(B_KEY), buf_len(), "%d", v);
                svl = buf_put(B_KEY);
            }
            else if(type == OPT_GETDEFAULTTOOL && obj->do_DefaultTool)
            {
                svl = obj->do_DefaultTool;
            }
            else if(type == OPT_GETTOOLTYPE && obj->do_ToolTypes)
            {
                svl = (char *) FindToolType(obj->do_ToolTypes, name);
                name = str(types[i]->children[++j]);
            }

            // Always a valid value.
            svl = svl ? svl : "";
            #else
            // Testing purposes only.
            snprintf(buf_get(B_KEY), buf_len(), "%d:%zu", type, j);
            svl = buf_put(B_KEY);
            #endif

            // Always a valid (string).
            entry_p val = new_string(DBG_ALLOC(strdup(svl)));

            // Unless we're out of memory.
            if(!val)
            {
                PANIC(contxt);
                break;
            }

            // If a symbol with the same name as that of the option, replace
            // the value of the old one with the new value.
            if(contxt->symbols)
            {
                for(size_t k = 1; exists(C_SYM(k)); k++)
                {
                    if(!strcasecmp(C_SYM(k)->name, name))
                    {
                        kill(C_SYM(k)->resolved);
                        C_SYM(k)->resolved = val;
                        push(global(contxt), C_SYM(k));
                        val->parent = C_SYM(k);

                        // We no longer own 'val'.
                        val = NULL;
                        break;
                    }
                }
            }

            // Continue with the next symbol if this one exists.
            if(!val)
            {
                continue;
            }

            // This is a new symbol. Create, append to this function and push to
            // the global context.
            entry_p sym = new_symbol(DBG_ALLOC(strdup(name)));

            if(!sym)
            {
                // Do not leak 'val'.
                kill(val);
                continue;
            }

            // Adopt the value found above.
            val->parent = sym;
            sym->resolved = val;

            // PANIC set by append on out of memory.
            if(append(&contxt->symbols, sym))
            {
                push(global(contxt), sym);
                sym->parent = contxt;
            }
        }
    }

    #if defined(AMIGA) && !defined(LG_TEST)
    FreeDiskObject(obj);
    #endif

    // Success.
    R_NUM(LG_TRUE);
}

//------------------------------------------------------------------------------
// (querydisplay <object> <option>)
//
//      Returns information about the current display environment for
//      Installer.  This can be used to open different medias (pictures or
//      animations) for different number of colors or screen sizes.
//
// Refer to Installer.guide 1.20 (25.10.1999) 1995-99 by Amiga Inc.
//------------------------------------------------------------------------------
entry_p n_querydisplay(entry_p contxt)
{
    // We need 2 arguments.
    C_SANE(2, NULL);

    char *obj = str(C_ARG(1)), *option = str(C_ARG(2));
    int32_t width = 0, height = 0, depth = 0, colors = 0, upper = 0, lower = 0,
            left = 0, right = 0;

    // Object 'screen'
    if(strcasecmp(obj, "screen") == 0)
    {
        gui_query_screen(&width, &height, &depth, &colors);
    }
    // Object 'window'
    else if(strcasecmp(obj, "window") == 0)
    {
        gui_query_window(&width, &height, &upper, &lower, &left, &right);
    }

    // Return translated option.
    R_NUM(strcasecmp(option, "width") == 0 ? width :
          strcasecmp(option, "height") == 0 ? height :
          strcasecmp(option, "depth") == 0 ? depth :
          strcasecmp(option, "colors") == 0 ? colors :
          strcasecmp(option, "upper") == 0 ? upper :
          strcasecmp(option, "lower") == 0 ? lower :
          strcasecmp(option, "left") == 0 ? left :
          strcasecmp(option, "right") == 0 ? right : 0);
}
