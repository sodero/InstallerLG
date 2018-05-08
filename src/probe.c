//----------------------------------------------------------------------------
// probe.c: 
//
// Environment information retrieval
//
//----------------------------------------------------------------------------

#include "alloc.h"
#include "error.h"
#include "eval.h"
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
#include <workbench/workbench.h>
#endif

//----------------------------------------------------------------------------
// (database <feature> [<checkvalue>])
//    return information about the Amiga that the Installer 
//    is running on.  
//
// Refer to Installer.guide 1.19 (29.4.96) 1995-96 by ESCOM AG
//----------------------------------------------------------------------------
entry_p m_database(entry_p contxt)
{
    // We need atleast one argument
    if(c_sane(contxt, 1))
    {   
        int memf = -1; 
        static char buf[NUMLEN]; 
        const char *feat = str(CARG(1)),
            *cpu =  
        #ifdef __i386__
            "x86",
        #elif __amd64__
            "x86_64",
        #elif __arm__
            "ARM",
        #elif __ppc__
            "PowerPC",
        #elif __mc68000__
            "68000",
        #elif __mc68010__
            "68010",
        #elif __mc68020__
            "68020",
        #elif __mc68030__
            "68030",
        #elif __mc68040__
            "68040",
        #elif __mc68060__
            "68060",
        #else
            "Unknown",
        #endif
            *ret = "Unknown";

        if(!strcmp(feat, "cpu"))
        {   
            ret = cpu; 
        }
        else
        if(!strcmp(feat, "graphics-mem"))
        {   
            memf =
            #ifdef AMIGA
            AvailMem(MEMF_CHIP);
            #else
            524288;
            #endif
        }
        else
        if(!strcmp(feat, "total-mem"))
        {   
            memf =
            #ifdef AMIGA
            AvailMem(MEMF_ANY);
            #else
            524288;
            #endif
        }

        if(memf != -1)
        {   
            ret = buf; 
            snprintf(buf, sizeof(buf), "%d", memf); 
        }

        // Are we testing for a specific value?
        if(CARG(2) && CARG(2) != end())
        {
            ret = strcmp(ret, str(CARG(2))) ? "0" : "1";
        }

        RSTR(strdup(ret));  
    }
    else
    {
        // The parser is broken.
        error(PANIC); 
        RCUR;
    }
}

//----------------------------------------------------------------------------
// (earlier <file1> <file2>)
//     true if file1 earlier than file2
//
// Refer to Installer.guide 1.19 (29.4.96) 1995-96 by ESCOM AG
//----------------------------------------------------------------------------
entry_p m_earlier(entry_p contxt)
{
    // We need two filenames.
    if(c_sane(contxt, 2))
    {
        // One struct per file.
        struct stat f1, f2; 

        // Get information about the first file.
        if(stat(str(CARG(1)), &f1))
        {
            // Could not read from file / dir. 
            error(contxt->id, ERR_READ, str(CARG(1))); 
            RNUM(0); 
        }

        // Get information about the second file.
        if(stat(str(CARG(2)), &f2))
        {
            // Could not read from file / dir. 
            error(contxt->id, ERR_READ, str(CARG(2))); 
            RNUM(0); 
        }

        // Is the first older than the second one?
        RNUM
        (
            f1.st_mtime < f2.st_mtime ? 1 : 0
        );
    }
    else
    {
        // The parser is broken
        error(PANIC); 
        RCUR;
    }
}

//----------------------------------------------------------------------------
// (getassign <name> <opts>)
//     return value of logical name (no `:') `<opts>': 'v'-volumes,
//     'a'-assigns, 'd'-devices
//
// Refer to Installer.guide 1.19 (29.4.96) 1995-96 by ESCOM AG
//----------------------------------------------------------------------------
entry_p m_getassign(entry_p contxt)
{
    // We need one or more arguments.
    if(c_sane(contxt, 1))
    {
        // On non Amiga systems this is a stub.
        #ifdef AMIGA
	    struct DosList *dl;
        const char *asn = str(CARG(1)); 
        size_t asnl = strlen(asn); 

        if(!asnl)
        {
            // Invalid name of assign, and
            // the empty string is how the 
            // CBM installer fails.
            REST; 
        }

        // The second argument is optional. 
        entry_p opt = CARG(2); 

        // The bitmask must contain atleast
        // this LDF_READ. 
        ULONG msk = LDF_READ; 

        // Parse the option string if it exists. 
        if(opt && opt != end())
        {
            const char *o = str(opt); 
            
            if(strlen(o))
            {
                // Translate from Installer speak to DOS
                // speak. 
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
                // The CBM installer returns an empty
                // string if option string is empty. 
                REST; 
            }
        }
        else
        // The default behaviour, when no option string is
        // present, is to look for logical assignments. 
        {
            msk |= LDF_ASSIGNS;
        }
       
        // Prepare to walk the device list. 
	    dl = (struct DosList *) LockDosList(msk);

        if(dl)
        {
            ULONG bits[] = 
            {
                LDF_ASSIGNS, 
                LDF_VOLUMES, 
                LDF_DEVICES,
                0
            };

            // Iterate over all flags. 
            for(size_t i = 0; 
                bits[i]; i++)
            {
                // For all flags matching the option
                // string (or its absence), traverse
                // the doslist. 
                if(msk & bits[i])
                {
                    struct DosList *dc = (struct DosList *) 
                        NextDosEntry(dl, bits[i]); 

                    while(dc)
                    {
                        const char *n = B_TO_CSTR(dc->dol_Name);

                        // Ignore case when looking for match.
                        if(!strcasecmp(asn, n))
                        {
                            // Unlock doslist and allocate enough 
                            // memory to hold any path. 
                            char *r = calloc(PATH_MAX, 1); 
	                        UnLockDosList(msk);

                            if(r)
                            {
                                // The form common to all types. Do we
                                // need to do anything with LDF_VOLUMES?
                                snprintf(r, PATH_MAX, "%s:", n); 

                                // Logical assignments. Get the full path
                                // from the lock. 
                                if(bits[i] == LDF_ASSIGNS)
                                {
                                    BPTR l = (BPTR) Lock(r, ACCESS_READ);

                                    if(l)
                                    {
                                        NameFromLock(l, r, PATH_MAX); 
                                        UnLock(l); 
                                    }
                                }
                                // Devices. No other options than 'd' are 
                                // allowed in the options string for some
                                // reason (in the CBM installer). 
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
                                RSTR(r); 
                            }
                            else
                            {
                                // Out of memory
                                error(PANIC);
                                REST;
                            }
                        }
                        else
                        {
                            // No match. Next list item.
                            dc = (struct DosList *) 
                                NextDosEntry(dc, bits[i]);
                        }
                    }
                }
            }

            // Not found. 
	        UnLockDosList(msk);
        }
        else
        {
            // Could not lock doslist. I'm not
            // sure this can happen. I believe
            // LockDosList will block until the
            // end of time if a problem occurs.
            error(contxt->id, ERR_READ, asn); 
        }
        #endif
    }

    // Return empty string
    // on failure. 
    REST;
}

//----------------------------------------------------------------------------
// (getdevice <path>)
//     returns name of device upon which <path> resides
//
// Refer to Installer.guide 1.19 (29.4.96) 1995-96 by ESCOM AG
//----------------------------------------------------------------------------
entry_p m_getdevice(entry_p contxt)
{
    // We need a path. 
    if(c_sane(contxt, 1))
    {
        #ifdef AMIGA
        // Attempt to lock path. 
        BPTR lock = (BPTR) Lock(str(CARG(1)), ACCESS_READ);

        if(lock)
        {
            struct InfoData id; 

            // Get vol info from file / dir lock.
            if(Info(lock, &id))
            {
                struct DosList *dl = (struct DosList *) id.id_VolumeNode;
                UnLock(lock);

                if(dl)
                {
                    struct MsgPort *mp = dl->dol_Task; 
                    ULONG msk = LDF_READ | LDF_DEVICES;

                    // Search for <path> handler in the
                    // list of devices. 
                    dl = (struct DosList *) LockDosList(msk);

                    while(dl && mp != dl->dol_Task)
                    {
                        dl = (struct DosList *)
                            NextDosEntry(dl, LDF_DEVICES); 
                    }

                    UnLockDosList(msk);

                    // If we found it, we also found the
                    // name of the device. 
                    if(dl)
                    {
                        const char *n = B_TO_CSTR(dl->dol_Name);
                        RSTR(strdup(n)); 
                    }
                }
            }
            else
            {
                UnLock(lock);
            }
        }

        // Could not get information about <path>.
        error(contxt->id, ERR_READ, str(CARG(1))); 
        #endif
    }
    else
    {
        // The parser is broken.
        error(PANIC);
    }

    // Return empty string.
    REST;
}

//----------------------------------------------------------------------------
// (getdiskspace <path>)
//     return available space (in bytes)
//
// Refer to Installer.guide 1.19 (29.4.96) 1995-96 by ESCOM AG
//
// Currently all values above 2G will be cap:ed. Shall we bother 
// with 64-bit values or shall we report free space in kB:s? Or
// should we not care at all? This will work until some program
// requires more than 2G diskspace.
//----------------------------------------------------------------------------
entry_p m_getdiskspace(entry_p contxt)
{
    // We need a path. 
    if(c_sane(contxt, 1))
    {
        #ifdef AMIGA
        // Attempt to lock path. 
        const char *n = str(CARG(1));
        BPTR lock = (BPTR) Lock(n, ACCESS_READ);

        // Do we have a lock?
        if(lock)
        {
            struct InfoData id; 

            // Retrieve information from lock.
            if(Info(lock, &id))
            {
                long long bfree = (long long) 
                    (id.id_NumBlocks -
                     id.id_NumBlocksUsed) * 
                     id.id_BytesPerBlock;

                // Release lock before return.
                UnLock(lock); 

                // Return free space in bytes. Cap
                // the value at 2G.
                RNUM
                (
                    bfree > INT_MAX ? 
                    INT_MAX : (int) bfree
                );
            }

            // Info() failed. Release lock.
            UnLock(lock); 
        }

        // For some reason, we could not
        // acquire a lock on <path>, or,
        // we could get a lock, but failed
        // when trying to retrieve info 
        // from the lock.
        error(contxt->id, ERR_READ, n); 
        #endif
    }
    else
    {
        // The parser is broken.
        error(PANIC);
    }

    // Failure, catastrophic
    // or just very very bad. 
    RNUM(-1); 
}

//----------------------------------------------------------------------------
// (getenv <name>)
//     return value of environment variable
//
// Refer to Installer.guide 1.19 (29.4.96) 1995-96 by ESCOM AG
//----------------------------------------------------------------------------
entry_p m_getenv(entry_p contxt)
{
    // We need a variable name. 
    if(c_sane(contxt, 1))
    {
        // Is there such an environment
        // variable? 
        char *e = getenv(str(CARG(1))); 

        if(e)
        {
            // Return what we found. 
            RSTR(strdup(e)); 
        }
    }
    else
    {
        // The parser is broken.
        error(PANIC);
    }

    // Return empty string.
    REST; 
}

//----------------------------------------------------------------------------
// (getsize <file>)
//     return size
//
// Refer to Installer.guide 1.19 (29.4.96) 1995-96 by ESCOM AG
//----------------------------------------------------------------------------
entry_p m_getsize(entry_p contxt)
{
    // We need a file name. 
    if(c_sane(contxt, 1))
    {
        // Open the file in read only mode.
        FILE *f = fopen(str(CARG(1)), "r"); 
        if(f)
        {
            // Seek to the end of the file.
            fseek(f, 0L, SEEK_END);

            // Let the result be the position.
            DNUM = (int) ftell(f); 

            // We're done.
            fclose(f); 
        }
        else
        {
            // We could not open the file. 
            error(contxt->id, ERR_READ_FILE, str(CARG(1))); 
            RNUM(0); 
        }
    }
    else
    {
        // The parser is broken
        error(PANIC);
    }
    
    // Return whatever we have
    // at this point. 
    RCUR; 
}

//----------------------------------------------------------------------------
// (getsum <file>)
//     return checksum of file for comparison purposes
//
// Refer to Installer.guide 1.19 (29.4.96) 1995-96 by ESCOM AG
//----------------------------------------------------------------------------
entry_p m_getsum(entry_p contxt)
{
    // We need a filename.
    if(c_sane(contxt, 1))
    {
        const char *fn = str(CARG(1));
        FILE *f = fopen(fn, "r"); 

        if(f)
        {
            int c = getc(f), 
                n = 1; 

            DNUM = 0; 

            // Generate silly checksum. Replace
            // this with something else.
            while(c != EOF)
            {
                DNUM -= (c + n);
                c = getc(f); 
                n = ~DNUM; 
            }

            fclose(f); 
            RCUR; 
        }
        else
        {
            error(contxt->id, ERR_READ_FILE, fn); 
            RNUM(0);
        }
    }
    else
    {
        // The parser is broken
        error(PANIC);
        RCUR; 
    }
}

//----------------------------------------------------------------------------
// getversion helper
//----------------------------------------------------------------------------
int h_getversion(entry_p contxt, const char *file)
{
    // Try to open whatever we have
    // in read only mode. 
    FILE *fp = fopen(file, "r"); 
    int ver = -1; 

    // Could we open the file? 
    if(fp)
    {
        int i = 0, c = 0; 

        // Version key. 
        int vk[] = {'$','V','E','R',':',0};

        // Read one byte at a time to find the
        // location of the version key if any.
        while(c != EOF && vk[i])
        {
            c = fgetc(fp); 
            i = c == vk[i] ? i + 1 : 0; 
        }

        // If we found the key, we have reached
        // the terminating 0, ergo found a match.
        if(!vk[i])
        {
            static char buf[BUFSIZ]; 

            // Fill up buffer with enough data to 
            // hold any realistic version string.
            fread(buf, 1, sizeof(buf), fp); 

            // Do we have data in the buffer? 
            if(!ferror(fp))
            {
                int v, r; 

                // Version string pattern. 
                const char *p = "%*[^0123456789]%d.%d%*[^\0]";

                // Try to find version string.
                if(sscanf(buf, p, &v, &r) == 2)
                {
                    // We found something.
                    ver = (v << 16) | r;
                }
            }
        }

        // Did we have any reading problems? 
        if(ferror(fp))
        {
            // Could not read from file. This 
            // will pick up problems from both
            // fgetc() and fread() above. 
            error(contxt->id, ERR_READ_FILE, file); 
        }

        // We don't need the file anymore. 
        fclose(fp); 
    }
    else
    {
        // Could not read from file. 
        error(contxt->id, ERR_READ_FILE, file); 
    }

    // Version or -1. 
    return ver;
}

//----------------------------------------------------------------------------
// (getversion <file> (resident))
//     return version/revision of file, library, etc. as 32 bit num
//
// Refer to Installer.guide 1.19 (29.4.96) 1995-96 by ESCOM AG
//----------------------------------------------------------------------------
entry_p m_getversion(entry_p contxt)
{
    // Unknown version.
    DNUM = 0; 

    // All we need is a context. 
    if(contxt)
    {
        // Any arguments given? 
        if(contxt->children &&
           c_sane(contxt, 1))
        {
            // Name of whatever we're trying to 
            // get the version information from. 
            const char *w = str(CARG(1));

            // A resident library or device? 
            if(get_opt(contxt, OPT_RESIDENT))
            {
                #ifdef AMIGA
                struct Resident *res = 
                    (struct Resident *) FindResident(w); 

                if(res)
                {
                    int v, r; 
                    const char *id = res->rt_IdString;

                    // Version string pattern. 
                    const char *p = "%*[^0123456789]%d.%d%*[^\0]";

                    // Try to find the revision, if any, in
                    // the id string. The major part of our 
                    // parsed result should match rt_Version. 
                    if(sscanf(id, p, &v, &r) == 2 &&
                       v == res->rt_Version)
                    {
                        // We found something.
                        DNUM = (v << 16) | r;
                    }
                    else
                    {
                        // We can't trust the parsed result.
                        // Use what we know, ignore revision.
                        DNUM = res->rt_Version << 16;
                    }
                }
                #else
                DNUM = 0; 
                #endif
            }
            // A file of some sort, on disk, not resident.
            else
            {
                int ver = h_getversion(contxt, w);
                DNUM = ver != -1 ? ver : 0; 
            }
        }
        else
        {
            // No arguments, return version of Exec. 
            #ifdef AMIGA
            extern struct ExecBase *SysBase;

            DNUM = (SysBase->LibNode.lib_Version << 16) |
                    SysBase->SoftVer;
            #endif
        }
    }
    else
    {
        // The parser is broken
        error(PANIC);
    }

    // Return whatever we have, could
    // be a failure (0) or version and 
    // revision information.
    RCUR; 
}

//----------------------------------------------------------------------------
// (iconinfo <parameters>)
//     return information about an icon (V42.12)
//
// Refer to Installer.guide 1.19 (29.4.96) 1995-96 by ESCOM AG
//
// Despite what the Installer.guide says, 'help', 'prompt', 'confirm' 
// and 'safe' are dead options in OS 3.9. We choose to ignore the guide
// and mimic the behaviour of the implementation in 3.9. Also, the 3.9
// implementation deletes tooltypes when (gettooltype) is used. This is
// assumed to be a bug and therefore not mimiced. 
//----------------------------------------------------------------------------
entry_p m_iconinfo(entry_p contxt)
{
    // We need one or more arguments.
    if(c_sane(contxt, 1))
    {
        entry_p dst   =   get_opt(contxt, OPT_DEST);
        entry_p tt[]  = { get_opt(contxt, OPT_GETTOOLTYPE),
                          get_opt(contxt, OPT_GETDEFAULTTOOL),
                          get_opt(contxt, OPT_GETSTACK),
                          get_opt(contxt, OPT_GETPOSITION), end() };

        // We need something to work with. 
        if(dst) 
        {
            // Something is 'dst'.info 
            const char *file = str(dst);

            #ifdef AMIGA
            // Get icon information. 
            struct DiskObject *obj = (struct DiskObject *) 
                GetDiskObject(file);
            #else
            const char *obj = file; 
            #endif

            if(obj)
            {
                // Iterate over all options or until
                // we run into resource problems. 
                for(size_t i = 0; 
                    tt[i] != end() &&
                    !did_error(); i++)
                {
                    // If we have an option of any kind. 
                    if(tt[i])
                    {
                        // Iterate over all its children. 
                        for(size_t j = 0; 
                            tt[i]->children[j] &&
                            tt[i]->children[j] != end(); j++)
                        {
                            // Get variable name and option type. 
                            int t = tt[i]->id; 
                            const char *n = str(tt[i]->children[j]);

                            // Variable names must be atleast one
                            // character long.
                            if(strlen(n))
                            {
                                static char tmp[NUMLEN]; 
                                char *svl = NULL;
                                entry_p val;

                                #ifdef AMIGA
                                // Is this a numerical value?
                                if(t == OPT_GETSTACK ||
                                   t == OPT_GETPOSITION)
                                {
                                    int v = 
                                    (
                                        t == OPT_GETSTACK ? 
                                        obj->do_StackSize : 
                                        j == 0 ? 
                                        obj->do_CurrentX :
                                        obj->do_CurrentY
                                    );

                                    snprintf(tmp, sizeof(tmp), "%d", v); 
                                    svl = tmp; 
                                }
                                else
                                if(t == OPT_GETDEFAULTTOOL &&
                                   obj->do_DefaultTool)
                                {
                                    svl = obj->do_DefaultTool; 
                                }
                                else
                                if(t == OPT_GETTOOLTYPE &&
                                   obj->do_ToolTypes)
                                {
                                    svl = (char *) FindToolType(obj->do_ToolTypes, n);
                                    n = str(tt[i]->children[++j]);
                                }
                                #else
                                // Testing purposes only.
                                snprintf(tmp, sizeof(tmp), "%d:%zu", t, j); 
                                svl = tmp; 
                                #endif

                                // Always create a valid value (string). 
                                val = new_string(strdup(svl ? svl : "")); 

                                if(val)
                                {
                                    // If we already have a symbol of the same
                                    // same as in the option, replace the value
                                    // of the old one with the new value.
                                    if(contxt->symbols)
                                    {
                                        for(size_t k = 0; 
                                            contxt->symbols[k] &&
                                            contxt->symbols[k] != end(); 
                                            k++)
                                        {
                                            if(!strcmp(contxt->symbols[k]->name, n))
                                            {
                                                kill(contxt->symbols[k]->resolved); 
                                                contxt->symbols[k]->resolved = val;
                                                push(global(contxt), contxt->symbols[k]); 
                                                val->parent = contxt->symbols[k]; 

                                                // We no longer own 'val'.
                                                val = NULL; 
                                                break;
                                            }
                                        }
                                    }

                                    // No, this is a new symbol. Create, append 
                                    // to this function and push to the global 
                                    // context. 
                                    if(val)
                                    {
                                        entry_p sym = new_symbol(strdup(n)); 

                                        if(sym)
                                        {
                                            // Adopt the value found above.
                                            val->parent = sym; 
                                            sym->resolved = val; 

                                            if(append(&contxt->symbols, sym))
                                            {
                                                push(global(contxt), sym); 
                                                sym->parent = contxt;  
                                            }
                                        }
                                        else
                                        {
                                            // Out of memory. Do not
                                            // leak 'val'.
                                            kill(val); 
                                        }
                                    }
                                }
                            }
                        }
                    }
                }

                #ifdef AMIGA
                FreeDiskObject(obj);
                #endif
            }
            else
            {
                // More information? IoErr() is nice.  
                error(contxt->id, ERR_READ_FILE, file); 
                RNUM(0); 
            }

            // Success. 
            RNUM(1); 
        }
        else
        {
            error(contxt->id, ERR_MISSING_OPTION, "dest"); 
            RNUM(0); 
        }
    }
    else
    {
        // The parser is broken
        error(PANIC);
        RCUR; 
    }
}
