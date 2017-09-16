#ifndef ERROR_H_
#define ERROR_H_

typedef enum
{
    ERR_PANIC = 0,
    ERR_MISS,
    ERR_HALT, 
    ERR_RESET,
    ERR_READ_FILE, 
    ERR_READ_DIR, 
    ERR_WRITE_FILE, 
    ERR_WRITE_DIR, 
    ERR_RENAME_FILE, 
    ERR_DELETE_FILE, 
    ERR_NOT_A_FILE, 
    ERR_NOT_A_DIR, 
    ERR_NO_SUCH_FILE_OR_DIR, 
    ERR_DIV_BY_ZERO, 
    ERR_UNDEF_FNC, 
    ERR_UNDEF_VAR, 
    ERR_MAX_DEPTH, 
    ERR_FMT_INVALID, 
    ERR_FMT_MISMATCH, 
    ERR_FMT_MISSING, 
    ERR_FMT_UNUSED, 
    ERR_NO_ITEM, 
    ERR_MISSING_OPTION, 
    ERR_INVALID_APP 
} error_t; 

//#define PANIC __LINE__, "Internal error", __func__
//#define MISS 1, "Implementation missing", __func__
#define HALT -1, "Halt", __func__
#define RESET -2, "Reset", __func__
#define PANIC __LINE__, ERR_PANIC, __func__
#define MISS 1, ERR_MISS, __func__
//#define HALT -1, ERR_HALT, __func__
//#define RESET -2, ERR_RESET, __func__


int did_error(void);
int did_halt(void);
int error(int id, 
          const char *type, 
          const char *info);

int error_ng(int id, error_t type, const char *info);

#endif
